#include "test.h"

START_TEST(sum_1) {
  matrix_t A, B, C, res;
  ck_assert_int_eq(s21_create_matrix(3, 3, &A), OK);
  ck_assert_int_eq(s21_create_matrix(3, 3, &B), OK);
  ck_assert_int_eq(s21_create_matrix(3, 3, &res), OK);

  set_matrix(&res, 2.0, 4.0, 6.0, 8.0, 10.0, 12.0, 14.0, 16.0, 18.0);
  fill_matrix(&A, 0);
  fill_matrix(&B, 0);
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &C), OK);
  ck_assert_int_eq(s21_eq_matrix(&C, &res), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(sum_2) {
  matrix_t A, B, C, res;
  ck_assert_int_eq(s21_create_matrix(3, 3, &A), OK);
  ck_assert_int_eq(s21_create_matrix(3, 3, &B), OK);
  ck_assert_int_eq(s21_create_matrix(3, 3, &res), OK);

  set_matrix(&res, 2.0, 2.0, 3.0, 2.0, 4.0, 5.0, 3.0, 4.0, 7.0);
  set_matrix(&A, 1.0, 2.0, 3.0, 0.0, 4.0, 5.0, 0.0, 0.0, 6.0);
  set_matrix(&B, 1.0, 0.0, 0.0, 2.0, 0.0, 0.0, 3.0, 4.0, 1.0);
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &C), OK);
  ck_assert_int_eq(s21_eq_matrix(&C, &res), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(sum_3) {
  matrix_t A, B, C;
  ck_assert_int_eq(s21_create_matrix(3, 3, &A), OK);
  ck_assert_int_eq(s21_create_matrix(3, 2, &B), OK);

  ck_assert_int_eq(s21_sum_matrix(&A, &B, &C), CALCULATION_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sum_4) {
  matrix_t A, B, C;
  ck_assert_int_eq(s21_create_matrix(3, 3, &A), OK);
  ck_assert_int_eq(s21_create_matrix(3, 3, &B), OK);
  B.columns = 0;

  ck_assert_int_eq(s21_sum_matrix(&A, &B, &C), INCORRECT_MATRIX);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sum_5) {
  matrix_t A, B, C, res;
  ck_assert_int_eq(s21_create_matrix(3, 3, &A), OK);
  ck_assert_int_eq(s21_create_matrix(3, 3, &B), OK);
  ck_assert_int_eq(s21_create_matrix(3, 3, &res), OK);

  set_matrix(&res, 3.0, 3.0, 4.0, 3.0, 4.0, 6.0, 4.0, 5.0, 8.0);
  set_matrix(&A, 1.5, 2.6, 3.2, 0.1, 4.0, 5.9, 0.6, 0.7, 6.3);
  set_matrix(&B, 1.5, 0.4, 0.8, 2.9, 0.0, 0.1, 3.4, 4.3, 1.7);
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &C), OK);
  ck_assert_int_eq(s21_eq_matrix(&C, &res), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(sum_6) {
  matrix_t A, B, C, res;
  ck_assert_int_eq(s21_create_matrix(3, 3, &A), OK);
  ck_assert_int_eq(s21_create_matrix(3, 3, &B), OK);
  ck_assert_int_eq(s21_create_matrix(3, 3, &res), OK);

  set_matrix(&res, 3.0, 3.0, 4.0, 3.0, 4.01, 6.0, 4.0, 5.0, 8.0);
  set_matrix(&A, 1.5, 2.6, 3.2, 0.1, 4.0, 5.9, 0.6, 0.7, 6.3);
  set_matrix(&B, 1.5, 0.4, 0.8, 2.9, 0.0, 0.1, 3.4, 4.3, 1.7);
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &C), OK);
  ck_assert_int_eq(s21_eq_matrix(&C, &res), FAILURE);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&res);
}
END_TEST

Suite* test_sum() {
  Suite* s = suite_create("\033[45mS21_SUM_MATRIX\033[0m");
  TCase* tc = tcase_create("sum");

  tcase_add_test(tc, sum_1);
  tcase_add_test(tc, sum_2);
  tcase_add_test(tc, sum_3);
  tcase_add_test(tc, sum_4);
  tcase_add_test(tc, sum_5);
  tcase_add_test(tc, sum_6);

  suite_add_tcase(s, tc);
  return s;
}