#include "s21_arithmetic.h"

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  int res = 0;

  if (is_decimal_zero(value_2)) {
    res = 3;
  } else if (result != NULL) {
    set_zero(result);
    int final_sign = s21_get_sign(value_1) ^ s21_get_sign(value_2);
    big_decimal big_1, big_2;
    decimal_to_big(value_1, &big_1);
    decimal_to_big(value_2, &big_2);

    normalize_scales_big(value_1, value_2, &big_1, &big_2);
    int scale = 0;

    big_decimal quotient = {0}, remainder = {0}, total_quotient = {0};
    divide_big_decimal(big_1, big_2, &quotient, &remainder);
    total_quotient = quotient;
    while (!is_big_dec_zero(remainder) && scale < MAX_SCALE) {
      mul_by_10_big(&remainder);
      big_decimal new_remainder = {0};
      divide_big_decimal(remainder, big_2, &quotient, &new_remainder);

      mul_by_10_big(&total_quotient);
      add_big(&total_quotient, &quotient);

      remainder = new_remainder;
      scale++;
    }

    if (!is_big_dec_zero(remainder)) {
      round_big(remainder, big_2, &total_quotient);
    }
    if (big_convertion(total_quotient, result, &scale) != 0) {
      res = (final_sign || scale >= 28) ? 2 : 1;
    } else {
      s21_set_scale(result, scale);
      s21_set_sign(result, final_sign);

      if (is_decimal_zero(*result)) {
        res = (final_sign || scale >= 28) ? 2 : 1;
      }
    }
    if (res == 0) {
      s21_set_scale(result, scale);
      s21_set_sign(result, final_sign);
    }
  }

  return res;
}

void normalize_scales_big(s21_decimal value_1, s21_decimal value_2,
                          big_decimal* big_1, big_decimal* big_2) {
  int scale_1 = s21_get_scale(value_1);
  int scale_2 = s21_get_scale(value_2);

  while (scale_1 < scale_2) {
    mul_by_10_big(big_1);
    scale_1++;
  }
  while (scale_2 < scale_1) {
    mul_by_10_big(big_2);
    scale_2++;
  }
}

void round_big(big_decimal remainder, big_decimal big_2,
               big_decimal* total_quotient) {
  big_decimal double_remainder = remainder;
  uint64_t carry = 0;
  for (int i = 0; i < 6; i++) {
    uint64_t temp = (uint64_t)double_remainder.data[i] * 2 + carry;
    double_remainder.data[i] = (uint32_t)(temp & 0xFFFFFFFF);
    carry = temp >> 32;
  }

  int cmp = compare_mantissa_big(double_remainder, big_2);

  if (cmp > 0) {
    big_decimal one = {{1, 0, 0, 0, 0, 0, 0}};
    add_big(total_quotient, &one);
  } else if (cmp == 0) {
    if (total_quotient->data[0] & 1) {
      big_decimal one = {{1, 0, 0, 0, 0, 0, 0}};
      add_big(total_quotient, &one);
    }
  }
}

void divide_big_decimal(big_decimal dividend, big_decimal divisor,
                        big_decimal* quotient, big_decimal* remainder) {
  set_zero_big_dec(quotient);
  set_zero_big_dec(remainder);

  const int total_bits = 192;
  for (int i = total_bits - 1; i >= 0; i--) {
    shift_left_one_big(remainder);

    int word = i / 32;
    int bits = i % 32;

    if (dividend.data[word] & (1U << bits)) {
      remainder->data[0] |= 1;
    }

    if (compare_mantissa_big(*remainder, divisor) >= 0) {
      subtract_big(remainder, &divisor);
      quotient->data[word] |= (1U << bits);
    }
  }
}

void add_big(big_decimal* a, const big_decimal* b) {
  uint64_t carry = 0;
  for (int i = 0; i < 6; i++) {
    uint64_t sum = (uint64_t)a->data[i] + (uint64_t)b->data[i] + carry;
    a->data[i] = (uint32_t)(sum & 0xFFFFFFFF);
    carry = sum >> 32;
  }
}

void subtract_big(big_decimal* a, const big_decimal* b) {
  uint64_t borrow = 0;
  for (int i = 0; i < 6; i++) {
    uint64_t minuend = a->data[i];
    uint64_t subtrahend = (uint64_t)b->data[i] + borrow;
    borrow = (minuend < subtrahend) ? 1 : 0;
    if (borrow) {
      int64_t diff = (int64_t)minuend - (int64_t)subtrahend;
      a->data[i] = (uint32_t)diff;
    } else {
      a->data[i] = (uint32_t)(minuend - subtrahend);
    }
  }
}

void shift_left_one_big(big_decimal* num) {
  uint64_t carry = 0;
  for (int i = 0; i < 6; i++) {
    uint64_t value = ((uint64_t)num->data[i] << 1) | carry;
    num->data[i] = (uint32_t)(value & 0xFFFFFFFF);
    carry = value >> 32;
  }
}

int is_big_dec_zero(big_decimal value) {
  int res = 1;

  for (int i = 0; i < 6 && res; i++) {
    if (value.data[i] != 0) res = 0;
  }

  return res;
}

int big_convertion(big_decimal big, s21_decimal* dec, int* scale) {
  int code = 0;
  while ((big.data[3] != 0 || big.data[4] != 0 || big.data[5] != 0) &&
         code != 1) {
    if (*scale == 0) {
      code = 1;
    } else {
      uint64_t carry = 0;
      for (int i = 5; i >= 0; i--) {
        uint64_t current = carry << 32 | big.data[i];
        big.data[i] = (uint32_t)(current / 10);
        carry = current % 10;
      }
      (*scale)--;
    }
  }

  if (code != 1) {
    dec->bits[0] = (uint32_t)big.data[0];
    dec->bits[1] = (uint32_t)big.data[1];
    dec->bits[2] = (uint32_t)big.data[2];
  }

  return code;
}

void set_zero_big_dec(big_decimal* value) {
  memset(value, 0, sizeof(big_decimal));
}
