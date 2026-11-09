#include "test.h"

START_TEST(eq_1) {
  matrix_t A, B;
  ck_assert_int_eq(s21_create_matrix(3, 3, &A), OK);
  ck_assert_int_eq(s21_create_matrix(3, 3, &B), OK);
  fill_matrix(&A, 0);
  fill_matrix(&B, 0);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_2) {
  matrix_t A, B;
  ck_assert_int_eq(s21_create_matrix(3, 3, &A), OK);
  ck_assert_int_eq(s21_create_matrix(3, 3, &B), OK);
  fill_matrix(&A, 0);
  fill_matrix(&B, 1);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_3) {
  matrix_t A, B;
  ck_assert_int_eq(s21_create_matrix(3, 3, &A), OK);
  ck_assert_int_eq(s21_create_matrix(2, 2, &B), OK);
  fill_matrix(&A, 1);
  fill_matrix(&B, 1);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_4) {
  matrix_t A, B;
  ck_assert_int_eq(s21_create_matrix(2, 2, &A), OK);
  ck_assert_int_eq(s21_create_matrix(1, 4, &B), OK);
  fill_matrix(&A, 0);
  fill_matrix(&B, 0);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_5) {
  matrix_t A, B;
  ck_assert_int_eq(s21_create_matrix(2, 2, &A), OK);
  ck_assert_int_eq(s21_create_matrix(2, 2, &B), OK);
  fill_matrix(&A, 0);
  fill_matrix(&B, 0);
  A.matrix[1][0] = 7.936473999;
  B.matrix[1][0] = 7.936473777;
  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_6) {
  matrix_t A, B;
  ck_assert_int_eq(s21_create_matrix(2, 2, &A), OK);
  ck_assert_int_eq(s21_create_matrix(2, 2, &B), OK);
  fill_matrix(&A, 0);
  fill_matrix(&B, 0);
  A.matrix[1][0] = 7.936473999;
  B.matrix[1][0] = 7.936475999;
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite* test_eq() {
  Suite* s = suite_create("\033[45mS21_EQ_MATRIX\033[0m");
  TCase* tc = tcase_create("eq");

  tcase_add_test(tc, eq_1);
  tcase_add_test(tc, eq_2);
  tcase_add_test(tc, eq_3);
  tcase_add_test(tc, eq_4);
  tcase_add_test(tc, eq_5);
  tcase_add_test(tc, eq_6);

  suite_add_tcase(s, tc);
  return s;
}