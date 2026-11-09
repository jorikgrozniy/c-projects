#include "tests.h"

START_TEST(strncmp_1) {
  char str1[] = "abc";
  char str2[] = "abc";
  int n = 3;
  int s21 = s21_strncmp(str1, str2, n);
  int s00 = strncmp(str1, str2, n);
  ck_assert_int_eq(s21, s00);
}
END_TEST

START_TEST(strncmp_2) {
  char str1[] = "Abc";
  char str2[] = "abc";
  int n = 3;
  int s21 = s21_strncmp(str1, str2, n);
  int s00 = strncmp(str1, str2, n);
  ck_assert_int_eq(s21, s00);
}
END_TEST

START_TEST(strncmp_3) {
  char str1[] = "abc";
  char str2[] = "Abc";
  int n = 3;
  int s21 = s21_strncmp(str1, str2, n);
  int s00 = strncmp(str1, str2, n);
  ck_assert_int_eq(s21, s00);
}
END_TEST

START_TEST(strncmp_4) {
  char str1[] = "abC";
  char str2[] = "abc";
  int n = 3;
  int s21 = s21_strncmp(str1, str2, n);
  int s00 = strncmp(str1, str2, n);
  ck_assert_int_eq(s21, s00);
}
END_TEST

START_TEST(strncmp_5) {
  char str1[] = "abc";
  char str2[] = "abC";
  int n = 3;
  int s21 = s21_strncmp(str1, str2, n);
  int s00 = strncmp(str1, str2, n);
  ck_assert_int_eq(s21, s00);
}
END_TEST

START_TEST(strncmp_6) {
  char str1[] = "ABC";
  char str2[] = "abc";
  int n = 3;
  int s21 = s21_strncmp(str1, str2, n);
  int s00 = strncmp(str1, str2, n);
  ck_assert_int_eq(s21, s00);
}
END_TEST

START_TEST(strncmp_7) {
  char str1[] = "abc";
  char str2[] = "ABC";
  int n = 3;
  int s21 = s21_strncmp(str1, str2, n);
  int s00 = strncmp(str1, str2, n);
  ck_assert_int_eq(s21, s00);
}
END_TEST

START_TEST(strncmp_8) {
  char str1[] = "a b c";
  char str2[] = "abc";
  int n = 3;
  int s21 = s21_strncmp(str1, str2, n);
  int s00 = strncmp(str1, str2, n);
  ck_assert_int_eq(s21, s00);
}
END_TEST

START_TEST(strncmp_9) {
  char str1[] = "abc";
  char str2[] = "a b c";
  int n = 3;
  int s21 = s21_strncmp(str1, str2, n);
  int s00 = strncmp(str1, str2, n);
  ck_assert_int_eq(s21, s00);
}
END_TEST

START_TEST(strncmp_10) {
  char str1[] = "";
  char str2[] = "abc";
  int n = 3;
  int s21 = s21_strncmp(str1, str2, n);
  int s00 = strncmp(str1, str2, n);
  ck_assert_int_eq(s21, s00);
}
END_TEST

START_TEST(strncmp_11) {
  char str1[] = "abc";
  char str2[] = "";
  int n = 3;
  int s21 = s21_strncmp(str1, str2, n);
  int s00 = strncmp(str1, str2, n);
  ck_assert_int_eq(s21, s00);
}
END_TEST

START_TEST(strncmp_12) {
  char str1[] = " ";
  char str2[] = "abc";
  int n = 3;
  int s21 = s21_strncmp(str1, str2, n);
  int s00 = strncmp(str1, str2, n);
  ck_assert_int_eq(s21, s00);
}
END_TEST

START_TEST(strncmp_13) {
  char str1[] = "abc";
  char str2[] = " ";
  int n = 3;
  int s21 = s21_strncmp(str1, str2, n);
  int s00 = strncmp(str1, str2, n);
  ck_assert_int_eq(s21, s00);
}
END_TEST

START_TEST(strncmp_14) {
  char str1[] = "9087";
  char str2[] = "657";
  int n = 3;
  int s21 = s21_strncmp(str1, str2, n);
  int s00 = strncmp(str1, str2, n);
  ck_assert_int_eq(s21, s00);
}
END_TEST

START_TEST(strncmp_17) {
  char str1[] = "abc ";
  char str2[] = "abc";
  int n = 3;
  int s21 = s21_strncmp(str1, str2, n);
  int s00 = strncmp(str1, str2, n);
  ck_assert_int_eq(s21, s00);
}
END_TEST

START_TEST(strncmp_18) {
  char str1[] = "abc";
  char str2[] = "abc ";
  int n = 3;
  int s21 = s21_strncmp(str1, str2, n);
  int s00 = strncmp(str1, str2, n);
  ck_assert_int_eq(s21, s00);
}
END_TEST

