#include "test.h"

START_TEST(mult_1) {
  matrix_t A, B, C, res;
  ck_assert_int_eq(s21_create_matrix(3, 3, &A), OK);
  ck_assert_int_eq(s21_create_matrix(3, 3, &B), OK);
  ck_assert_int_eq(s21_create_matrix(3, 3, &res), OK);

  fill_matrix(&A, 0);
  fill_matrix(&B, 0);
  set_matrix(&res, 30.0, 36.0, 42.0, 66.0, 81.0, 96.0, 102.0, 126.0, 150.0);
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &C), OK);
  ck_assert_int_eq(s21_eq_matrix(&C, &res), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(mult_2) {
  matrix_t A, B, C, res;
  ck_assert_int_eq(s21_create_matrix(3, 2, &A), OK);
  ck_assert_int_eq(s21_create_matrix(2, 3, &B), OK);
  ck_assert_int_eq(s21_create_matrix(3, 3, &res), OK);

  set_matrix(&res, 9.0, 11.0, 17.0, 12.0, 13.0, 22.0, 15.0, 15.0, 27.0);
  set_matrix(&A, 1.0, 4.0, 2.0, 5.0, 3.0, 6.0);
  set_matrix(&B, 1.0, -1.0, 1.0, 2.0, 3.0, 4.0);
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &C), OK);
  ck_assert_int_eq(s21_eq_matrix(&C, &res), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(mult_3) {
  matrix_t A, B, C, res;
  ck_assert_int_eq(s21_create_matrix(2, 2, &A), OK);
  ck_assert_int_eq(s21_create_matrix(2, 2, &B), OK);
  ck_assert_int_eq(s21_create_matrix(2, 2, &res), OK);

  set_matrix(&res, 1.0, 0.0, 0.0, 1.0);
  set_matrix(&A, 1.0, 2.0, -1.0, 0.0);
  set_matrix(&B, 0.0, -1.0, 0.5, 0.5);
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &C), OK);
  ck_assert_int_eq(s21_eq_matrix(&C, &res), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(mult_4) {
  matrix_t A, B, C, res;
  ck_assert_int_eq(s21_create_matrix(3, 3, &A), OK);
  ck_assert_int_eq(s21_create_matrix(3, 3, &B), OK);
  ck_assert_int_eq(s21_create_matrix(3, 3, &res), OK);

  set_matrix(&res, 54.00882, 50.008085, 46.00735, -1453.05, -1333.38, -1213.71,
             4461.0, 4088.5, 3716.0);
  set_matrix(&A, 3.0, 0.000735, 1.0, 0.33, -126.0, 6.0, 0.0, 369.5, 3.0);
  set_matrix(&B, 15.0, 14.0, 13.0, 12.0, 11.0, 10.0, 9.0, 8.0, 7.0);
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &C), OK);
  ck_assert_int_eq(s21_eq_matrix(&C, &res), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(mult_5) {
  matrix_t A, B, C;
  ck_assert_int_eq(s21_create_matrix(2, 3, &A), OK);
  ck_assert_int_eq(s21_create_matrix(2, 3, &B), OK);

  ck_assert_int_eq(s21_mult_matrix(&A, &B, &C), CALCULATION_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite* test_mult() {
  Suite* s = suite_create("\033[45mS21_MULT_MATRIX\033[0m");
  TCase* tc = tcase_create("mult");

  tcase_add_test(tc, mult_1);
  tcase_add_test(tc, mult_2);
  tcase_add_test(tc, mult_3);
  tcase_add_test(tc, mult_4);
  tcase_add_test(tc, mult_5);

  suite_add_tcase(s, tc);
  return s;
}