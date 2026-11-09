#ifndef S21_OTHERS_H
#define S21_OTHERS_H

#include "../arithmetic/s21_arithmetic.h"
#include "../comparison/s21_comparison.h"
#include "../convertors/s21_convertors.h"
#include "../s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal* result);
int s21_truncate(s21_decimal value, s21_decimal* result);
int s21_floor(s21_decimal value, s21_decimal* result);
int s21_round(s21_decimal value, s21_decimal* result);

#endif