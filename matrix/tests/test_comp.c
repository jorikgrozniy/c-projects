#include "test.h"

START_TEST(comp_1) {
  matrix_t A, C, res;
  ck_assert_int_eq(s21_create_matrix(3, 3, &A), OK);
  ck_assert_int_eq(s21_create_matrix(3, 3, &res), OK);

  set_matrix(&A, 1.0, 2.0, 3.0, 0.0, 4.0, 2.0, 5.0, 2.0, 1.0);
  set_matrix(&res, 0.0, 10.0, -20.0, 4.0, -14.0, 8.0, -8.0, -2.0, 4.0);
  ck_assert_int_eq(s21_calc_complements(&A, &C), OK);
  ck_assert_int_eq(s21_eq_matrix(&C, &res), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(comp_2) {
  matrix_t A, C;
  ck_assert_int_eq(s21_create_matrix(3, 4, &A), OK);

  ck_assert_int_eq(s21_calc_complements(&A, &C), CALCULATION_ERROR);

  s21_remove_matrix(&A);
}
END_TEST

Suite* test_comp() {
  Suite* s = suite_create("\033[45mS21_CALC_COMPLEMENTS\033[0m");
  TCase* tc = tcase_create("comp");

  tcase_add_test(tc, comp_1);
  tcase_add_test(tc, comp_2);

  suite_add_tcase(s, tc);
  return s;
}