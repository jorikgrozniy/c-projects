#include "../s21_decimal.h"
#include "s21_arithmetic.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  int res = 0;
  set_zero(result);

  int a_sign = s21_get_sign(value_1), b_sign = s21_get_sign(value_2);
  int sign = a_sign == b_sign ? 1 : -1;
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);

  big_decimal a_big, b_big;
  big_decimal res_big = {{0}};

  if ((s21_is_less(value_1, value_2) && !a_sign && b_sign) ||
      (s21_is_greater(value_1, value_2) && a_sign && !b_sign) ||
      (a_sign && b_sign)) {
    s21_set_sign(result, 1);
    set_sign_big(&res_big, 1);
  }

  decimal_to_big(value_1, &a_big);
  decimal_to_big(value_2, &b_big);
  align_scales_big(&a_big, &b_big);
  big_decimal *first = &a_big, *second = &b_big;
  if (s21_is_less(value_1, value_2)) {
    first = &b_big;
    second = &a_big;
  }

  if (sign == 1) {
    int64_t overflow = 0;
    for (int i = 0; i < 6; i++) {
      int64_t temp = (int64_t)(first->data[i] & 0xFFFFFFFF) +
                     (int64_t)(second->data[i] & 0xFFFFFFFF) + overflow;
      res_big.data[i] = temp & 0xFFFFFFFF;
      overflow = (uint64_t)temp >> 32;
    }
  } else {
    uint64_t borrow = 0;
    for (int i = 0; i < 6; i++) {
      uint64_t a = first->data[i];
      uint64_t b = (uint64_t)second->data[i] + borrow;

      if (a < b) {
        res_big.data[i] = (uint32_t)((((uint64_t)1 << 32) + a) - b);
        borrow = 1;
      } else {
        res_big.data[i] = (uint32_t)(a - b);
        borrow = 0;
      }
    }
  }

  set_scale_big(&res_big, get_scale_big(a_big));
  if (is_overflow_big(res_big) == 0) {
    big_to_decimal(res_big, result);
  } else if (is_overflow_big(res_big) == 2) {
    if (bank_rounding_big(res_big, &res_big) == 1) {
      res = get_sign_big(res_big) ? 2 : 1;
    }
    big_to_decimal(res_big, result);
  } else
    res = is_overflow_big(res_big) == 1 ? 1 : 2;

  if (is_decimal_zero(*result)) {
    s21_set_sign(result, 0);
  }

  return res;
}

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  s21_set_sign(&value_2, !s21_get_sign(value_2));
  return s21_add(value_1, value_2, result);
}

int mul_by_10_big(big_decimal* value) {
  uint64_t carry = 0;
  for (int i = 0; i < 6; i++) {
    uint64_t temp = (uint64_t)value->data[i] * 10 + carry;
    value->data[i] = temp & 0xFFFFFFFF;
    carry = temp >> 32;
  }
  return carry ? 1 : 0;
}

uint32_t div_by_10_big(big_decimal* value) {
  uint32_t remainder = 0;
  for (int i = 5; i >= 0; i--) {
    uint64_t temp = ((uint64_t)remainder << 32) | value->data[i];
    value->data[i] = temp / 10;
    remainder = temp % 10;
  }
  return remainder;
}

int compare_mantissa_big(big_decimal a, big_decimal b) {
  int res = 0;
  for (int i = 5; i >= 0 && !res; i--) {
    if (a.data[i] > b.data[i]) {
      res = 1;
    } else if (a.data[i] < b.data[i]) {
      res = -1;
    }
  }
  return res;
}

void compress_scale_big(big_decimal* num) {
  int scale = get_scale_big(*num);

  while (scale > 0 &&
         (num->data[3] != 0 || num->data[4] != 0 || num->data[5] != 0)) {
    div_by_10_big(num);
    scale--;
    set_scale_big(num, scale);
  }
}

int is_overflow_big(big_decimal num) {
  int res = 0;
  if (num.data[3] != 0 || num.data[4] != 0 || num.data[5] != 0) {
    big_decimal max = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0, 0, 0, 0}};
    compress_scale_big(&num);
    if (compare_mantissa_big(num, max) == 1)
      res = get_sign_big(num) ? -1 : 1;
    else
      res = 2;
  }
  return res;
}

