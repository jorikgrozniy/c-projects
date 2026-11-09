#include "s21_comparison.h"

int s21_is_equal(s21_decimal a, s21_decimal b) {
  int res = 0;
  int a_sign = s21_get_sign(a), b_sign = s21_get_sign(b);

  if (a_sign == b_sign) {
    align_scales(&a, &b);
    if (compare_mantissa(a, b) == 0) res = 1;
  } else if (is_decimal_zero(a) && is_decimal_zero(b)) {
    res = 1;
  }
  return res;
}

int s21_is_greater(s21_decimal a, s21_decimal b) {
  int res = 0;
  int a_sign = s21_get_sign(a), b_sign = s21_get_sign(b);

  if (a_sign == 0 && b_sign == 1) {
    res = 1;
  } else if (a_sign == 1 && b_sign == 0) {
    res = 0;
  } else {
    int final_sign = a_sign;
    align_scales(&a, &b);
    int compr = compare_mantissa(a, b);

    if (compr == 1) {
      res = (final_sign) ? 0 : 1;
    } else if (compr == -1) {
      res = (final_sign) ? 1 : 0;
    } else {
      res = 0;
    }
  }

  return res;
}

int s21_is_less(s21_decimal a, s21_decimal b) {
  int res = 0;
  int a_sign = s21_get_sign(a), b_sign = s21_get_sign(b);

  if (a_sign == 1 && b_sign == 0) {
    res = 1;
  } else if (a_sign == b_sign) {
    if (align_scales(&a, &b)) {
      int scale_a = s21_get_scale(a), scale_b = s21_get_scale(b);
      if (a_sign) {
        res = (scale_a > scale_b) ? 0 : 1;
      } else {
        res = (scale_a > scale_b) ? 1 : 0;
      }
    } else {
      int cmpr = compare_mantissa(a, b);

      if (a_sign) {
        res = (cmpr == 1) ? 1 : 0;
      } else {
        res = (cmpr == -1) ? 1 : 0;
      }
    }
  }
  return res;
}

int s21_is_not_equal(s21_decimal a, s21_decimal b) {
  return !s21_is_equal(a, b);
}

int s21_is_less_or_equal(s21_decimal a, s21_decimal b) {
  return s21_is_less(a, b) || s21_is_equal(a, b);
}

int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2) {
  return s21_is_greater(value_1, value_2) || s21_is_equal(value_1, value_2);
}