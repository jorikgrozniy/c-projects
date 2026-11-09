#include "tests.h"

START_TEST(strcspn_1) {
  char str1[] = "abc";
  char str2[] = "abc";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_2) {
  char str1[] = "Abc";
  char str2[] = "abc";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_3) {
  char str1[] = "abc";
  char str2[] = "Abc";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_4) {
  char str1[] = "abC";
  char str2[] = "abc";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_5) {
  char str1[] = "abc";
  char str2[] = "abC";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_6) {
  char str1[] = "ABC";
  char str2[] = "abc";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_7) {
  char str1[] = "abc";
  char str2[] = "ABC";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_8) {
  char str1[] = "a b c";
  char str2[] = "abc";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_9) {
  char str1[] = "abc";
  char str2[] = "a b c";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_10) {
  char str1[] = "";
  char str2[] = "abc";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_11) {
  char str1[] = "abc";
  char str2[] = "";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_12) {
  char str1[] = " ";
  char str2[] = "abc";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_13) {
  char str1[] = "abc";
  char str2[] = " ";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_14) {
  char str1[] = "9087";
  char str2[] = "657";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_15) {
  char str1[] = "";
  char str2[] = "";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_16) {
  char str1[] = " ";
  char str2[] = " ";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_17) {
  char str1[] = "abc ";
  char str2[] = "abc";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_18) {
  char str1[] = "abc";
  char str2[] = "abc ";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_19) {
  char str1[] = " abc";
  char str2[] = "abc";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_20) {
  char str1[] = "abc";
  char str2[] = " abc";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_21) {
  char str1[] = "123";
  char str2[] = "123";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_22) {
  char str1[] = "123";
  char str2[] = "321";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_23) {
  char str1[] = "321";
  char str2[] = "321";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_24) {
  char str1[] = "321";
  char str2[] = "123";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_25) {
  char str1[] = "1234";
  char str2[] = "123";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_26) {
  char str1[] = "132";
  char str2[] = "1234";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_27) {
  char str1[] = "abcd";
  char str2[] = "abc";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_28) {
  char str1[] = "abc";
  char str2[] = "abcd";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_29) {
  char str1[] = "12ab";
  char str2[] = "12ab";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_30) {
  char str1[] = "ab12";
  char str2[] = "12ab";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

Suite *test_strcspn(void) {
  Suite *s1 = suite_create("\033[45mS21_STRCSPN\033[0m");
  TCase *tc1_1 = tcase_create("strcspn_tc");

  tcase_add_test(tc1_1, strcspn_1);
  tcase_add_test(tc1_1, strcspn_2);
  tcase_add_test(tc1_1, strcspn_3);
  tcase_add_test(tc1_1, strcspn_4);
  tcase_add_test(tc1_1, strcspn_5);
  tcase_add_test(tc1_1, strcspn_6);
  tcase_add_test(tc1_1, strcspn_7);
  tcase_add_test(tc1_1, strcspn_8);
  tcase_add_test(tc1_1, strcspn_9);
  tcase_add_test(tc1_1, strcspn_10);
  tcase_add_test(tc1_1, strcspn_11);
  tcase_add_test(tc1_1, strcspn_12);
  tcase_add_test(tc1_1, strcspn_13);
  tcase_add_test(tc1_1, strcspn_14);
  tcase_add_test(tc1_1, strcspn_15);
  tcase_add_test(tc1_1, strcspn_16);
  tcase_add_test(tc1_1, strcspn_17);
  tcase_add_test(tc1_1, strcspn_18);
  tcase_add_test(tc1_1, strcspn_19);
  tcase_add_test(tc1_1, strcspn_20);
  tcase_add_test(tc1_1, strcspn_21);
  tcase_add_test(tc1_1, strcspn_22);
  tcase_add_test(tc1_1, strcspn_23);
  tcase_add_test(tc1_1, strcspn_24);
  tcase_add_test(tc1_1, strcspn_25);
  tcase_add_test(tc1_1, strcspn_26);
  tcase_add_test(tc1_1, strcspn_27);
  tcase_add_test(tc1_1, strcspn_28);
  tcase_add_test(tc1_1, strcspn_29);
  tcase_add_test(tc1_1, strcspn_30);

  suite_add_tcase(s1, tc1_1);
  return s1;
}