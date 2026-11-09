#include "test.h"

START_TEST(mult_n_1) {
  matrix_t A, C, res;
  ck_assert_int_eq(s21_create_matrix(3, 3, &A), OK);
  ck_assert_int_eq(s21_create_matrix(3, 3, &res), OK);

  fill_matrix(&A, 0);
  set_matrix(&res, 2.0, 4.0, 6.0, 8.0, 10.0, 12.0, 14.0, 16.0, 18.0);
  ck_assert_int_eq(s21_mult_number(&A, 2, &C), OK);
  ck_assert_int_eq(s21_eq_matrix(&C, &res), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(mult_n_2) {
  matrix_t A, C, res;
  ck_assert_int_eq(s21_create_matrix(3, 3, &A), OK);
  ck_assert_int_eq(s21_create_matrix(3, 3, &res), OK);

  set_matrix(&res, 2.0, 4.0, 6.0, 0.0, 8.0, 4.0, 4.0, 6.0, 8.0);
  set_matrix(&A, 1.0, 2.0, 3.0, 0.0, 4.0, 2.0, 2.0, 3.0, 4.0);
  ck_assert_int_eq(s21_mult_number(&A, 2, &C), OK);
  ck_assert_int_eq(s21_eq_matrix(&C, &res), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(mult_n_3) {
  matrix_t A, C, res;
  ck_assert_int_eq(s21_create_matrix(2, 4, &A), OK);
  ck_assert_int_eq(s21_create_matrix(2, 4, &res), OK);

  set_matrix(&res, -1.0, -2.0, -3.0, -0.0, -4.0, -2.0, -2.0, -3.0);
  set_matrix(&A, 1.0, 2.0, 3.0, 0.0, 4.0, 2.0, 2.0, 3.0);
  ck_assert_int_eq(s21_mult_number(&A, -1, &C), OK);
  ck_assert_int_eq(s21_eq_matrix(&C, &res), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&res);
}
END_TEST

Suite* test_mult_n() {
  Suite* s = suite_create("\033[45mS21_MULT_NUMBER\033[0m");
  TCase* tc = tcase_create("mult_n");

  tcase_add_test(tc, mult_n_1);
  tcase_add_test(tc, mult_n_2);
  tcase_add_test(tc, mult_n_3);

  suite_add_tcase(s, tc);
  return s;
}