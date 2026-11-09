#include "tests.h"

START_TEST(memset_1) {
  char str1[] = "abcdefghij";
  char str2[] = "abcdefghij";
  int c = '2';
  int n = 10;
  ck_assert_str_eq(memset(str1, c, n), s21_memset(str2, c, n));
}
END_TEST

START_TEST(memset_2) {
  char str1[] = "abcdefghij";
  char str2[] = "abcdefghij";
  int c = 'a';
  int n = 10;
  ck_assert_str_eq(memset(str1, c, n), s21_memset(str2, c, n));
}
END_TEST

START_TEST(memset_3) {
  char str1[] = "abcdefghij";
  char str2[] = "abcdefghij";
  int c = '2';
  int n = 5;
  ck_assert_str_eq(memset(str1, c, n), s21_memset(str2, c, n));
}
END_TEST

START_TEST(memset_4) {
  char str1[] = "abcdefghij";
  char str2[] = "abcdefghij";
  int c = 'a';
  int n = 5;
  ck_assert_str_eq(memset(str1, c, n), s21_memset(str2, c, n));
}
END_TEST

START_TEST(memset_5) {
  char str1[] = "abcdefghij";
  char str2[] = "abcdefghij";
  int c = '2';
  int n = 1;
  ck_assert_str_eq(memset(str1, c, n), s21_memset(str2, c, n));
}
END_TEST

START_TEST(memset_6) {
  char str1[] = "abcdefghij";
  char str2[] = "abcdefghij";
  int c = 'a';
  int n = 1;
  ck_assert_str_eq(memset(str1, c, n), s21_memset(str2, c, n));
}
END_TEST

START_TEST(memset_7) {
  char str1[] = "abcdefghij";
  char str2[] = "abcdefghij";
  int c = '2';
  int n = 0;
  ck_assert_str_eq(memset(str1, c, n), s21_memset(str2, c, n));
}
END_TEST

START_TEST(memset_8) {
  char str1[] = "abcdefghij";
  char str2[] = "abcdefghij";
  int c = 'a';
  int n = 0;
  ck_assert_str_eq(memset(str1, c, n), s21_memset(str2, c, n));
}
END_TEST

START_TEST(memset_9) {
  char str1[] = "abcdefghij";
  char str2[] = "abcdefghij";
  int c = '2';
  int n = 7;
  ck_assert_str_eq(memset(str1, c, n), s21_memset(str2, c, n));
}
END_TEST

START_TEST(memset_10) {
  char str1[] = "abcdefghij";
  char str2[] = "abcdefghij";
  int c = 'a';
  int n = 3;
  ck_assert_str_eq(memset(str1, c, n), s21_memset(str2, c, n));
}
END_TEST

START_TEST(memset_11) {
  char str1[] = "1234567890";
  char str2[] = "1234567890";
  int c = '2';
  int n = 10;
  ck_assert_str_eq(memset(str1, c, n), s21_memset(str2, c, n));
}
END_TEST

START_TEST(memset_12) {
  char str1[] = "1234567890";
  char str2[] = "1234567890";
  int c = 'a';
  int n = 10;
  ck_assert_str_eq(memset(str1, c, n), s21_memset(str2, c, n));
}
END_TEST

START_TEST(memset_13) {
  char str1[] = "1234567890";
  char str2[] = "1234567890";
  int c = '2';
  int n = 5;
  ck_assert_str_eq(memset(str1, c, n), s21_memset(str2, c, n));
}
END_TEST

START_TEST(memset_14) {
  char str1[] = "1234567890";
  char str2[] = "1234567890";
  int c = 'a';
  int n = 5;
  ck_assert_str_eq(memset(str1, c, n), s21_memset(str2, c, n));
}
END_TEST

START_TEST(memset_15) {
  char str1[] = "1234567890";
  char str2[] = "1234567890";
  int c = '2';
  int n = 1;
  ck_assert_str_eq(memset(str1, c, n), s21_memset(str2, c, n));
}
END_TEST

