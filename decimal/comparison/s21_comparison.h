#ifndef S21_COMPR_H
#define S21_COMPR_H

#include "../convertors/s21_convertors.h"
#include "../others/s21_others.h"
#include "../s21_decimal.h"

int s21_is_equal(s21_decimal a, s21_decimal b);
int s21_is_greater(s21_decimal a, s21_decimal b);
int s21_is_less(s21_decimal a, s21_decimal b);
int s21_is_not_equal(s21_decimal a, s21_decimal b);
int s21_is_less_or_equal(s21_decimal a, s21_decimal b);
int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2);

#endif