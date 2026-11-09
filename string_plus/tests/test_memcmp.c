#include "tests.h"

START_TEST(memcmp_1) {
  char str1[] = "abc";
  char str2[] = "abc";
  int n = 3;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_2) {
  char str1[] = "Abc";
  char str2[] = "abc";
  int n = 3;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_3) {
  char str1[] = "abc";
  char str2[] = "Abc";
  int n = 3;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_4) {
  char str1[] = "abC";
  char str2[] = "abc";
  int n = 3;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_5) {
  char str1[] = "abc";
  char str2[] = "abC";
  int n = 3;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_6) {
  char str1[] = "ABC";
  char str2[] = "abc";
  int n = 3;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_7) {
  char str1[] = "abc";
  char str2[] = "ABC";
  int n = 3;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_8) {
  char str1[] = "a b c";
  char str2[] = "abc";
  int n = 3;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_9) {
  char str1[] = "abc";
  char str2[] = "a b c";
  int n = 3;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_10) {
  char str1[] = "";
  char str2[] = "abc";
  int n = 0;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_11) {
  char str1[] = "abc";
  char str2[] = "";
  int n = 1;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_12) {
  char str1[] = " ";
  char str2[] = "abc";
  int n = 1;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_13) {
  char str1[] = "abc";
  char str2[] = " ";
  int n = 2;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_14) {
  char str1[] = "9087";
  char str2[] = "657";
  int n = 3;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_15) {
  char str1[] = "";
  char str2[] = "";
  int n = 0;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_16) {
  char str1[] = " ";
  char str2[] = " ";
  int n = 2;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_17) {
  char str1[] = "abc ";
  char str2[] = "abc";
  int n = 3;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_18) {
  char str1[] = "abc";
  char str2[] = "abc ";
  int n = 3;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_19) {
  char str1[] = " abc";
  char str2[] = "abc";
  int n = 3;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_20) {
  char str1[] = "abc";
  char str2[] = " abc";
  int n = 3;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_21) {
  char str1[] = "123";
  char str2[] = "123";
  int n = 3;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_22) {
  char str1[] = "123";
  char str2[] = "321";
  int n = 3;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_23) {
  char str1[] = "321";
  char str2[] = "321";
  int n = 3;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_24) {
  char str1[] = "321";
  char str2[] = "123";
  int n = 3;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_25) {
  char str1[] = "1234";
  char str2[] = "123";
  int n = 3;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_26) {
  char str1[] = "132";
  char str2[] = "1234";
  int n = 3;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_27) {
  char str1[] = "abcd";
  char str2[] = "abc";
  int n = 3;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_28) {
  char str1[] = "abc";
  char str2[] = "abcd";
  int n = 3;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_29) {
  char str1[] = "12ab";
  char str2[] = "12ab";
  int n = 3;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_30) {
  char str1[] = "ab12";
  char str2[] = "12ab";
  int n = 3;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_31) {
  char str1[] = "abc";
  char str2[] = "abc";
  int n = 4;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_32) {
  char str1[] = "Abc";
  char str2[] = "abc";
  int n = 4;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_33) {
  char str1[] = "abc";
  char str2[] = "Abc";
  int n = 4;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_34) {
  char str1[] = "abC";
  char str2[] = "abc";
  int n = 4;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_35) {
  char str1[] = "abc";
  char str2[] = "abC";
  int n = 4;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_36) {
  char str1[] = "ABC";
  char str2[] = "abc";
  int n = 4;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_37) {
  char str1[] = "abc";
  char str2[] = "ABC";
  int n = 4;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_38) {
  char str1[] = "a b c";
  char str2[] = "abc";
  int n = 4;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_39) {
  char str1[] = "abc";
  char str2[] = "a b c";
  int n = 4;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_50) {
  char str1[] = "abc";
  char str2[] = " abc";
  int n = 0;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_51) {
  char str1[] = "123";
  char str2[] = "123";
  int n = 0;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_52) {
  char str1[] = "123";
  char str2[] = "321";
  int n = 0;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_53) {
  char str1[] = "321";
  char str2[] = "321";
  int n = 0;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_54) {
  char str1[] = "321";
  char str2[] = "123";
  int n = 0;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_55) {
  char str1[] = "1234";
  char str2[] = "123";
  int n = 0;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_56) {
  char str1[] = "132";
  char str2[] = "1234";
  int n = 0;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_57) {
  char str1[] = "abcd";
  char str2[] = "abc";
  int n = 0;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_58) {
  char str1[] = "abc";
  char str2[] = "abcd";
  int n = 0;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_59) {
  char str1[] = "12ab";
  char str2[] = "12ab";
  int n = 0;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_60) {
  char str1[] = "ab12";
  char str2[] = "12ab";
  int n = 0;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

Suite *test_memcmp(void) {
  Suite *s1 = suite_create("\033[45mS21_MEMCMP\033[0m");
  TCase *tc1_1 = tcase_create("memcmp_tc");
  tcase_add_test(tc1_1, memcmp_1);
  tcase_add_test(tc1_1, memcmp_2);
  tcase_add_test(tc1_1, memcmp_3);
  tcase_add_test(tc1_1, memcmp_4);
  tcase_add_test(tc1_1, memcmp_5);
  tcase_add_test(tc1_1, memcmp_6);
  tcase_add_test(tc1_1, memcmp_7);
  tcase_add_test(tc1_1, memcmp_8);
  tcase_add_test(tc1_1, memcmp_9);
  tcase_add_test(tc1_1, memcmp_10);
  tcase_add_test(tc1_1, memcmp_11);
  tcase_add_test(tc1_1, memcmp_12);
  tcase_add_test(tc1_1, memcmp_13);
  tcase_add_test(tc1_1, memcmp_14);
  tcase_add_test(tc1_1, memcmp_15);
  tcase_add_test(tc1_1, memcmp_16);
  tcase_add_test(tc1_1, memcmp_17);
  tcase_add_test(tc1_1, memcmp_18);
  tcase_add_test(tc1_1, memcmp_19);
  tcase_add_test(tc1_1, memcmp_20);
  tcase_add_test(tc1_1, memcmp_21);
  tcase_add_test(tc1_1, memcmp_22);
  tcase_add_test(tc1_1, memcmp_23);
  tcase_add_test(tc1_1, memcmp_24);
  tcase_add_test(tc1_1, memcmp_25);
  tcase_add_test(tc1_1, memcmp_26);
  tcase_add_test(tc1_1, memcmp_27);
  tcase_add_test(tc1_1, memcmp_28);
  tcase_add_test(tc1_1, memcmp_29);
  tcase_add_test(tc1_1, memcmp_30);
  tcase_add_test(tc1_1, memcmp_31);
  tcase_add_test(tc1_1, memcmp_32);
  tcase_add_test(tc1_1, memcmp_33);
  tcase_add_test(tc1_1, memcmp_34);
  tcase_add_test(tc1_1, memcmp_35);
  tcase_add_test(tc1_1, memcmp_36);
  tcase_add_test(tc1_1, memcmp_37);
  tcase_add_test(tc1_1, memcmp_38);
  tcase_add_test(tc1_1, memcmp_39);
  tcase_add_test(tc1_1, memcmp_50);
  tcase_add_test(tc1_1, memcmp_51);
  tcase_add_test(tc1_1, memcmp_52);
  tcase_add_test(tc1_1, memcmp_53);
  tcase_add_test(tc1_1, memcmp_54);
  tcase_add_test(tc1_1, memcmp_55);
  tcase_add_test(tc1_1, memcmp_56);
  tcase_add_test(tc1_1, memcmp_57);
  tcase_add_test(tc1_1, memcmp_58);
  tcase_add_test(tc1_1, memcmp_59);
  tcase_add_test(tc1_1, memcmp_60);

  suite_add_tcase(s1, tc1_1);
  return s1;
}