START_TEST(memset_16) {
  char str1[] = "1234567890";
  char str2[] = "1234567890";
  int c = 'a';
  int n = 1;
  ck_assert_str_eq(memset(str1, c, n), s21_memset(str2, c, n));
}
END_TEST

START_TEST(memset_17) {
  char str1[] = "1234567890";
  char str2[] = "1234567890";
  int c = '2';
  int n = 0;
  ck_assert_str_eq(memset(str1, c, n), s21_memset(str2, c, n));
}
END_TEST

START_TEST(memset_18) {
  char str1[] = "1234567890";
  char str2[] = "1234567890";
  int c = 'a';
  int n = 0;
  ck_assert_str_eq(memset(str1, c, n), s21_memset(str2, c, n));
}
END_TEST

START_TEST(memset_19) {
  char str1[] = "1234567890";
  char str2[] = "1234567890";
  int c = '2';
  int n = 10;
  ck_assert_str_eq(memset(str1, c, n), s21_memset(str2, c, n));
}
END_TEST

START_TEST(memset_20) {
  char str1[] = "1234567890";
  char str2[] = "1234567890";
  int c = 'a';
  int n = 0;
  ck_assert_str_eq(memset(str1, c, n), s21_memset(str2, c, n));
}
END_TEST

START_TEST(memset_21) {
  char str1[] = "abcde67890";
  char str2[] = "abcde67890";
  int c = '2';
  int n = 10;
  ck_assert_str_eq(memset(str1, c, n), s21_memset(str2, c, n));
}
END_TEST

START_TEST(memset_22) {
  char str1[] = "abcde67890";
  char str2[] = "abcde67890";
  int c = 'a';
  int n = 10;
  ck_assert_str_eq(memset(str1, c, n), s21_memset(str2, c, n));
}
END_TEST

START_TEST(memset_23) {
  char str1[] = "abcde67890";
  char str2[] = "abcde67890";
  int c = '2';
  int n = 5;
  ck_assert_str_eq(memset(str1, c, n), s21_memset(str2, c, n));
}
END_TEST

START_TEST(memset_24) {
  char str1[] = "abcde67890";
  char str2[] = "abcde67890";
  int c = 'a';
  int n = 5;
  ck_assert_str_eq(memset(str1, c, n), s21_memset(str2, c, n));
}
END_TEST

START_TEST(memset_25) {
  char str1[] = "abcde67890";
  char str2[] = "abcde67890";
  int c = '2';
  int n = 1;
  ck_assert_str_eq(memset(str1, c, n), s21_memset(str2, c, n));
}
END_TEST

START_TEST(memset_26) {
  char str1[] = "abcde67890";
  char str2[] = "abcde67890";
  int c = 'a';
  int n = 1;
  ck_assert_str_eq(memset(str1, c, n), s21_memset(str2, c, n));
}
END_TEST

START_TEST(memset_27) {
  char str1[] = "abcde67890";
  char str2[] = "abcde67890";
  int c = '2';
  int n = 0;
  ck_assert_str_eq(memset(str1, c, n), s21_memset(str2, c, n));
}
END_TEST

START_TEST(memset_28) {
  char str1[] = "abcde67890";
  char str2[] = "abcde67890";
  int c = 'a';
  int n = 0;
  ck_assert_str_eq(memset(str1, c, n), s21_memset(str2, c, n));
}
END_TEST

START_TEST(memset_29) {
  char str1[] = "abcde67890";
  char str2[] = "abcde67890";
  int c = '2';
  int n = 7;
  ck_assert_str_eq(memset(str1, c, n), s21_memset(str2, c, n));
}
END_TEST

START_TEST(memset_30) {
  char str1[] = "abcde67890";
  char str2[] = "abcde67890";
  int c = 'a';
  int n = 7;
  ck_assert_str_eq(memset(str1, c, n), s21_memset(str2, c, n));
}
END_TEST

