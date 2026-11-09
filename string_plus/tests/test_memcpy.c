#include "tests.h"

START_TEST(memcpy_1) {
  char str1[9] = "abc";
  char str2[] = "def";
  char str3[9] = "abc";
  s21_size_t n = 1;
  ck_assert_str_eq(memcpy(str1, str2, n), s21_memcpy(str3, str2, n));
}
END_TEST

START_TEST(memcpy_2) {
  char str1[9] = "ab\nc";
  char str2[] = "def";
  char str3[9] = "ab\nc";
  int n = 1;
  ck_assert_str_eq(memcpy(str1, str2, n), s21_memcpy(str3, str2, n));
}
END_TEST

START_TEST(memcpy_3) {
  char str1[9] = "ab\0c";
  char str2[] = "def";
  char str3[9] = "ab\0c";
  int n = 1;
  ck_assert_str_eq(memcpy(str1, str2, n), s21_memcpy(str3, str2, n));
}
END_TEST

START_TEST(memcpy_4) {
  char str1[9] = "abc";
  char str2[] = "de\0f";
  char str3[9] = "abc";
  int n = 1;
  ck_assert_str_eq(memcpy(str1, str2, n), s21_memcpy(str3, str2, n));
}
END_TEST

START_TEST(memcpy_5) {
  char str1[9] = "abc";
  char str2[] = "de\nf";
  char str3[9] = "abc";
  int n = 1;
  ck_assert_str_eq(memcpy(str1, str2, n), s21_memcpy(str3, str2, n));
}
END_TEST

START_TEST(memcpy_6) {
  char str1[9] = "ab\0c";
  char str2[] = "def";
  char str3[9] = "ab\0c";
  int n = 4;
  ck_assert_str_eq(memcpy(str1, str2, n), s21_memcpy(str3, str2, n));
}
END_TEST

START_TEST(memcpy_7) {
  char str1[9] = "abc";
  char str2[] = "de\0f";
  char str3[9] = "abc";
  int n = 4;
  ck_assert_str_eq(memcpy(str1, str2, n), s21_memcpy(str3, str2, n));
}
END_TEST

START_TEST(memcpy_8) {
  char str1[9] = "";
  char str2[] = "def";
  char str3[9] = "";
  int n = 3;
  memcpy(str1, str2, n);
  s21_memcpy(str3, str2, n);
  ck_assert_str_eq(str1, str3);
}
END_TEST

START_TEST(memcpy_9) {
  char str1[9] = "abc";
  char str2[] = "";
  char str3[9] = "abc";
  int n = 1;
  ck_assert_str_eq(memcpy(str1, str2, n), s21_memcpy(str3, str2, n));
}
END_TEST

START_TEST(memcpy_10) {
  char str1[9] = "abc";
  char str2[] = "def";
  char str3[9] = "abc";
  int n = 1;
  ck_assert_str_eq(memcpy(str1, str2, n), s21_memcpy(str3, str2, n));
}
END_TEST

START_TEST(memcpy_11) {
  char str1[9] = "abc";
  char str2[] = "def";
  char str3[9] = "abc";
  int n = 1;
  ck_assert_str_eq(memcpy(str1, str2, n), s21_memcpy(str3, str2, n));
}
END_TEST

START_TEST(memcpy_12) {
  char str1[9] = "ab\nc";
  char str2[] = "def";
  char str3[9] = "ab\nc";
  int n = 4;
  ck_assert_str_eq(memcpy(str1, str2, n), s21_memcpy(str3, str2, n));
}
END_TEST

START_TEST(memcpy_13) {
  char str1[9] = "ab\0c";
  char str2[] = "def";
  char str3[9] = "ab\0c";
  int n = 0;
  ck_assert_str_eq(memcpy(str1, str2, n), s21_memcpy(str3, str2, n));
}
END_TEST

START_TEST(memcpy_14) {
  char str1[9] = "abc";
  char str2[] = "de\0f";
  char str3[9] = "abc";
  int n = 0;
  ck_assert_str_eq(memcpy(str1, str2, n), s21_memcpy(str3, str2, n));
}
END_TEST

START_TEST(memcpy_15) {
  char str1[9] = "abc";
  char str2[] = "de\nf";
  char str3[9] = "abc";
  int n = 0;
  ck_assert_str_eq(memcpy(str1, str2, n), s21_memcpy(str3, str2, n));
}
END_TEST

START_TEST(memcpy_16) {
  char str1[9] = "ab\0c";
  char str2[] = "def";
  char str3[9] = "ab\0c";
  int n = 4;
  ck_assert_str_eq(memcpy(str1, str2, n), s21_memcpy(str3, str2, n));
}
END_TEST

START_TEST(memcpy_17) {
  char str1[9] = "abc";
  char str2[] = "de\0f";
  char str3[9] = "ab\0c";
  int n = 3;
  ck_assert_str_eq(memcpy(str1, str2, n), s21_memcpy(str3, str2, n));
}
END_TEST

START_TEST(memcpy_18) {
  char str1[9] = "";
  char str2[] = "def";
  char str3[9] = "";
  int n = 1;
  ck_assert_str_eq(memcpy(str1, str2, n), s21_memcpy(str3, str2, n));
}
END_TEST

START_TEST(memcpy_19) {
  char str1[9] = "";
  char str2[] = "";
  char str3[9] = "";
  int n = 1;
  ck_assert_str_eq(memcpy(str1, str2, n), s21_memcpy(str3, str2, n));
}
END_TEST

START_TEST(memcpy_20) {
  char str1[9] = " ";
  char str2[] = " ";
  char str3[9] = " ";
  int n = 0;
  ck_assert_str_eq(memcpy(str1, str2, n), s21_memcpy(str3, str2, n));
}
END_TEST

Suite *test_memcpy(void) {
  Suite *s1 = suite_create("\033[45mS21_MEMCPY\033[0m");
  TCase *tc1_1 = tcase_create("memcpy_tc");

  tcase_add_test(tc1_1, memcpy_1);
  tcase_add_test(tc1_1, memcpy_2);
  tcase_add_test(tc1_1, memcpy_3);
  tcase_add_test(tc1_1, memcpy_4);
  tcase_add_test(tc1_1, memcpy_5);
  tcase_add_test(tc1_1, memcpy_6);
  tcase_add_test(tc1_1, memcpy_7);
  tcase_add_test(tc1_1, memcpy_8);
  tcase_add_test(tc1_1, memcpy_9);
  tcase_add_test(tc1_1, memcpy_10);
  tcase_add_test(tc1_1, memcpy_11);
  tcase_add_test(tc1_1, memcpy_12);
  tcase_add_test(tc1_1, memcpy_13);
  tcase_add_test(tc1_1, memcpy_14);
  tcase_add_test(tc1_1, memcpy_15);
  tcase_add_test(tc1_1, memcpy_16);
  tcase_add_test(tc1_1, memcpy_17);
  tcase_add_test(tc1_1, memcpy_18);
  tcase_add_test(tc1_1, memcpy_19);
  tcase_add_test(tc1_1, memcpy_20);

  suite_add_tcase(s1, tc1_1);
  return s1;
}