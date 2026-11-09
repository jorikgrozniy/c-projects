#include "test.h"

START_TEST(inverse_1) {
  matrix_t A, C, res;
  ck_assert_int_eq(s21_create_matrix(3, 3, &A), OK);
  ck_assert_int_eq(s21_create_matrix(3, 3, &res), OK);

  set_matrix(&A, 2.0, 5.0, 7.0, 6.0, 3.0, 4.0, 5.0, -2.0, -3.0);
  set_matrix(&res, 1.0, -1.0, 1.0, -38.0, 41.0, -34.0, 27.0, -29.0, 24.0);
  ck_assert_int_eq(s21_inverse_matrix(&A, &C), OK);
  ck_assert_int_eq(s21_eq_matrix(&C, &res), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(inverse_2) {
  matrix_t A, C;
  ck_assert_int_eq(s21_create_matrix(3, 3, &A), OK);

  fill_matrix(&A, 0);
  ck_assert_int_eq(s21_inverse_matrix(&A, &C), CALCULATION_ERROR);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(inverse_3) {
  matrix_t A, C;
  ck_assert_int_eq(s21_create_matrix(3, 4, &A), OK);

  fill_matrix(&A, 0);
  ck_assert_int_eq(s21_inverse_matrix(&A, &C), CALCULATION_ERROR);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(inverse_4) {
  matrix_t A, C, res, E;
  ck_assert_int_eq(s21_create_matrix(3, 3, &A), OK);
  ck_assert_int_eq(s21_create_matrix(3, 3, &E), OK);

  set_matrix(&A, 2.0, 5.0, 7.0, 6.0, 3.0, 4.0, 5.0, -2.0, -3.0);
  set_matrix(&E, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0);
  ck_assert_int_eq(s21_inverse_matrix(&A, &C), OK);
  ck_assert_int_eq(s21_mult_matrix(&A, &C, &res), OK);
  ck_assert_int_eq(s21_eq_matrix(&E, &res), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&E);
  s21_remove_matrix(&res);
}
END_TEST

Suite* test_inverse() {
  Suite* s = suite_create("\033[45mS21_INVERSE_MATRIX\033[0m");
  TCase* tc = tcase_create("inverse");

  tcase_add_test(tc, inverse_1);
  tcase_add_test(tc, inverse_2);
  tcase_add_test(tc, inverse_3);
  tcase_add_test(tc, inverse_4);

  suite_add_tcase(s, tc);
  return s;
}