START_TEST(memset_31) {
  char str1[] = ")(*&^UTYfghjkliuy7oi6";
  char str2[] = ")(*&^UTYfghjkliuy7oi6";
  int c = '2';
  int n = 10;
  ck_assert_str_eq(memset(str1, c, n), s21_memset(str2, c, n));
}
END_TEST

START_TEST(memset_32) {
  char str1[] = ")(*&^UTYfghjkliuy7oi6";
  char str2[] = ")(*&^UTYfghjkliuy7oi6";
  int c = 'a';
  int n = 10;
  ck_assert_str_eq(memset(str1, c, n), s21_memset(str2, c, n));
}
END_TEST

START_TEST(memset_33) {
  char str1[] = ")(*&^UTYfghjkliuy7oi6";
  char str2[] = ")(*&^UTYfghjkliuy7oi6";
  int c = '2';
  int n = 5;
  ck_assert_str_eq(memset(str1, c, n), s21_memset(str2, c, n));
}
END_TEST

START_TEST(memset_34) {
  char str1[] = ")(*&^UTYfghjkliuy7oi6";
  char str2[] = ")(*&^UTYfghjkliuy7oi6";
  int c = 'a';
  int n = 5;
  ck_assert_str_eq(memset(str1, c, n), s21_memset(str2, c, n));
}
END_TEST

START_TEST(memset_35) {
  char str1[] = ")(*&^UTYfghjkliuy7oi6";
  char str2[] = ")(*&^UTYfghjkliuy7oi6";
  int c = '2';
  int n = 1;
  ck_assert_str_eq(memset(str1, c, n), s21_memset(str2, c, n));
}
END_TEST

START_TEST(memset_36) {
  char str1[] = ")(*&^UTYfghjkliuy7oi6";
  char str2[] = ")(*&^UTYfghjkliuy7oi6";
  int c = 'a';
  int n = 1;
  ck_assert_str_eq(memset(str1, c, n), s21_memset(str2, c, n));
}
END_TEST

START_TEST(memset_37) {
  char str1[] = ")(*&^UTYfghjkliuy7oi6";
  char str2[] = ")(*&^UTYfghjkliuy7oi6";
  int c = '2';
  int n = 0;
  ck_assert_str_eq(memset(str1, c, n), s21_memset(str2, c, n));
}
END_TEST

START_TEST(memset_38) {
  char str1[] = ")(*&^UTYfghjkliuy7oi6";
  char str2[] = ")(*&^UTYfghjkliuy7oi6";
  int c = 'a';
  int n = 0;
  ck_assert_str_eq(memset(str1, c, n), s21_memset(str2, c, n));
}
END_TEST

START_TEST(memset_39) {
  char str1[] = ")(*&^UTYfghjkliuy7oi6";
  char str2[] = ")(*&^UTYfghjkliuy7oi6";
  int c = '2';
  int n = 11;
  ck_assert_str_eq(memset(str1, c, n), s21_memset(str2, c, n));
}
END_TEST

START_TEST(memset_40) {
  char str1[] = ")(*&^UTYfghjkliuy7oi6";
  char str2[] = ")(*&^UTYfghjkliuy7oi6";
  int c = 'a';
  int n = 11;
  ck_assert_str_eq(memset(str1, c, n), s21_memset(str2, c, n));
}
END_TEST

START_TEST(memset_41) {
  char str1[] = "";
  char str2[] = "";
  int c = 'a';
  int n = 0;
  ck_assert_str_eq(memset(str1, c, n), s21_memset(str2, c, n));
}
END_TEST

START_TEST(memset_42) {
  char str1[] = " ";
  char str2[] = " ";
  int c = 'a';
  int n = 1;
  ck_assert_str_eq(memset(str1, c, n), s21_memset(str2, c, n));
}
END_TEST

