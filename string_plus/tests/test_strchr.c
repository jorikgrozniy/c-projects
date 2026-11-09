#include "tests.h"

START_TEST(strchr_1) {
  const char *str = "";
  int c = 'a';
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(strchr_2) {
  const char *str = "Hello, World!";
  int c = 'e';
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(strchr_3) {
  const char *str = "Hello, World!";
  int c = 'x';
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(strchr_5) {
  const char *str = "Hello, World!";
  int c = ' ';
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(strchr_6) {
  const char *str = "Hello, World!";
  int c = 'l';
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(strchr_7) {
  const char *str = "Hello, World!";
  int c = 'd';
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(strchr_8) {
  const char *str = "Hello, World!";
  int c = 'o';
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(strchr_9) {
  const char *str = "Hello, World!";
  int c = 'H';
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(strchr_10) {
  const char *str = "Hello, World!";
  int c = '!';
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

Suite *test_strchr(void) {
  Suite *s = suite_create("\033[45mS21_STRCHR\033[0m");
  TCase *tc = tcase_create("strchr");

  tcase_add_test(tc, strchr_1);
  tcase_add_test(tc, strchr_2);
  tcase_add_test(tc, strchr_3);
  tcase_add_test(tc, strchr_5);
  tcase_add_test(tc, strchr_6);
  tcase_add_test(tc, strchr_7);
  tcase_add_test(tc, strchr_8);
  tcase_add_test(tc, strchr_9);
  tcase_add_test(tc, strchr_10);
  suite_add_tcase(s, tc);
  return s;
}