START_TEST(strncmp_19) {
  char str1[] = " abc";
  char str2[] = "abc";
  int n = 3;
  int s21 = s21_strncmp(str1, str2, n);
  int s00 = strncmp(str1, str2, n);
  ck_assert_int_eq(s21, s00);
}
END_TEST

START_TEST(strncmp_20) {
  char str1[] = "abc";
  char str2[] = " abc";
  int n = 3;
  int s21 = s21_strncmp(str1, str2, n);
  int s00 = strncmp(str1, str2, n);
  ck_assert_int_eq(s21, s00);
}
END_TEST

START_TEST(strncmp_21) {
  char str1[] = "123";
  char str2[] = "123";
  int n = 3;
  int s21 = s21_strncmp(str1, str2, n);
  int s00 = strncmp(str1, str2, n);
  ck_assert_int_eq(s21, s00);
}
END_TEST

START_TEST(strncmp_22) {
  char str1[] = "123";
  char str2[] = "321";
  int n = 3;
  int s21 = s21_strncmp(str1, str2, n);
  int s00 = strncmp(str1, str2, n);
  ck_assert_int_eq(s21, s00);
}
END_TEST

START_TEST(strncmp_23) {
  char str1[] = "321";
  char str2[] = "321";
  int n = 3;
  int s21 = s21_strncmp(str1, str2, n);
  int s00 = strncmp(str1, str2, n);
  ck_assert_int_eq(s21, s00);
}
END_TEST

START_TEST(strncmp_24) {
  char str1[] = "321";
  char str2[] = "123";
  int n = 3;
  int s21 = s21_strncmp(str1, str2, n);
  int s00 = strncmp(str1, str2, n);
  ck_assert_int_eq(s21, s00);
}
END_TEST

START_TEST(strncmp_25) {
  char str1[] = "1234";
  char str2[] = "123";
  int n = 3;
  int s21 = s21_strncmp(str1, str2, n);
  int s00 = strncmp(str1, str2, n);
  ck_assert_int_eq(s21, s00);
}
END_TEST

START_TEST(strncmp_26) {
  char str1[] = "132";
  char str2[] = "1234";
  int n = 3;
  int s21 = s21_strncmp(str1, str2, n);
  int s00 = strncmp(str1, str2, n);
  ck_assert_int_eq(s21, s00);
}
END_TEST

START_TEST(strncmp_27) {
  char str1[] = "abcd";
  char str2[] = "abc";
  int n = 3;
  int s21 = s21_strncmp(str1, str2, n);
  int s00 = strncmp(str1, str2, n);
  ck_assert_int_eq(s21, s00);
}
END_TEST

START_TEST(strncmp_28) {
  char str1[] = "abc";
  char str2[] = "abcd";
  int n = 3;
  int s21 = s21_strncmp(str1, str2, n);
  int s00 = strncmp(str1, str2, n);
  ck_assert_int_eq(s21, s00);
}
END_TEST

START_TEST(strncmp_29) {
  char str1[] = "12ab";
  char str2[] = "12ab";
  int n = 3;
  int s21 = s21_strncmp(str1, str2, n);
  int s00 = strncmp(str1, str2, n);
  ck_assert_int_eq(s21, s00);
}
END_TEST

START_TEST(strncmp_30) {
  char str1[] = "ab12";
  char str2[] = "12ab";
  int n = 3;
  int s21 = s21_strncmp(str1, str2, n);
  int s00 = strncmp(str1, str2, n);
  ck_assert_int_eq(s21, s00);
}
END_TEST

START_TEST(strncmp_50) {
  char str1[] = "abc";
  char str2[] = " abc";
  int n = 0;
  int s21 = s21_strncmp(str1, str2, n);
  int s00 = strncmp(str1, str2, n);
  ck_assert_int_eq(s21, s00);
}
END_TEST

START_TEST(strncmp_51) {
  char str1[] = "123";
  char str2[] = "123";
  int n = 0;
  int s21 = s21_strncmp(str1, str2, n);
  int s00 = strncmp(str1, str2, n);
  ck_assert_int_eq(s21, s00);
}
END_TEST

START_TEST(strncmp_52) {
  char str1[] = "123";
  char str2[] = "321";
  int n = 0;
  int s21 = s21_strncmp(str1, str2, n);
  int s00 = strncmp(str1, str2, n);
  ck_assert_int_eq(s21, s00);
}
END_TEST

START_TEST(strncmp_53) {
  char str1[] = "321";
  char str2[] = "321";
  int n = 0;
  int s21 = s21_strncmp(str1, str2, n);
  int s00 = strncmp(str1, str2, n);
  ck_assert_int_eq(s21, s00);
}
END_TEST