START_TEST(memset_43) {
  char str1[] = ")(*&^UTYfgh\0jkliuy7oi6";
  char str2[] = ")(*&^UTYfgh\0jkliuy7oi6";
  int c = 'a';
  int n = 11;
  ck_assert_str_eq(memset(str1, c, n), s21_memset(str2, c, n));
}
END_TEST

START_TEST(memset_44) {
  char str1[] = ")(*&^UTYfgh\njkliuy7oi6";
  char str2[] = ")(*&^UTYfgh\njkliuy7oi6";
  int c = 'a';
  int n = 11;
  ck_assert_str_eq(memset(str1, c, n), s21_memset(str2, c, n));
}
END_TEST

START_TEST(memset_45) {
  char str1[] = ")(*&^UTYfghjkliuy7oi6\0";
  char str2[] = ")(*&^UTYfghjkliuy7oi6\0";
  int c = 'a';
  int n = 11;
  ck_assert_str_eq(memset(str1, c, n), s21_memset(str2, c, n));
}
END_TEST

START_TEST(memset_46) {
  char str1[] = "\0)(*&^UTYfgh\0jkliuy7oi6";
  char str2[] = "\0)(*&^UTYfgh\0jkliuy7oi6";
  int c = 'a';
  int n = 11;
  ck_assert_str_eq(memset(str1, c, n), s21_memset(str2, c, n));
}
END_TEST

Suite *test_memset(void) {
  Suite *s1 = suite_create("\033[45mS21_MEMSET\033[0m");
  TCase *tc1_1 = tcase_create("memset_tc");

  tcase_add_test(tc1_1, memset_1);
  tcase_add_test(tc1_1, memset_2);
  tcase_add_test(tc1_1, memset_3);
  tcase_add_test(tc1_1, memset_4);
  tcase_add_test(tc1_1, memset_5);
  tcase_add_test(tc1_1, memset_6);
  tcase_add_test(tc1_1, memset_7);
  tcase_add_test(tc1_1, memset_8);
  tcase_add_test(tc1_1, memset_9);
  tcase_add_test(tc1_1, memset_10);
  tcase_add_test(tc1_1, memset_11);
  tcase_add_test(tc1_1, memset_12);
  tcase_add_test(tc1_1, memset_13);
  tcase_add_test(tc1_1, memset_14);
  tcase_add_test(tc1_1, memset_15);
  tcase_add_test(tc1_1, memset_16);
  tcase_add_test(tc1_1, memset_17);
  tcase_add_test(tc1_1, memset_18);
  tcase_add_test(tc1_1, memset_19);
  tcase_add_test(tc1_1, memset_20);
  tcase_add_test(tc1_1, memset_21);
  tcase_add_test(tc1_1, memset_22);
  tcase_add_test(tc1_1, memset_23);
  tcase_add_test(tc1_1, memset_24);
  tcase_add_test(tc1_1, memset_25);
  tcase_add_test(tc1_1, memset_26);
  tcase_add_test(tc1_1, memset_27);
  tcase_add_test(tc1_1, memset_28);
  tcase_add_test(tc1_1, memset_29);
  tcase_add_test(tc1_1, memset_30);
  tcase_add_test(tc1_1, memset_31);
  tcase_add_test(tc1_1, memset_32);
  tcase_add_test(tc1_1, memset_33);
  tcase_add_test(tc1_1, memset_34);
  tcase_add_test(tc1_1, memset_35);
  tcase_add_test(tc1_1, memset_36);
  tcase_add_test(tc1_1, memset_37);
  tcase_add_test(tc1_1, memset_38);
  tcase_add_test(tc1_1, memset_39);
  tcase_add_test(tc1_1, memset_40);
  tcase_add_test(tc1_1, memset_41);
  tcase_add_test(tc1_1, memset_42);
  tcase_add_test(tc1_1, memset_43);
  tcase_add_test(tc1_1, memset_44);
  tcase_add_test(tc1_1, memset_45);
  tcase_add_test(tc1_1, memset_46);

  suite_add_tcase(s1, tc1_1);
  return s1;
}