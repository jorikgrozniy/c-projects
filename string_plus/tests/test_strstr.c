#include "tests.h"

START_TEST(strstr_1) {
  const char *haystack = "abcdefg";
  const char *needle = "cde";
  ck_assert_ptr_eq(strstr(haystack, needle), s21_strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_2) {
  const char *haystack = "";
  const char *needle = "abc";
  ck_assert_ptr_eq(strstr(haystack, needle), s21_strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_3) {
  const char *haystack = "abcdefg";
  const char *needle = "";
  ck_assert_ptr_eq(strstr(haystack, needle), s21_strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_4) {
  const char *haystack = "abcdefghi";
  const char *needle = "def";
  ck_assert_ptr_eq(strstr(haystack, needle), s21_strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_5) {
  const char *haystack = "abc";
  const char *needle = "abc";
  ck_assert_ptr_eq(strstr(haystack, needle), s21_strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_6) {
  const char *haystack = "abababab";
  const char *needle = "ab";
  ck_assert_ptr_eq(strstr(haystack, needle), s21_strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_7) {
  const char *haystack = "abcdefg";
  const char *needle = "abc";
  ck_assert_ptr_eq(strstr(haystack, needle), s21_strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_8) {
  const char *haystack = "abcdefg";
  const char *needle = "efg";
  ck_assert_ptr_eq(strstr(haystack, needle), s21_strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_9) {
  const char *haystack = "abcdefg";
  const char *needle = "xyz";
  ck_assert_ptr_eq(strstr(haystack, needle), s21_strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_10) {
  const char *haystack = "abc";
  const char *needle = "abcdefghi";
  ck_assert_ptr_eq(strstr(haystack, needle), s21_strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_11) {
  const char *haystack = "";
  const char *needle = "";
  ck_assert_ptr_eq(strstr(haystack, needle), s21_strstr(haystack, needle));
}
END_TEST

Suite *test_strstr(void) {
  Suite *s = suite_create("\033[45mS21_STRSTR\033[0m");
  TCase *tc = tcase_create("strstr");

  tcase_add_test(tc, strstr_1);
  tcase_add_test(tc, strstr_2);
  tcase_add_test(tc, strstr_3);
  tcase_add_test(tc, strstr_4);
  tcase_add_test(tc, strstr_5);
  tcase_add_test(tc, strstr_6);
  tcase_add_test(tc, strstr_7);
  tcase_add_test(tc, strstr_8);
  tcase_add_test(tc, strstr_9);
  tcase_add_test(tc, strstr_10);
  tcase_add_test(tc, strstr_11);

  suite_add_tcase(s, tc);
  return s;
}