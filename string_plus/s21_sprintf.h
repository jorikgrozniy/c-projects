#ifndef S21_SPRINTF_H
#define S21_SPRINTF_H

#include <math.h>
#include <stdarg.h>

#include "s21_string.h"

typedef struct {
  char spec;
  int f_plus;
  int f_minus;
  int f_space;
  int width;
  int precision;
  char length;
} options;

int s21_isdigit(char c);
void parse_flags(const char** format, options* sp);
void parse_width(const char** format, options* sp);
void parse_precision(const char** format, options* sp);
void parse_length(const char** format, options* sp);
void parse_format_specs(const char** format, options* sp);
void reverse_string(char* str);
char* s21_itoa(char* str, unsigned long long int n);
void fill_width(char** p, int n, char c);
void print_sign(char** p, options sp, int is_positive, int is_negative);
void print_d(va_list* args, options sp, char** p);
void print_c(va_list* args, options sp, char** p);
void print_s(va_list* args, options sp, char** p);
long double round_precision(long double n, int precision);
char* s21_dtoa(char* str, long double n, int precision);
void print_f(va_list* args, options sp, char** p);
void print_u(va_list* args, options sp, char** p);
void process_format(va_list* args, const char** format, char** p);

#endif