START_TEST(strncmp_54) {
  char str1[] = "321";
  char str2[] = "123";
  int n = 0;
  int s21 = s21_strncmp(str1, str2, n);
  int s00 = strncmp(str1, str2, n);
  ck_assert_int_eq(s21, s00);
}
END_TEST

START_TEST(strncmp_55) {
  char str1[] = "1234";
  char str2[] = "123";
  int n = 0;
  int s21 = s21_strncmp(str1, str2, n);
  int s00 = strncmp(str1, str2, n);
  ck_assert_int_eq(s21, s00);
}
END_TEST

START_TEST(strncmp_56) {
  char str1[] = "132";
  char str2[] = "1234";
  int n = 0;
  int s21 = s21_strncmp(str1, str2, n);
  int s00 = strncmp(str1, str2, n);
  ck_assert_int_eq(s21, s00);
}
END_TEST

START_TEST(strncmp_57) {
  char str1[] = "abcd";
  char str2[] = "abc";
  int n = 0;
  int s21 = s21_strncmp(str1, str2, n);
  int s00 = strncmp(str1, str2, n);
  ck_assert_int_eq(s21, s00);
}
END_TEST

START_TEST(strncmp_58) {
  char str1[] = "abc";
  char str2[] = "abcd";
  int n = 0;
  int s21 = s21_strncmp(str1, str2, n);
  int s00 = strncmp(str1, str2, n);
  ck_assert_int_eq(s21, s00);
}
END_TEST

START_TEST(strncmp_59) {
  char str1[] = "12ab";
  char str2[] = "12ab";
  int n = 0;
  int s21 = s21_strncmp(str1, str2, n);
  int s00 = strncmp(str1, str2, n);
  ck_assert_int_eq(s21, s00);
}
END_TEST

START_TEST(strncmp_60) {
  char str1[] = "ab12";
  char str2[] = "12ab";
  int n = 0;
  int s21 = s21_strncmp(str1, str2, n);
  int s00 = strncmp(str1, str2, n);
  ck_assert_int_eq(s21, s00);
}
END_TEST

Suite *test_strncmp(void) {
  Suite *s1 = suite_create("\033[45mS21_STRNCMP\033[0m");
  TCase *tc1_1 = tcase_create("strncmp");
  tcase_add_test(tc1_1, strncmp_1);
  tcase_add_test(tc1_1, strncmp_2);
  tcase_add_test(tc1_1, strncmp_3);
  tcase_add_test(tc1_1, strncmp_4);
  tcase_add_test(tc1_1, strncmp_5);
  tcase_add_test(tc1_1, strncmp_6);
  tcase_add_test(tc1_1, strncmp_7);
  tcase_add_test(tc1_1, strncmp_8);
  tcase_add_test(tc1_1, strncmp_9);
  tcase_add_test(tc1_1, strncmp_10);
  tcase_add_test(tc1_1, strncmp_11);
  tcase_add_test(tc1_1, strncmp_12);
  tcase_add_test(tc1_1, strncmp_13);
  tcase_add_test(tc1_1, strncmp_14);

  tcase_add_test(tc1_1, strncmp_17);
  tcase_add_test(tc1_1, strncmp_18);
  tcase_add_test(tc1_1, strncmp_19);
  tcase_add_test(tc1_1, strncmp_20);
  tcase_add_test(tc1_1, strncmp_21);
  tcase_add_test(tc1_1, strncmp_22);
  tcase_add_test(tc1_1, strncmp_23);
  tcase_add_test(tc1_1, strncmp_24);
  tcase_add_test(tc1_1, strncmp_25);
  tcase_add_test(tc1_1, strncmp_26);
  tcase_add_test(tc1_1, strncmp_27);
  tcase_add_test(tc1_1, strncmp_28);
  tcase_add_test(tc1_1, strncmp_29);
  tcase_add_test(tc1_1, strncmp_30);

  tcase_add_test(tc1_1, strncmp_50);
  tcase_add_test(tc1_1, strncmp_51);
  tcase_add_test(tc1_1, strncmp_52);
  tcase_add_test(tc1_1, strncmp_53);
  tcase_add_test(tc1_1, strncmp_54);
  tcase_add_test(tc1_1, strncmp_55);
  tcase_add_test(tc1_1, strncmp_56);
  tcase_add_test(tc1_1, strncmp_57);
  tcase_add_test(tc1_1, strncmp_58);
  tcase_add_test(tc1_1, strncmp_59);
  tcase_add_test(tc1_1, strncmp_60);

  suite_add_tcase(s1, tc1_1);
  return s1;
}