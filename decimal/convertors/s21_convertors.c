#include "s21_convertors.h"

int s21_from_decimal_to_int(s21_decimal src, int* dst) {
  int res = 0;
  if (dst == NULL) {
    res = 1;
  } else {
    memset(dst, 0, sizeof(int));
    int sign = s21_get_sign(src);
    int scale = s21_get_scale(src);
    while (scale > 0) {
      div_by_10(&src);
      scale--;
    }
    s21_set_scale(&src, scale);

    if (check_overflow(src)) {
      res = 1;
    } else {
      int result = (int)src.bits[0];
      if (sign) result = -result;

      *dst = result;
    }
  }

  return res;
}

int s21_from_decimal_to_float(s21_decimal src, float* dst) {
  int res = 0;
  if (dst == NULL) {
    res = 1;
  } else if (is_decimal_zero(src)) {
    if (s21_get_sign(src)) {
      *dst = -0.0;
    } else {
      *dst = +0.0;
    }
  } else {
    int sign = s21_get_sign(src);
    int scale = s21_get_scale(src);

    double mantissa = 0.0;
    mantissa += (double)src.bits[2] * pow(2, 64);
    mantissa += (double)src.bits[1] * pow(2, 32);
    mantissa += (double)src.bits[0];

    double value = mantissa / pow(10, scale);
    if (sign) value = -value;

    double abs_value = fabs(value);
    if (abs_value > 0 && abs_value < 1e-28) {
      res = 1;
    } else {
      float fval = (float)abs_value;
      if (sign) fval = -fval;
      *dst = fval;
    }
  }
  return res;
}

int s21_from_int_to_decimal(int src, s21_decimal* dst) {
  int code = 0;
  if (!dst) {
    code = 1;
  } else {
    dst->bits[0] = 0;
    dst->bits[1] = 0;
    dst->bits[2] = 0;
    dst->bits[3] = 0;

    if (src < 0) {
      dst->bits[3] |= (1u << 31);
      src = -src;
    }

    dst->bits[0] = (uint32_t)src;
  }

  return code;
}

void extract_mantissa_and_exp(const char* buff, char* mant, int* mant_len,
                              int* exp10) {
  *mant_len = 0;
  *exp10 = 0;
  int point_pos = -1;

  const char* e_ptr = strchr(buff, 'e');
  if (!e_ptr) e_ptr = strchr(buff, 'E');

  if (e_ptr) {
    for (int i = 0; i < (int)(e_ptr - buff); ++i) {
      char c = buff[i];
      if (c == '.') {
        point_pos = *mant_len;
      } else if (c >= '0' && c <= '9') {
        mant[(*mant_len)++] = c;
      }
    }
    *exp10 = atoi(e_ptr + 1);
  } else {
    for (int i = 0; buff[i] != 0; ++i) {
      char c = buff[i];
      if (c == '.') {
        point_pos = *mant_len;
      } else if (c >= '0' && c <= '9') {
        mant[(*mant_len)++] = c;
      }
    }
  }
  if (point_pos == -1) point_pos = *mant_len;
  *exp10 -= (*mant_len - point_pos);
}

void build_full_number(const char* mant, char* remainder, int mant_len,
                       int* rem_len, int exp10, char* full, int* full_len,
                       int* scale) {
  *full_len = 0;
  if (exp10 >= 0) {
    for (int i = 0; i < mant_len; ++i) full[(*full_len)++] = mant[i];
    for (int z = 0; z < exp10; ++z) full[(*full_len)++] = '0';
  } else {
    int remove = -exp10;
    int base = mant_len - remove;
    if (remove < mant_len) {
      for (int i = 0; i < base; i++) full[(*full_len)++] = mant[i];
      for (int i = base; i < mant_len; i++) remainder[(*rem_len)++] = mant[i];
    }
  }

  while (*full_len > 0 && full[*full_len - 1] == '0' && *scale > 0 &&
         *full_len > 1) {
    (*full_len)--;
    full[*full_len] = 0;
    (*scale)--;
  }
}

void convert_string_to_blocks(const char* full, int full_len,
                              uint32_t* blocks) {
  memset(blocks, 0, 3 * sizeof(uint32_t));
  for (int i = 0; i < full_len; ++i) {
    int digit = full[i] - '0';
    uint64_t carry = (uint64_t)digit;
    for (int k = 0; k < 3; ++k) {
      uint64_t tmp = (uint64_t)blocks[k] * 10ULL + carry;
      blocks[k] = (uint32_t)(tmp & 0xFFFFFFFFULL);
      carry = tmp >> 32;
    }
    if (carry != 0) {
      memset(blocks, 0, 3 * sizeof(uint32_t));
      break;
    }
  }
}

int s21_from_float_to_decimal(float src, s21_decimal* dst) {
  int code = 0;

  if (dst == NULL) {
    code = 1;
  } else {
    double abs_val = fabs(src);
    code = (abs_val > MAX_VAL || isinf(src) || isnan(src) ||
            (abs_val > 0 && abs_val < 1e-28))
               ? 1
               : 0;
    set_zero(dst);
    if (!code) {
      set_zero(dst);
      int scale = 0;
      normalize_scale(&scale, &abs_val);

      char buff[64];
      snprintf(buff, sizeof(buff), "%.7g", abs_val);

      char mant[64];
      int mant_len = 0, exp10 = 0;
      extract_mantissa_and_exp(buff, mant, &mant_len, &exp10);

      char full[128];
      char remainder[128];
      int full_len = 0;
      int rem_len = 0;
      build_full_number(mant, remainder, mant_len, &rem_len, exp10, full,
                        &full_len, &scale);

      bankers_round(full, &full_len, remainder, rem_len);
      uint32_t blocks[3] = {0};
      convert_string_to_blocks(full, full_len, blocks);

      dst->bits[0] = blocks[0];
      dst->bits[1] = blocks[1];
      dst->bits[2] = blocks[2];
      dst->bits[3] = 0;
      s21_set_sign(dst, signbit(src));
      s21_set_scale(dst, scale);
    }
  }

  return code;
}

void normalize_scale(int* scale, double* abs_val) {
  while (*abs_val < 0.1 && *scale < 28) {
    *abs_val *= 10.0;
    (*scale)++;
  }
  if (*scale + 7 > 28) {
    int diff = 28 - *scale;
    *abs_val *= pow(10, diff);
    *scale = 28;
  } else {
    *scale += 7;
    *abs_val *= pow(10, 7);
  }
}

void bankers_round(char* full, int* full_len, const char* remainder,
                   int rem_len) {
  if (rem_len == 0) return;

  int last_digit_index = *full_len - 1;
  int last_digit = full[last_digit_index] - '0';
  int first_rem = remainder[0] - '0';

  if (first_rem > 5) {
    last_digit++;
  } else if (first_rem == 5 && rem_len > 1) {
    last_digit++;
  } else if (first_rem == 5 && rem_len == 1) {
    if (last_digit % 2 != 0) {
      last_digit++;
    }
  }

  while (last_digit == 10 && last_digit_index >= 0) {
    full[last_digit_index] = '0';
    last_digit_index--;
    if (last_digit_index >= 0) {
      last_digit = full[last_digit_index] - '0' + 1;
    } else {
      memmove(full + 1, full, *full_len);
      full[0] = '1';
      (*full_len)++;
      full[*full_len] = '\0';
      return;
    }
  }

  if (last_digit_index >= 0) {
    full[last_digit_index] = (char)('0' + last_digit);
  }

  full[*full_len] = '\0';
}
