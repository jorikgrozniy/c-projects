#include "s21_arithmetic.h"

void bigint_add(uint32_t* num, int size, uint64_t add) {
  uint64_t carry = add;
  for (int i = 0; i < size && carry; i++) {
    uint64_t sum = (uint64_t)num[i] + carry;
    num[i] = (uint32_t)(sum & 0xFFFFFFFF);
    carry = sum >> 32;
  }
}

uint32_t bigint_div10(uint32_t* num, int size) {
  uint64_t rem = 0;
  for (int i = size - 1; i >= 0; i--) {
    uint64_t cur = (rem << 32) | num[i];
    num[i] = (uint32_t)(cur / 10);
    rem = cur % 10;
  }
  return (uint32_t)rem;
}

void bigint_div10_banker(uint32_t* num, int size) {
  uint32_t remainder = bigint_div10(num, size);
  if (remainder > 5) {
    bigint_add(num, size, 1);
  } else if (remainder == 5) {
    uint32_t last_digit = num[0] % 10;
    if (last_digit % 2 != 0) {
      bigint_add(num, size, 1);
    }
  }
}

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  int res = 0;
  if (result == NULL) {
    res = 1;
  } else {
    set_zero(result);

    uint32_t product[6] = {0};
    for (int i = 0; i < 3; i++) {
      uint64_t carry = 0;
      for (int j = 0; j < 3; j++) {
        uint64_t temp = (uint64_t)value_1.bits[i] * value_2.bits[j] +
                        product[i + j] + carry;
        product[i + j] = (uint32_t)(temp & 0xFFFFFFFF);
        carry = (uint64_t)(temp >> 32);
      }
      product[i + 3] += (uint32_t)carry;
    }

    int final_sign = s21_get_sign(value_1) ^ s21_get_sign(value_2);
    int final_scale = s21_get_scale(value_1) + s21_get_scale(value_2);

    while (final_scale > 28) {
      bigint_div10(product, 6);
      final_scale--;
    }

    while ((product[3] || product[4] || product[5]) && final_scale > 0) {
      bigint_div10_banker(product, 6);
      final_scale--;
    }

    if (product[3] || product[4] || product[5]) {
      res = (final_sign) ? 2 : 1;
    } else {
      result->bits[0] = product[0];
      result->bits[1] = product[1];
      result->bits[2] = product[2];
      result->bits[3] = 0;
      s21_set_sign(result, final_sign);
      s21_set_scale(result, final_scale);
    }
  }

  return res;
}
