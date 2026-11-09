#include "test.h"

START_TEST(s21_set_scale_1) {
  s21_decimal x = {{0}};
  s21_set_scale(&x, 5);
  ck_assert_int_eq(s21_get_scale(x), 5);
}
END_TEST

START_TEST(s21_set_sign_1) {
  s21_decimal x = {{0}};
  s21_set_sign(&x, 1);
  ck_assert_int_eq(s21_get_sign(x), 1);
}
END_TEST

Suite* init_suite_common() {
  Suite* suite = suite_create("\033[45mSUITE_COMMON\033[0m");

  TCase* tcase_bit_manipulation = tcase_create("bit_manipulation");
  tcase_add_test(tcase_bit_manipulation, s21_set_scale_1);
  tcase_add_test(tcase_bit_manipulation, s21_set_sign_1);
  suite_add_tcase(suite, tcase_bit_manipulation);

  return suite;
}
