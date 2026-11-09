#include "tests.h"

START_TEST(s21_trim_1) {
  char str1[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char str2[] = "ABC";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "DEFGHIJKLMNOPQRSTUVWXYZ");
  free(str3);
}
END_TEST

START_TEST(s21_trim_2) {
  char str1[] = "ABCDEFGHIabcABCPQRSTUVWXYZ";
  char str2[] = "ABC";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "DEFGHIabcABCPQRSTUVWXYZ");
  free(str3);
}
END_TEST

START_TEST(s21_trim_3) {
  char str1[] = "ABCDEFGHIabcABCPQRSTUVWXYZABC";
  char str2[] = "ABC";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "DEFGHIabcABCPQRSTUVWXYZ");
  free(str3);
}
END_TEST

START_TEST(s21_trim_4) {
  char str1[] = "ABCDEFGHIabcABCPQRSTUVWXYZabc";
  char str2[] = "ABC";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "DEFGHIabcABCPQRSTUVWXYZabc");
  free(str3);
}
END_TEST

START_TEST(s21_trim_5) {
  char str1[] = "ABCDEFGHIabcABCPQRSTUVWXYZabc";
  char str2[] = "abc";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "ABCDEFGHIabcABCPQRSTUVWXYZ");
  free(str3);
}
END_TEST

START_TEST(s21_trim_6) {
  char str1[] = "abc123abc";
  char str2[] = "abc";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "123");
  free(str3);
}
END_TEST

START_TEST(s21_trim_7) {
  char str1[] = "abc123abc456abc";
  char str2[] = "abc";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "123abc456");
  free(str3);
}
END_TEST

START_TEST(s21_trim_8) {
  char str1[] = "a1bc123abc456a1bc";
  char str2[] = "abc";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "1bc123abc456a1");
  free(str3);
}
END_TEST

START_TEST(s21_trim_9) {
  char str1[] = "a1bc123abc456a1bc";
  char str2[] = "a1bc";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "23abc456");
  free(str3);
}
END_TEST

START_TEST(s21_trim_10) {
  char str1[] = "abc123abc456a1bc";
  char str2[] = "ab2c";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "123abc456a1");
  free(str3);
}
END_TEST

START_TEST(s21_trim_11) {
  char str1[] = "abc123abc456a1bc";
  char str2[] = "ab12c";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "3abc456");
  free(str3);
}
END_TEST

START_TEST(s21_trim_12) {
  char str1[] = "abAc123abc456aB1bc";
  char str2[] = "ab12c";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "Ac123abc456aB");
  free(str3);
}
END_TEST

START_TEST(s21_trim_13) {
  char str1[] = "abAc123abc456aB1bc";
  char str2[] = "aBb12c";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "Ac123abc456");
  free(str3);
}
END_TEST

START_TEST(s21_trim_14) {
  char str1[] = "11222333444aaaBaabaA53332244445677Babab7878998";
  char str2[] = "aBbA12c";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "333444aaaBaabaA53332244445677Babab7878998");
  free(str3);
}
END_TEST

START_TEST(s21_trim_15) {
  char str1[] = "11222333444aaaBaabaA53332244445677Babab7878998";
  char str2[] = "4aB3bA12c";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "53332244445677Babab7878998");
  free(str3);
}
END_TEST

START_TEST(s21_trim_16) {
  char str1[] = "11222333444aaaBaabaA53332244445677Babab7878998";
  char str2[] = "4aB37bA897c";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "11222333444aaaBaabaA533322444456");
  free(str3);
}
END_TEST

START_TEST(s21_trim_17) {
  char str1[] = "11222333444aaaBaabaA53332244445677Babab7878998";
  char str2[] = "4223aB437bA189117c";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "533322444456");
  free(str3);
}
END_TEST

START_TEST(s21_trim_18) {
  char str1[] = "11222333444aaaBaabaA53332244445677Babab7878998";
  char str2[] = "4223aB6437bA1589117c";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "");
  free(str3);
}
END_TEST

START_TEST(s21_trim_19) {
  char str1[] = "11222333444aaaBaabaA53332244445677Babab7878998";
  char str2[] = "jK";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "11222333444aaaBaabaA53332244445677Babab7878998");
  free(str3);
}
END_TEST

START_TEST(s21_trim_20) {
  char str1[] = "";
  char str2[] = "jK";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "");
  free(str3);
}
END_TEST

START_TEST(s21_trim_21) {
  char str1[] = "sdfghjk";
  char str2[] = " ";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "sdfghjk");
  free(str3);
}
END_TEST

START_TEST(s21_trim_22) {
  char str1[] = "sdfg hjk";
  char str2[] = " ";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "sdfg hjk");
  free(str3);
}
END_TEST

START_TEST(s21_trim_23) {
  char str1[] = " ";
  char str2[] = " ";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "");
  free(str3);
}
END_TEST

START_TEST(s21_trim_24) {
  char str1[] = "a231546yutiljkhgtyre565786oiu;jlkhb12";
  char str2[] = "12333333333333333333333333333333333ab";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "546yutiljkhgtyre565786oiu;jlkh");
  free(str3);
}
END_TEST

START_TEST(s21_trim_25) {
  char str1[] = "a231546yutiljkhgtyre565786oiu;jlkhb12";
  char str2[] = "12333333333333333333333333333333333abmmmmmm";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "546yutiljkhgtyre565786oiu;jlkh");
  free(str3);
}
END_TEST

Suite *test_trim(void) {
  Suite *s1 = suite_create("\033[45mS21_TRIM\033[0m");
  TCase *tc1_1 = tcase_create("trim_tc");
  tcase_add_test(tc1_1, s21_trim_1);
  tcase_add_test(tc1_1, s21_trim_2);
  tcase_add_test(tc1_1, s21_trim_3);
  tcase_add_test(tc1_1, s21_trim_4);
  tcase_add_test(tc1_1, s21_trim_5);
  tcase_add_test(tc1_1, s21_trim_6);
  tcase_add_test(tc1_1, s21_trim_7);
  tcase_add_test(tc1_1, s21_trim_8);
  tcase_add_test(tc1_1, s21_trim_9);
  tcase_add_test(tc1_1, s21_trim_10);
  tcase_add_test(tc1_1, s21_trim_11);
  tcase_add_test(tc1_1, s21_trim_12);
  tcase_add_test(tc1_1, s21_trim_13);
  tcase_add_test(tc1_1, s21_trim_14);
  tcase_add_test(tc1_1, s21_trim_15);
  tcase_add_test(tc1_1, s21_trim_16);
  tcase_add_test(tc1_1, s21_trim_17);
  tcase_add_test(tc1_1, s21_trim_18);
  tcase_add_test(tc1_1, s21_trim_19);
  tcase_add_test(tc1_1, s21_trim_20);
  tcase_add_test(tc1_1, s21_trim_21);
  tcase_add_test(tc1_1, s21_trim_22);
  tcase_add_test(tc1_1, s21_trim_23);
  tcase_add_test(tc1_1, s21_trim_24);
  tcase_add_test(tc1_1, s21_trim_25);

  suite_add_tcase(s1, tc1_1);
  return s1;
}