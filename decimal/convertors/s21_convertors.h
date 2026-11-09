#ifndef S21_CONVR_H
#define S21_CONVR_H

#include "../comparison/s21_comparison.h"
#include "../others/s21_others.h"
#include "../s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int* dst);
int s21_from_decimal_to_float(s21_decimal src, float* dst);
int s21_from_int_to_decimal(int src, s21_decimal* dst);
void extract_mantissa_and_exp(const char* buff, char* mant, int* mant_len,
                              int* exp10);
void build_full_number(const char* mant, char* remainder, int mant_len,
                       int* rem_len, int exp10, char* full, int* full_len,
                       int* scale);
void convert_string_to_blocks(const char* full, int full_len, uint32_t* blocks);
int s21_from_float_to_decimal(float src, s21_decimal* dst);
void bankers_round(char* full, int* full_len, const char* remainder,
                   int rem_len);
void normalize_scale(int* scale, double* abs_val);

#endif