#include "s21_decimal.h"

void s21_set_sign(s21_decimal *value, int sign) {
  value->bits[3] =
      sign ? (value->bits[3] | (1u << 31)) : (value->bits[3] & ~(1u << 31));
}

int s21_get_sign(s21_decimal value) { return (value.bits[3] >> 31) & 1u; }

void s21_set_scale(s21_decimal *value, int scale) {
  value->bits[3] = (value->bits[3] & (int)0xFF00FFFF) | ((scale & 0xFF) << 16);
}

int s21_get_scale(s21_decimal value) { return (value.bits[3] >> 16) & 0xFF; }

int is_decimal_zero(s21_decimal value) {
  int res = 1;

  for (int i = 0; i < 3; i++) {
    if (value.bits[i] != 0) res = 0;
  }

  return res;
}

void set_zero(s21_decimal *value) { memset(value, 0, sizeof(s21_decimal)); }

int align_scales(s21_decimal *a, s21_decimal *b) {
  int code = 0;
  int scale_a = s21_get_scale(*a);
  int scale_b = s21_get_scale(*b);

  if (scale_a == scale_b) return 0;

  s21_decimal *min_scale_value = scale_a < scale_b ? a : b;
  int min_scale = scale_a < scale_b ? scale_a : scale_b;
  int max_scale = scale_a < scale_b ? scale_b : scale_a;
  int res_scale = min_scale;
  for (int i = 0; i < max_scale - min_scale && !code; i++) {
    if (min_scale_value->bits[0] == 0xFFFFFFFF &&
        min_scale_value->bits[1] == 0xFFFFFFFF &&
        min_scale_value->bits[2] == 0xFFFFFFFF) {
      code = 1;
    } else {
      mul_by_10(min_scale_value);
      res_scale++;
    }
  }

  s21_set_scale(min_scale_value, res_scale);

  return code;
}

uint32_t div_by_10(s21_decimal *a) {
  uint64_t remainder = 0;
  for (int i = 2; i >= 0; i--) {
    uint64_t value = (remainder << 32) | a->bits[i];
    a->bits[i] = (uint32_t)(value / 10);
    remainder = value % 10;
  }
  return (uint32_t)remainder;
}

void set_bit(uint32_t *dst, int pos, int value) {
  if (value) {
    *dst |= (1 << pos);
  } else {
    *dst &= ~(1 << pos);
  }
}

uint32_t mul_by_10(s21_decimal *value) {
  uint64_t carry = 0;
  for (int i = 0; i < 3; i++) {
    uint64_t temp = (uint64_t)value->bits[i] * 10 + carry;
    value->bits[i] = (uint32_t)(temp & 0xFFFFFFFF);
    carry = temp >> 32;
  }
  return carry;
}

int check_overflow(s21_decimal dec) {
  int res = 0;
  s21_decimal max_int = {.bits = {(uint32_t)MAX_INT, 0, 0, 0}};
  s21_decimal min_int = {.bits = {(uint32_t)MIN_INT, 0, 0, 1U << 31}};

  int sign = s21_get_sign(dec);

  if (!sign) {
    for (int i = 0; i < 3; i++) {
      if (dec.bits[i] > max_int.bits[i]) res = 1;
    }
  } else {
    for (int i = 0; i < 3; i++) {
      if ((uint32_t)dec.bits[i] > (uint32_t)min_int.bits[i]) res = 1;
    }
  }

  return res;
}

int compare_mantissa(s21_decimal a, s21_decimal b) {
  int res = 0;
  for (int i = 2; i >= 0 && res == 0; i--) {
    if (a.bits[i] > b.bits[i]) {
      res = 1;
    } else if (a.bits[i] < b.bits[i]) {
      res = -1;
    }
  }
  return res;
}