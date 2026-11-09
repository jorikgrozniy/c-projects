#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H

#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SCALE 28
#define MAX_INT 2147483647
#define MIN_INT (-2147483648)
#define MAX_VAL 7.9228162514264337593543950335e28

typedef struct s21_decimal {
  uint32_t bits[4];
} s21_decimal;

typedef struct {
  uint32_t data[7];
} s21_big_decimal;

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);
int s21_is_greater(s21_decimal a, s21_decimal b);
int s21_is_less(s21_decimal a, s21_decimal b);
int s21_is_equal(s21_decimal a, s21_decimal b);
int s21_is_not_equal(s21_decimal a, s21_decimal b);
int s21_is_greater_or_equal(s21_decimal a, s21_decimal b);
int s21_is_less_or_equal(s21_decimal a, s21_decimal b);
int s21_negate(s21_decimal value, s21_decimal* result);
int s21_truncate(s21_decimal value, s21_decimal* result);
int s21_floor(s21_decimal value, s21_decimal* result);
int s21_round(s21_decimal value, s21_decimal* result);
int s21_from_int_to_decimal(int src, s21_decimal* dst);
int s21_from_float_to_decimal(float src, s21_decimal* dst);
int s21_from_decimal_to_int(s21_decimal src, int* dst);
int s21_from_decimal_to_float(s21_decimal src, float* dst);

uint32_t mul_by_10(s21_decimal* value);
void set_zero(s21_decimal* value);
int is_decimal_zero(s21_decimal value);
int s21_get_sign(s21_decimal value);
void s21_set_sign(s21_decimal* dst, int sign);
int align_scales(s21_decimal* a, s21_decimal* b);
int s21_get_scale(s21_decimal value);
void s21_set_scale(s21_decimal* value, int scale);
uint32_t div_by_10(s21_decimal* a);
void set_bit(uint32_t* dst, int pos, int value);
int check_overflow(s21_decimal dec);
int compare_mantissa(s21_decimal a, s21_decimal b);

#endif
