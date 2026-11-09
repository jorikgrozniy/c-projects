#include "test.h"

START_TEST(transpose_1) {
  matrix_t A, C, res;
  ck_assert_int_eq(s21_create_matrix(3, 3, &A), OK);
  ck_assert_int_eq(s21_create_matrix(3, 3, &res), OK);

  fill_matrix(&A, 0);
  set_matrix(&res, 1.0, 4.0, 7.0, 2.0, 5.0, 8.0, 3.0, 6.0, 9.0);
  ck_assert_int_eq(s21_transpose(&A, &C), OK);
  ck_assert_int_eq(s21_eq_matrix(&C, &res), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(transpose_2) {
  matrix_t A, C, res;
  ck_assert_int_eq(s21_create_matrix(2, 4, &A), OK);
  ck_assert_int_eq(s21_create_matrix(4, 2, &res), OK);

  fill_matrix(&A, 0);
  set_matrix(&res, 1.0, 5.0, 2.0, 6.0, 3.0, 7.0, 4.0, 8.0);
  ck_assert_int_eq(s21_transpose(&A, &C), OK);
  ck_assert_int_eq(s21_eq_matrix(&C, &res), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(transpose_3) {
  matrix_t A, C;
  ck_assert_int_eq(s21_create_matrix(3, 4, &A), OK);
  A.columns = -2;

  ck_assert_int_eq(s21_transpose(&A, &C), INCORRECT_MATRIX);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(transpose_4) {
  matrix_t A, C, res;
  ck_assert_int_eq(s21_create_matrix(4, 2, &A), OK);
  ck_assert_int_eq(s21_create_matrix(2, 4, &res), OK);

  fill_matrix(&A, 0);
  set_matrix(&res, 1.0, 3.0, 5.0, 7.0, 2.0, 4.0, 6.0, 8.0);
  ck_assert_int_eq(s21_transpose(&A, &C), OK);
  ck_assert_int_eq(s21_eq_matrix(&C, &res), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&res);
}
END_TEST

Suite* test_transpose() {
  Suite* s = suite_create("\033[45mS21_TRANSPOSE\033[0m");
  TCase* tc = tcase_create("transpose");

  tcase_add_test(tc, transpose_1);
  tcase_add_test(tc, transpose_2);
  tcase_add_test(tc, transpose_3);
  tcase_add_test(tc, transpose_4);

  suite_add_tcase(s, tc);
  return s;
}