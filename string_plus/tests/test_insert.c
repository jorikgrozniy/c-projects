#include "tests.h"

START_TEST(s21_insert_1) {
  char str1[] = "abc";
  char str2[] = "def";
  int n = 3;
  char *str3 = s21_insert(str1, str2, n);
  ck_assert_str_eq(str3, "abcdef");
  free(str3);
}
END_TEST

START_TEST(s21_insert_2) {
  char str1[] = "abc";
  char str2[] = "def";
  int n = 2;
  char *str3 = s21_insert(str1, str2, n);
  ck_assert_str_eq(str3, "abdefc");
  free(str3);
}
END_TEST

START_TEST(s21_insert_3) {
  char str1[] = "abc";
  char str2[] = "def";
  int n = 1;
  char *str3 = s21_insert(str1, str2, n);
  ck_assert_str_eq(str3, "adefbc");
  free(str3);
}
END_TEST

START_TEST(s21_insert_4) {
  char str1[] = "abc";
  char str2[] = "def";
  int n = 0;
  char *str3 = s21_insert(str1, str2, n);
  ck_assert_str_eq(str3, "defabc");
  free(str3);
}
END_TEST

START_TEST(s21_insert_5) {
  char str1[] = "abcdefghijkl123456789";
  char str2[] = "xyz";
  int n = 5;
  char *str3 = s21_insert(str1, str2, n);
  ck_assert_str_eq(str3, "abcdexyzfghijkl123456789");
  free(str3);
}
END_TEST

START_TEST(s21_insert_6) {
  char str1[] = "abc";
  char str2[] = "";
  int n = 0;
  char *str3 = s21_insert(str1, str2, n);
  ck_assert_str_eq(str3, "abc");
  free(str3);
}
END_TEST

START_TEST(s21_insert_7) {
  char str1[] = "abc";
  char str2[] = "";
  int n = 1;
  char *str3 = s21_insert(str1, str2, n);
  ck_assert_str_eq(str3, "abc");
  free(str3);
}
END_TEST

START_TEST(s21_insert_8) {
  char str1[] = "abc";
  char str2[] = "";
  int n = 3;
  char *str3 = s21_insert(str1, str2, n);
  ck_assert_str_eq(str3, "abc");
  free(str3);
}
END_TEST

START_TEST(s21_insert_9) {
  char str1[] = "";
  char str2[] = "abc";
  int n = 1;
  char *str3 = s21_insert(str1, str2, n);
  ck_assert_pstr_eq(str3, S21_NULL);
  free(str3);
}
END_TEST

START_TEST(s21_insert_10) {
  char str1[] = "";
  char str2[] = "abc";
  int n = 0;
  char *str3 = s21_insert(str1, str2, n);
  ck_assert_str_eq(str3, "abc");
  free(str3);
}
END_TEST

START_TEST(s21_insert_11) {
  char str1[] = "";
  char str2[] = "abc";
  int n = 3;
  char *str3 = s21_insert(str1, str2, n);
  ck_assert_pstr_eq(str3, S21_NULL);
  free(str3);
}
END_TEST

START_TEST(s21_insert_12) {
  char str1[] = "";
  char str2[] = "";
  int n = 3;
  char *str3 = s21_insert(str1, str2, n);
  ck_assert_pstr_eq(str3, S21_NULL);
  free(str3);
}
END_TEST

START_TEST(s21_insert_13) {
  char str1[] = "";
  char str2[] = "";
  int n = 0;
  char *str3 = s21_insert(str1, str2, n);
  ck_assert_str_eq(str3, "");
  free(str3);
}
END_TEST

Suite *test_insert(void) {
  Suite *s1;
  TCase *tc1_1;
  s1 = suite_create("\033[45mS21_INSERT\033[0m");
  tc1_1 = tcase_create("Core");

  tcase_add_test(tc1_1, s21_insert_1);
  tcase_add_test(tc1_1, s21_insert_2);
  tcase_add_test(tc1_1, s21_insert_3);
  tcase_add_test(tc1_1, s21_insert_4);
  tcase_add_test(tc1_1, s21_insert_5);
  tcase_add_test(tc1_1, s21_insert_6);
  tcase_add_test(tc1_1, s21_insert_7);
  tcase_add_test(tc1_1, s21_insert_8);
  tcase_add_test(tc1_1, s21_insert_9);
  tcase_add_test(tc1_1, s21_insert_10);
  tcase_add_test(tc1_1, s21_insert_11);
  tcase_add_test(tc1_1, s21_insert_12);
  tcase_add_test(tc1_1, s21_insert_13);
  suite_add_tcase(s1, tc1_1);
  return s1;
}
