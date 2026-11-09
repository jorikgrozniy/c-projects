#include "s21_others.h"

int s21_negate(s21_decimal value, s21_decimal* result) {
  int res = result == NULL ? 1 : 0;
  if (!res) {
    *result = value;
    s21_set_sign(result, !s21_get_sign(*result));
  }
  return res;
}

int s21_truncate(s21_decimal value, s21_decimal* result) {
  int res = result == NULL ? 1 : 0;
  if (!res) {
    *result = value;
    for (int i = 0; i < s21_get_scale(value); i++) {
      div_by_10(result);
    }
    s21_set_scale(result, 0);
  }
  return res;
}

int s21_floor(s21_decimal value, s21_decimal* result) {
  int res = (result == NULL) ? 1 : 0;
  if (!res) {
    set_zero(result);
    int scale = s21_get_scale(value);
    if (scale > 0) {
      s21_decimal truncated = {0};
      s21_truncate(value, &truncated);
      if (s21_get_sign(value) && !s21_is_equal(value, truncated)) {
        s21_decimal one = {{1, 0, 0, 0}};
        s21_sub(truncated, one, result);
      } else
        *result = truncated;
    } else {
      memcpy(result, &value, sizeof(s21_decimal));
    }
  }
  return res;
}

int s21_round(s21_decimal value, s21_decimal* result) {
  int res = result == NULL ? 1 : 0;
  if (!res) {
    set_zero(result);
    int scale = s21_get_scale(value);
    if (scale > 0) {
      int sign = s21_get_sign(value);
      s21_set_sign(&value, 0);
      s21_decimal tmp, fractional, truncated = {0};
      s21_truncate(value, &truncated);
      tmp = truncated;
      for (int i = 0; i < scale; i++) {
        mul_by_10(&truncated);
      }
      s21_set_scale(&truncated, scale);

      uint64_t overflow = 0;
      for (int i = 0; i < 3; i++) {
        uint64_t temp = (uint64_t)(value.bits[i] & 0xFFFFFFFF) -
                        (uint64_t)(truncated.bits[i] & 0xFFFFFFFF) - overflow;
        fractional.bits[i] = (int)(temp & 0xFFFFFFFF);
        overflow = temp >> 32;
      }
      for (int i = 0; i < scale - 1; i++) {
        div_by_10(&fractional);
      }
      int last_num = fractional.bits[0];

      if (last_num >= 5) {
        overflow = 0;
        s21_decimal one = {{1, 0, 0, 0}};
        for (int i = 0; i < 3; i++) {
          uint64_t temp = (uint64_t)(tmp.bits[i] & 0xFFFFFFFF) +
                          (uint64_t)(one.bits[i] & 0xFFFFFFFF) + overflow;
          tmp.bits[i] = (int)(temp & 0xFFFFFFFF);
          overflow = temp >> 32;
        }
      }
      *result = tmp;
      s21_set_sign(result, sign);
    } else {
      memcpy(result, &value, sizeof(s21_decimal));
    }
  }
  return res;
}
