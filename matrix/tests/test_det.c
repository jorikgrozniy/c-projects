#include "test.h"

START_TEST(det_1) {
  matrix_t A;
  double n;
  ck_assert_int_eq(s21_create_matrix(3, 3, &A), OK);

  fill_matrix(&A, 0);
  ck_assert_int_eq(s21_determinant(&A, &n), OK);
  ck_assert_double_eq(n, 0.0);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(det_2) {
  matrix_t A;
  double n;
  ck_assert_int_eq(s21_create_matrix(3, 3, &A), OK);

  set_matrix(&A, 1.0, 2.0, 5.0, 4.0, 8.0, 5.0, 1.0, 7.0, 6.0);
  ck_assert_int_eq(s21_determinant(&A, &n), OK);
  ck_assert_double_eq(n, 75.0);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(det_3) {
  matrix_t A;
  double n;
  ck_assert_int_eq(s21_create_matrix(7, 7, &A), OK);

  fill_matrix(&A, 0);
  ck_assert_int_eq(s21_determinant(&A, &n), OK);
  ck_assert_double_eq(n, 0.0);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(det_4) {
  matrix_t A;
  double n;
  ck_assert_int_eq(s21_create_matrix(1, 1, &A), OK);

  fill_matrix(&A, 0);
  ck_assert_int_eq(s21_determinant(&A, &n), OK);
  ck_assert_double_eq(n, 1.0);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(det_5) {
  matrix_t A;
  double n;
  ck_assert_int_eq(s21_create_matrix(2, 2, &A), OK);

  fill_matrix(&A, 0);
  ck_assert_int_eq(s21_determinant(&A, &n), OK);
  ck_assert_double_eq(n, -2.0);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(det_6) {
  matrix_t A;
  double n;
  ck_assert_int_eq(s21_create_matrix(2, 3, &A), OK);

  ck_assert_int_eq(s21_determinant(&A, &n), CALCULATION_ERROR);

  s21_remove_matrix(&A);
}
END_TEST

Suite* test_det() {
  Suite* s = suite_create("\033[45mS21_DETERMINANT\033[0m");
  TCase* tc = tcase_create("det");

  tcase_add_test(tc, det_1);
  tcase_add_test(tc, det_2);
  tcase_add_test(tc, det_3);
  tcase_add_test(tc, det_4);
  tcase_add_test(tc, det_5);
  tcase_add_test(tc, det_6);

  suite_add_tcase(s, tc);
  return s;
}