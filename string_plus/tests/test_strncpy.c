#include "tests.h"

START_TEST(strncpy_1) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello, world!";
  char str3[] = "Good";
  ck_assert_str_eq(strncpy(str1, str3, 5), s21_strncpy(str2, str3, 5));
}
END_TEST

START_TEST(strncpy_2) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello, world!";
  char str3[] = "dfdfd";
  ck_assert_str_eq(strncpy(str1, str3, 1), s21_strncpy(str2, str3, 1));
}
END_TEST

START_TEST(strncpy_3) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello, world!";
  char str3[] = "fРі-Р°Рі-Р°Рі";
  ck_assert_str_eq(strncpy(str1, str3, 1), s21_strncpy(str2, str3, 1));
}
END_TEST

START_TEST(strncpy_4) {
  char str1[] = "";
  char str2[] = "";
  char str3[] = "";
  ck_assert_str_eq(strncpy(str1, str3, 1), s21_strncpy(str2, str3, 1));
}
END_TEST

START_TEST(strncpy_5) {
  char s1[70] = "";
  char s2[70] = "";
  char s3[] = "asdasdasdasdasdasdasdasdasdaasdasdasd";
  s21_size_t n = strlen(s3);
  ck_assert_str_eq(strncpy(s1, s3, n), s21_strncpy(s2, s3, n));
}
END_TEST

START_TEST(strncpy_6) {
  char s1[5] = "";
  char s2[5] = "";
  char s3[] = "\0";
  ck_assert_str_eq(strncpy(s1, s3, 1), s21_strncpy(s2, s3, 1));
}
END_TEST

START_TEST(strncpy_7) {
  char s1[] = "abcdef";
  char s2[] = "abcdef";
  char s3[] = "hi";
  ck_assert_str_eq(strncpy(s1, s3, 5), s21_strncpy(s2, s3, 5));
}
END_TEST

START_TEST(strncpy_8) {
  char s1[] = "abcd";
  char s2[] = "abcd";
  char s3[] = "hihi";
  ck_assert_str_eq(strncpy(s1, s3, 2), s21_strncpy(s2, s3, 2));
}
END_TEST

Suite *test_strncpy(void) {
  Suite *s = suite_create("\033[45mS21_STRNCPY\033[0m");
  TCase *tc = tcase_create("strncpy");
  tcase_add_test(tc, strncpy_1);
  tcase_add_test(tc, strncpy_2);
  tcase_add_test(tc, strncpy_3);
  tcase_add_test(tc, strncpy_4);
  tcase_add_test(tc, strncpy_5);
  tcase_add_test(tc, strncpy_6);
  tcase_add_test(tc, strncpy_7);
  tcase_add_test(tc, strncpy_8);
  suite_add_tcase(s, tc);
  return s;
}