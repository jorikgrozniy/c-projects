#include "s21_sprintf.h"

int s21_sprintf(char* str, const char* format, ...) {
  va_list args;
  va_start(args, format);
  char* p = str;

  while (*format) {
    if (*format == '%') {
      format++;
      process_format(&args, &format, &p);
    } else {
      *p = *format;
      p++;
    }
    format++;
  }

  *p = '\0';
  va_end(args);
  return p - str;
}

int s21_isdigit(char c) { return (c >= '0' && c <= '9'); }

void parse_flags(const char** format, options* sp) {
  sp->f_minus = 0;
  sp->f_plus = 0;
  sp->f_space = 0;
  int exit = 0;
  while (!exit) {
    switch (**format) {
      case '+':
        sp->f_plus = 1;
        (*format)++;
        break;
      case '-':
        sp->f_minus = 1;
        (*format)++;
        break;
      case ' ':
        sp->f_space = 1;
        (*format)++;
        break;
      default:
        exit = 1;
        break;
    }
  }
}

void parse_width(const char** format, options* sp) {
  sp->width = 0;
  while (s21_isdigit(**format)) {
    sp->width = sp->width * 10 + (**format - '0');
    (*format)++;
  }
}

void parse_precision(const char** format, options* sp) {
  sp->precision = -1;
  if (**format == '.') {
    (*format)++;
    if (!s21_isdigit(**format))
      sp->precision = 0;
    else {
      sp->precision = 0;
      while (s21_isdigit(**format)) {
        sp->precision = sp->precision * 10 + (**format - '0');
        (*format)++;
      }
    }
  }
}

void parse_length(const char** format, options* sp) {
  if (**format == 'h' || **format == 'l') {
    sp->length = **format;
    (*format)++;
  } else
    sp->length = 0;
}

void parse_format_specs(const char** format, options* sp) {
  parse_flags(format, sp);
  parse_width(format, sp);
  parse_precision(format, sp);
  parse_length(format, sp);
  sp->spec = **format;
}

void reverse_string(char* str) {
  int len = s21_strlen(str);
  for (int i = 0; i < len / 2; i++) {
    char tmp = str[i];
    str[i] = str[len - 1 - i];
    str[len - 1 - i] = tmp;
  }
}

char* s21_itoa(char* str, unsigned long long int n) {
  int i = 0;

  if (n == 0) {
    str[i++] = '0';
  } else {
    while (n > 0) {
      str[i++] = (n % 10) + '0';
      n /= 10;
    }
  }
  str[i] = '\0';
  reverse_string(str);
  return str;
}

char* s21_utoa(char* str, unsigned long long int n) {
  int i = 0;
  if (n == 0) {
    str[i++] = '0';
  } else {
    while (n > 0) {
      str[i++] = (n % 10) + '0';
      n /= 10;
    }
  }
  str[i] = '\0';
  reverse_string(str);
  return str;
}

void fill_width(char** p, int n, char c) {
  for (int i = 0; i < n; i++) {
    **p = c;
    (*p)++;
  }
}

void print_sign(char** p, options sp, int is_positive, int is_negative) {
  if (is_negative) {
    **p = '-';
    (*p)++;
  } else if (is_positive) {
    if (sp.f_plus) {
      **p = '+';
      (*p)++;
    } else if (sp.f_space) {
      **p = ' ';
      (*p)++;
    }
  }
}

void print_d(va_list* args, options sp, char** p) {
  char str[64] = {0};
  long long int num;
  if (sp.length == 'l') {
    num = va_arg(*args, long int);
  } else if (sp.length == 'h') {
    num = (short int)va_arg(*args, int);
  } else {
    num = va_arg(*args, int);
  }

  int neg = (num < 0);
  unsigned long long int unum =
      neg ? (unsigned long long int)(-num) : (unsigned long long int)num;

  s21_itoa(str, unum);

  int len = s21_strlen(str);
  if (sp.precision == -1) sp.precision = 0;

  int zeros = (len < sp.precision) ? sp.precision - len : 0;

  int sign_char = (neg || sp.f_plus || sp.f_space) ? 1 : 0;

  int total_len = zeros + len + sign_char;

  int spaces = (total_len < sp.width) ? sp.width - total_len : 0;

  if (!sp.f_minus) fill_width(p, spaces, ' ');

  print_sign(p, sp, !neg, neg);

  fill_width(p, zeros, '0');

  s21_strcpy(*p, str);
  (*p) += len;

  if (sp.f_minus) fill_width(p, spaces, ' ');
}

