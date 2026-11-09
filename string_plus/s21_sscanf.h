#ifndef S21_SSCANF_H
#define S21_SSCANF_H

#include <locale.h>
#include <math.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdlib.h>
#include <wchar.h>

#include "s21_string.h"

typedef struct Option {
  int width;
  int length;
  int error;
  int ignore;
  int format;
  int count;
  int end;
} Option;

void reset(Option *opt, const char *format);
void skip_spaces(Option *opt, char **str);
void match_non_form(Option *opt, char **str, const char *format);
int is_break(const Option *opt, char **str, const char *format);
int prc_float(va_list args, Option *opt, char **str);
long double s21_atold(Option *opt, char *str, char **str_lim, int *is_digit);
double s21_atod(Option *opt, char *str, char **str_lim, int *is_digit);
float s21_atof(Option *opt, char *str, char **str_lim, int *is_digit);
int prc_int(va_list args, Option *opt, char **str, int base, int is_signed);
void prc_perc(Option *opt, char **str, const char *format);
void prc_n(va_list args, Option *opt);
int prc_ptr(va_list args, Option *opt, char **str);
int prc_char(va_list args, Option *opt, char **str);
int prc_str(va_list args, Option *opt, char **str);
int prc_format(char **str, const char *format, Option *opt, va_list args);
void check_end(Option *opt, char *str);

#endif