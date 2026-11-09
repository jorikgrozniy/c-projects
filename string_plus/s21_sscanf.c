#include "s21_sscanf.h"

#define DEFINE_ATOI(TYPE, NAME)                                                \
  TYPE NAME(Option *opt, char *str, char **str_lim, int base, int *is_digit) { \
    TYPE result = 0;                                                           \
    *is_digit = 1;                                                             \
                                                                               \
    int wid = (opt && opt->width) ? opt->width : -1;                           \
                                                                               \
    int sign = 1;                                                              \
    if (*str == '-') {                                                         \
      sign = -1;                                                               \
      str++;                                                                   \
      wid--;                                                                   \
    } else if (*str == '+') {                                                  \
      str++;                                                                   \
      wid--;                                                                   \
    }                                                                          \
                                                                               \
    if (wid == 0) *is_digit = 0;                                               \
                                                                               \
    if ((base == 0 || base == 16) && *str == '0' &&                            \
        (*(str + 1) == 'x' || *(str + 1) == 'X')) {                            \
      base = 16;                                                               \
      str += 2;                                                                \
      wid -= 2;                                                                \
    } else if ((base == 0 || base == 8) && *str == '0') {                      \
      base = 8;                                                                \
      str++;                                                                   \
      wid--;                                                                   \
    } else if (base == 0) {                                                    \
      base = 10;                                                               \
    }                                                                          \
                                                                               \
    if (base == 10) {                                                          \
      for (; *str >= '0' && *str <= '9' && wid; str++, wid--)                  \
        result = result * 10 + (*str - '0');                                   \
                                                                               \
    } else if (base == 8) {                                                    \
      for (; *str >= '0' && *str <= '7' && wid; str++, wid--)                  \
        result = result * 8 + (*str - '0');                                    \
                                                                               \
    } else if (base == 16) {                                                   \
      for (; ((*str >= '0' && *str <= '9') || (*str >= 'a' && *str <= 'f') ||  \
              (*str >= 'A' && *str <= 'F')) &&                                 \
             wid;                                                              \
           str++, wid--) {                                                     \
        if (*str >= '0' && *str <= '9')                                        \
          result = result * 16 + (*str - '0');                                 \
        else if (*str >= 'a' && *str <= 'f')                                   \
          result = result * 16 + (*str - 'a') + 10;                            \
        else if (*str >= 'A' && *str <= 'F')                                   \
          result = result * 16 + (*str - 'A') + 10;                            \
      }                                                                        \
    }                                                                          \
                                                                               \
    if (str_lim) *str_lim = str;                                               \
                                                                               \
    return (TYPE)(result * sign);                                              \
  }

DEFINE_ATOI(int, s21_atoi)
DEFINE_ATOI(short, s21_atoi_s)
DEFINE_ATOI(long, s21_atoi_l)
DEFINE_ATOI(long long, s21_atoi_ll)
DEFINE_ATOI(unsigned short, s21_atoi_us)
DEFINE_ATOI(unsigned int, s21_atoi_ui)
DEFINE_ATOI(unsigned long, s21_atoi_ul)
DEFINE_ATOI(unsigned long long, s21_atoi_ull)

int s21_sscanf(const char *str, const char *format, ...) {
  setlocale(LC_ALL, "");
  int result = 0;
  Option opt = {0};
  va_list args;

  va_start(args, format);
  char *tmp = malloc((s21_strlen(str) + 1) * sizeof(char));
  s21_strcpy(tmp, str);
  char *start = tmp;

  check_end(&opt, tmp);
  int stop = 0;
  for (; *format && !stop; format++) {
    reset(&opt, format);

    if (opt.format) {
      if (*format == '%') format++;
      if (*format >= '0' && *format <= '9') {
        opt.width = opt.width * 10 + (*format - '0');
      } else {
        result += prc_format(&tmp, format, &opt, args);
      }
    } else {
      match_non_form(&opt, &tmp, format);
    }
    if (is_break(&opt, &tmp, format)) {
      if (!result && opt.end) {
        result = -1;
      }
      stop = 1;
    }
  }
  free(start);
  va_end(args);

  return result;
}