void print_c(va_list* args, options sp, char** p) {
  char c = (char)va_arg(*args, int);
  int spaces = sp.width > 1 ? sp.width - 1 : 0;

  if (!sp.f_minus) fill_width(p, spaces, ' ');
  **p = c;
  (*p)++;
  if (sp.f_minus) fill_width(p, spaces, ' ');
}

void print_s(va_list* args, options sp, char** p) {
  const char* str = va_arg(*args, const char*);
  if (str == S21_NULL) str = "(null)";
  int len = s21_strlen(str);
  if (sp.precision >= 0 && sp.precision < len) {
    len = sp.precision;
  }

  int spaces = (len < sp.width) ? sp.width - len : 0;

  if (!sp.f_minus) fill_width(p, spaces, ' ');
  s21_strncpy(*p, str, len);
  (*p) += len;
  if (sp.f_minus) fill_width(p, spaces, ' ');
}

long double round_precision(long double n, int precision) {
  long double factor = powl(10.0L, precision);
  return roundl(n * factor) / factor;
}

char* s21_dtoa(char* str, long double n, int precision) {
  if (n < 0) n = -n;
  long long int int_part = (long long int)n;
  long double frac = n - int_part;

  long double frac_scaled = roundl(frac * powl(10.0L, precision));
  if (frac_scaled >= powl(10.0L, precision)) {
    int_part++;
    frac_scaled = 0;
  }

  char str_int[64] = {0};
  char str_frac[64] = {0};

  s21_itoa(str_int, (unsigned long long)int_part);
  s21_utoa(str_frac, (unsigned long long)frac_scaled);

  char* ptr = str;
  s21_strcpy(ptr, str_int);
  ptr += s21_strlen(str_int);

  if (precision > 0) {
    *ptr++ = '.';
    int frac_len = s21_strlen(str_frac);
    for (int i = 0; i < precision - frac_len; i++) {
      *ptr++ = '0';
    }
    s21_strcpy(ptr, str_frac);
    ptr += frac_len;
  }
  *ptr = '\0';
  return str;
}

void print_f(va_list* args, options sp, char** p) {
  char str[128] = {0};
  int precision = (sp.precision >= 0) ? sp.precision : 6;
  double n = va_arg(*args, double);
  int neg = (n < 0);

  n = round_precision(n, precision);

  s21_dtoa(str, n, precision);

  int len = s21_strlen(str);
  int sign_char = (neg || sp.f_plus || sp.f_space) ? 1 : 0;
  int spaces = (len + sign_char < sp.width) ? sp.width - (len + sign_char) : 0;

  if (!sp.f_minus) fill_width(p, spaces, ' ');

  print_sign(p, sp, !neg, neg);

  s21_strcpy(*p, str);
  (*p) += len;

  if (sp.f_minus) fill_width(p, spaces, ' ');
}

void print_u(va_list* args, options sp, char** p) {
  char str[64] = {0};
  unsigned long long int num;
  if (sp.length == 'l') {
    num = va_arg(*args, unsigned long int);
  } else if (sp.length == 'h') {
    num = (unsigned short int)va_arg(*args, unsigned int);
  } else {
    num = va_arg(*args, unsigned int);
  }

  s21_utoa(str, num);

  int len = s21_strlen(str);
  if (sp.precision == -1) sp.precision = 0;
  int zeros = (len < sp.precision) ? sp.precision - len : 0;

  int total_len = len + zeros;
  int spaces = (total_len < sp.width) ? sp.width - total_len : 0;

  if (!sp.f_minus) fill_width(p, spaces, ' ');
  fill_width(p, zeros, '0');
  s21_strcpy(*p, str);
  (*p) += len;
  if (sp.f_minus) fill_width(p, spaces, ' ');
}

void process_format(va_list* args, const char** format, char** p) {
  options sp;
  parse_format_specs(format, &sp);
  switch (sp.spec) {
    case 'd':
      print_d(args, sp, p);
      break;
    case 'c':
      print_c(args, sp, p);
      break;
    case 's':
      print_s(args, sp, p);
      break;
    case 'f':
      print_f(args, sp, p);
      break;
    case 'u':
      print_u(args, sp, p);
      break;
    default:
      **p = sp.spec;
      (*p)++;
  }
}