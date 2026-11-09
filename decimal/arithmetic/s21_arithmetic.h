#ifndef S21_ARITHM_H
#define S21_ARITHM_H

#include "../comparison/s21_comparison.h"
#include "../convertors/s21_convertors.h"
#include "../others/s21_others.h"
#include "../s21_decimal.h"

typedef struct {
  uint32_t data[7];
} big_decimal;

// =========================== S21_ADD S21_SUB =================================

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);
int mul_by_10_big(big_decimal* value);
uint32_t div_by_10_big(big_decimal* value);
int compare_mantissa_big(big_decimal a, big_decimal b);
void compress_scale_big(big_decimal* num);
int is_overflow_big(big_decimal num);
int bank_rounding_big(big_decimal value, big_decimal* result);
void decimal_to_big(s21_decimal dec, big_decimal* big);
void big_to_decimal(big_decimal big, s21_decimal* dec);
void align_scales_big(big_decimal* a, big_decimal* b);
void set_scale_big(big_decimal* value, int scale);
void set_sign_big(big_decimal* value, int sign);
int get_sign_big(big_decimal value);
int get_scale_big(big_decimal value);

// =============================== S21_DIV =====================================
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);
void divide_big_decimal(big_decimal dividend, big_decimal divisor,
                        big_decimal* quotient, big_decimal* remainder);
void shift_left_one_big(big_decimal* num);
void subtract_big(big_decimal* a, const big_decimal* b);
int is_big_dec_zero(big_decimal value);
int big_convertion(big_decimal big, s21_decimal* dec, int* scale);
void set_zero_big_dec(big_decimal* value);
void add_big(big_decimal* a, const big_decimal* b);
void round_big(big_decimal remainder, big_decimal big_2,
               big_decimal* total_quotient);

// =============================== S21_MUL =====================================
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);
void bigint_add(uint32_t* num, int size, uint64_t add);
uint32_t bigint_div10(uint32_t* num, int size);
void bigint_div10_banker(uint32_t* num, int size);
void normalize_scales_big(s21_decimal value_1, s21_decimal value_2,
                          big_decimal* big_1, big_decimal* big_2);
int is_big_dec_overflow(big_decimal value);
int count_leading_zeros(big_decimal value);
void shift_left_n_big(big_decimal* num, int n);

#endif