void reset(Option *opt, const char *format) {
  if (*format == '%' && !opt->format) {
    opt->width = 0;
    opt->length = 0;
    opt->ignore = 0;
    opt->format = 1;
  }
}

void skip_spaces(Option *opt, char **str) {
  while (**str == ' ' || **str == '\n' || **str == '\t' || **str == '\r' ||
         **str == '\x0B' || **str == '\f') {
    (*str)++;
    opt->count++;
  }
}

void check_end(Option *opt, char *str) {
  while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\r' ||
         *str == '\x0B' || *str == '\f') {
    str++;
    opt->count++;
  }
  if (*str == '\0') {
    opt->end = 1;
  }
}

void match_non_form(Option *opt, char **str, const char *format) {
  if (*format == ' ' || *format == '\t' || *format == '\n' || *format == '\r' ||
      *format == '\x0B') {
    while (*format == **str) {
      (*str)++;
      opt->count++;
    }
  } else if (**str == *format) {
    (*str)++;
    opt->count++;
  } else {
    opt->error = 1;
  }
}

int is_break(const Option *opt, char **str, const char *format) {
  int result = 0;

  if ((!**str && !s21_strstr(format, "%n")) || opt->error) {
    result = 1;
  }

  return result;
}

int prc_int(va_list args, Option *opt, char **str, int base, int is_signed) {
  int result = 0;
  char *str_lim;
  int is_digit;

  skip_spaces(opt, str);

  if ((s21_atoi(opt, *str, S21_NULL, base, &is_digit) ||
       *(*str + s21_strspn(*str, "\n\t \f\x0B\r+-")) == '0') &&
      is_digit) {
    if (!opt->ignore) {
      result++;
      if (opt->length == -1) {
        if (is_signed)
          *(short int *)va_arg(args, void *) =
              s21_atoi_s(opt, *str, &str_lim, base, &is_digit);
        else
          *(short unsigned *)va_arg(args, void *) =
              s21_atoi_us(opt, *str, &str_lim, base, &is_digit);
      } else if (opt->length == 1) {
        if (is_signed)
          *(long int *)va_arg(args, void *) =
              s21_atoi_l(opt, *str, &str_lim, base, &is_digit);
        else
          *(long unsigned *)va_arg(args, void *) =
              s21_atoi_ul(opt, *str, &str_lim, base, &is_digit);
      } else if (opt->length == 2) {
        if (is_signed)
          *(long long int *)va_arg(args, void *) =
              (long long)s21_atoi(opt, *str, &str_lim, base, &is_digit);
        else
          *(long long unsigned *)va_arg(args, void *) =
              s21_atoi_ull(opt, *str, &str_lim, base, &is_digit);
      } else {
        if (is_signed)
          *(int *)va_arg(args, void *) =
              s21_atoi(opt, *str, &str_lim, base, &is_digit);
        else
          *(unsigned *)va_arg(args, void *) =
              s21_atoi_ui(opt, *str, &str_lim, base, &is_digit);
      }
    } else {
      if (is_signed)
        s21_atoi(opt, *str, &str_lim, base, &is_digit);
      else
        s21_atoi_ui(opt, *str, &str_lim, base, &is_digit);
    }
    opt->count += str_lim - *str;
    *str = str_lim;
  } else {
    opt->error = 1;
  }
  opt->format = 0;

  return result;
}