int bank_rounding_big(big_decimal value, big_decimal* result) {
  int code = 0;
  int scale = get_scale_big(value);
  uint32_t remainder = 0;
  if (scale > 0) {
    int sign = get_sign_big(value);
    big_decimal tmp = {0}, fractional = {0}, truncated = {0};

    while (is_overflow_big(value) != 0) {
      remainder = div_by_10_big(&value);
      scale--;
    }

    truncated = value;
    for (int i = 0; i < scale; i++) {
      div_by_10_big(&truncated);
    }
    set_scale_big(&truncated, 0);

    uint64_t overflow = 0;
    for (int i = 0; i < 6; i++) {
      uint64_t temp = (uint64_t)(value.data[i] & 0xFFFFFFFF) -
                      (uint64_t)(truncated.data[i] & 0xFFFFFFFF) - overflow;
      fractional.data[i] = temp & 0xFFFFFFFF;
      overflow = temp >> 32;
    }

    for (int i = 0; i < scale - 1; i++) {
      div_by_10_big(&fractional);
    }
    uint64_t last_num = fractional.data[0];
    while (last_num >= 10) {
      last_num /= 10;
    }
    if (scale == 0 && !last_num) last_num = remainder;

    tmp = truncated;
    if (last_num > 5 || (last_num == 5 && (tmp.data[0] & 1))) {
      overflow = 0;
      big_decimal one = {{1, 0, 0, 0, 0, 0, 0}};
      for (int i = 0; i < 6; i++) {
        uint64_t temp = (uint64_t)(tmp.data[i] & 0xFFFFFFFF) +
                        (uint64_t)(one.data[i] & 0xFFFFFFFF) + overflow;
        tmp.data[i] = (int)(temp & 0xFFFFFFFF);
        overflow = temp >> 32;
      }
      *result = tmp;
      scale--;
    } else {
      *result = value;
    }
    if (is_overflow_big(*result)) code = 1;

    set_sign_big(result, sign);
    set_scale_big(result, scale);
  } else {
    *result = value;
  }

  return code;
}

void decimal_to_big(s21_decimal dec, big_decimal* big) {
  if (big) {
    memset(big, 0, sizeof(big_decimal));
    big->data[0] = dec.bits[0];
    big->data[1] = dec.bits[1];
    big->data[2] = dec.bits[2];
    big->data[6] = dec.bits[3];
  }
}

void big_to_decimal(big_decimal big, s21_decimal* dec) {
  if (dec) {
    memset(dec, 0, sizeof(s21_decimal));
    dec->bits[0] = big.data[0];
    dec->bits[1] = big.data[1];
    dec->bits[2] = big.data[2];
    dec->bits[3] = big.data[6];
  }
}

void align_scales_big(big_decimal* a, big_decimal* b) {
  int scale_a = get_scale_big(*a), scale_b = get_scale_big(*b);
  if (scale_a == scale_b) return;

  big_decimal* min_scale_value = scale_a < scale_b ? a : b;
  int min_scale = scale_a < scale_b ? scale_a : scale_b;
  int max_scale = scale_a < scale_b ? scale_b : scale_a;
  for (int i = 0; i < max_scale - min_scale; i++) {
    mul_by_10_big(min_scale_value);
  }
  set_scale_big(min_scale_value, max_scale);
}

void set_scale_big(big_decimal* value, int scale) {
  if (scale >= 0 && scale <= 28)
    value->data[6] = (value->data[6] & 0xFF00FFFF) | ((scale & 0xFF) << 16);
}

void set_sign_big(big_decimal* value, int sign) {
  value->data[6] =
      sign ? (value->data[6] | (1u << 31)) : (value->data[6] & ~(1u << 31));
}

int get_sign_big(big_decimal value) {
  return (value.data[6] & 0x80000000) ? 1 : 0;
}

int get_scale_big(big_decimal value) {
  return (int)(value.data[6] >> 16) & 0xFF;
}