int prc_float(va_list args, Option *opt, char **str) {
  int result = 0;
  char *str_lim;
  int is_digit;

  if ((fabs(s21_atod(opt, *str, S21_NULL, &is_digit)) >= 1e-100 ||
       isnan(s21_atod(opt, *str, S21_NULL, &is_digit)) ||
       *(*str + s21_strspn(*str, "\n\t \f\x0B\r+-")) == '0') &&
      is_digit) {
    if (!opt->ignore) {
      result++;
      if (opt->length == 2) {
        *(long double *)va_arg(args, void *) =
            s21_atold(opt, *str, &str_lim, &is_digit);
      } else if (opt->length == 1) {
        *(double *)va_arg(args, void *) =
            s21_atod(opt, *str, &str_lim, &is_digit);
      } else {
        float x = s21_atof(opt, *str, &str_lim, &is_digit);
        *(float *)va_arg(args, void *) = x;
      }
    } else {
      s21_atold(opt, *str, &str_lim, &is_digit);
    }
    opt->count += str_lim - *str;
    *str = str_lim;
  } else {
    opt->error = 1;
  }
  opt->format = 0;
  return result;
}

long double s21_atold(Option *opt, char *str, char **str_lim, int *is_digit) {
  int sign;
  int wid = (opt->width) ? opt->width : -1;
  long double dec, val, e;
  *is_digit = 1;

  skip_spaces(opt, &str);

  sign = 1;
  if (*str == '-') {
    sign = -1;
    str++;
    wid--;
  }
  if (*str == '+') {
    str++;
    wid--;
  }

  if (wid == 0) *is_digit = 0;

  for (val = 0; *str >= '0' && *str <= '9' && wid; str++, wid--)
    val = val * 10 + *str - '0';
  if (*str == '.') str++;
  for (dec = 1; *str >= '0' && *str <= '9' && wid; str++, wid--, dec *= 10)
    val = val * 10 + *str - '0';
  if (*str == 'e' || *str == 'E') {
    int esign;
    // if (val <= 1e-6) val = 1;
    str++;
    esign = 1;
    if (*str == '-') {
      esign = -1;
      str++;
      wid--;
    }
    if (*str == '+') {
      str++;
      wid--;
    }
    for (e = 0; *str >= '0' && *str <= '9' && wid; str++, wid--)
      e = e * 10 + *str - '0';
    e *= esign;
  } else {
    e = 0;
  }

  if ((*str == 'n' || *str == 'N') &&
      (*(str + 1) == 'a' || *(str + 1) == 'A') &&
      (*(str + 2) == 'n' || *(str + 2) == 'N')) {
    str += 3;
    val = NAN * sign;
  }
  if ((*str == 'i' || *str == 'I') &&
      (*(str + 1) == 'n' || *(str + 1) == 'N') &&
      (*(str + 2) == 'f' || *(str + 2) == 'F')) {
    str += 3;
    val = INFINITY * sign;
  }

  if (str_lim) *str_lim = str;

  return (isnan(val) || isinf(val)) ? val : (val * sign / dec) * powl(10, e);
}

double s21_atod(Option *opt, char *str, char **str_lim, int *is_digit) {
  return s21_atold(opt, str, str_lim, is_digit);
}

float s21_atof(Option *opt, char *str, char **str_lim, int *is_digit) {
  return s21_atold(opt, str, str_lim, is_digit);
}

void prc_perc(Option *opt, char **str, const char *format) {
  skip_spaces(opt, str);
  if (*format == **str) {
    opt->count++;
    (*str)++;
  } else {
    opt->error = 1;
  }
  opt->format = 0;
}

void prc_n(va_list args, Option *opt) {
  if (!opt->ignore) {
    if (opt->length == -1)
      *(short int *)va_arg(args, void *) = opt->count;
    else if (opt->length == 1)
      *(long int *)va_arg(args, void *) = opt->count;
    else if (opt->length == 0)
      *(int *)va_arg(args, void *) = opt->count;
    else if (opt->length == 2) {
      opt->error = 1;
    }
  }
  opt->format = 0;
}

int prc_ptr(va_list args, Option *opt, char **str) {
  int result = 0;
  char *str_lim;
  int is_digit;
  opt->length = 2;
  if (s21_atoi(opt, *str, S21_NULL, 16, &is_digit)) {
    if (!opt->ignore) {
      result++;
      unsigned long long ptr = s21_atoi_ull(opt, *str, &str_lim, 16, &is_digit);
      *(void **)va_arg(args, void **) = (void *)(uintptr_t)ptr;
    } else {
      s21_atoi(opt, *str, &str_lim, 16, &is_digit);
    }
    opt->count += str_lim - *str;
    *str = str_lim;
  } else {
    opt->error = 1;
  }
  opt->format = 0;
  return result;
}

int prc_char(va_list args, Option *opt, char **str) {
  int result = 0;
  if (!opt->ignore) {
    if (opt->length == 1) {
      *(wchar_t *)va_arg(args, wchar_t *) = **str;
      result++;
    } else if (opt->length == 0) {
      *(char *)va_arg(args, char *) = **str;
      result++;
    } else {
      opt->error = 1;
    }
  }
  (*str)++;
  opt->count++;
  opt->format = 0;
  return result;
}

int prc_str(va_list args, Option *opt, char **str) {
  int result = 0;
  char *new_str =
      (opt->length) ? malloc(sizeof(wchar_t)) : malloc(sizeof(char));
  if (new_str) {
    skip_spaces(opt, str);
    int i = 0;
    int realloc_failed = 0;

    while (**str && !s21_isspace(**str) &&
           (opt->width == 0 || i < opt->width) && !realloc_failed) {
      void *tmp = S21_NULL;
      if (opt->length) {
        tmp = realloc(new_str, (i + 2) * sizeof(wchar_t));
      } else {
        tmp = realloc(new_str, (i + 2) * sizeof(char));
      }
      if (tmp == S21_NULL) {
        free(new_str);
        new_str = S21_NULL;
        realloc_failed = 1;
      } else {
        new_str = tmp;
        new_str[i] = **str;
        i++;
        (*str)++;
      }
    }

    if (new_str) {
      new_str[i] = '\0';
      int len = s21_strlen(new_str) + 1;

      if (!opt->ignore) {
        void *dest = S21_NULL;
        if (!opt->length) {
          result++;
          dest = va_arg(args, char *);
          char *cdest = (char *)dest;
          for (int j = 0; j < len; j++) {
            cdest[j] = new_str[j];
          }
        } else if (opt->length == 1) {
          result++;
          dest = va_arg(args, wchar_t *);
          wchar_t *wdest = (wchar_t *)dest;
          mbstowcs(wdest, new_str, len);
        } else {
          opt->error = 1;
        }
      }
      free(new_str);
      opt->count += len - 1;
      opt->format = 0;
    }
  }
  return result;
}

int prc_format(char **str, const char *format, Option *opt, va_list args) {
  int result = 0;
  switch (*format) {
    case 'd':
      result += prc_int(args, opt, str, 10, 1);
      break;
    case 'i':
      result += prc_int(args, opt, str, 0, 1);
      break;
    case 'o':
      result += prc_int(args, opt, str, 8, 0);
      break;
    case 'u':
      result += prc_int(args, opt, str, 10, 0);
      break;
    case 'x':
    case 'X':
      result += prc_int(args, opt, str, 16, 0);
      break;
    case 'e':
    case 'E':
    case 'g':
    case 'G':
    case 'f':
      result += prc_float(args, opt, str);
      break;
    case 'c':
      result += prc_char(args, opt, str);
      break;
    case 's':
      result += prc_str(args, opt, str);
      break;
    case 'p':
      result += prc_ptr(args, opt, str);
      break;
    case 'n':
      prc_n(args, opt);
      break;
    case '%':
      prc_perc(opt, str, format);
      break;
    case '*':
      opt->ignore = 1;
      break;
    case 'h':
      opt->length = -1;
      break;
    case 'l':
      if (opt->length == 1) {
        opt->length = 2;
      } else {
        opt->length = 1;
      }
      break;
    case 'L':
      opt->length = 2;
      break;
  }

  return result;
}
