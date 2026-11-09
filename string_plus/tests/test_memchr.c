#include "tests.h"

START_TEST(memchr_1) {
  char str1[] = "abc";
  int c = 'a';
  size_t n = 3;
  ck_assert_ptr_eq(memchr(str1, c, n), s21_memchr(str1, c, n));
}
END_TEST

START_TEST(memchr_2) {
  char str1[] = "abc";
  int c = 'b';
  size_t n = 3;
  ck_assert_ptr_eq(memchr(str1, c, n), s21_memchr(str1, c, n));
}
END_TEST

START_TEST(memchr_3) {
  char str1[] = "abc";
  int c = 'c';
  size_t n = 3;
  ck_assert_ptr_eq(memchr(str1, c, n), s21_memchr(str1, c, n));
}
END_TEST

START_TEST(memchr_4) {
  char str1[] = "abc";
  int c = 'd';
  size_t n = 3;
  ck_assert_ptr_eq(memchr(str1, c, n), s21_memchr(str1, c, n));
}
END_TEST

START_TEST(memchr_5) {
  char str1[] = "abc";
  int c = 'a';
  size_t n = 2;
  ck_assert_ptr_eq(memchr(str1, c, n), s21_memchr(str1, c, n));
}
END_TEST

START_TEST(memchr_6) {
  char str1[] = "abc";
  int c = 'b';
  size_t n = 2;
  ck_assert_ptr_eq(memchr(str1, c, n), s21_memchr(str1, c, n));
}
END_TEST

START_TEST(memchr_7) {
  char str1[] = "abc";
  int c = 'c';
  size_t n = 2;
  ck_assert_ptr_eq(memchr(str1, c, n), s21_memchr(str1, c, n));
}
END_TEST

START_TEST(memchr_8) {
  char str1[] = "abc";
  int c = 'a';
  size_t n = 1;
  ck_assert_ptr_eq(memchr(str1, c, n), s21_memchr(str1, c, n));
}
END_TEST

START_TEST(memchr_9) {
  char str1[] = "abc";
  int c = 'b';
  size_t n = 1;
  ck_assert_ptr_eq(memchr(str1, c, n), s21_memchr(str1, c, n));
}
END_TEST

START_TEST(memchr_10) {
  char str1[] = "abc";
  int c = 'c';
  size_t n = 1;
  ck_assert_ptr_eq(memchr(str1, c, n), s21_memchr(str1, c, n));
}
END_TEST

START_TEST(memchr_11) {
  char str1[] = "abc";
  int c = 'a';
  size_t n = 4;
  ck_assert_ptr_eq(memchr(str1, c, n), s21_memchr(str1, c, n));
}
END_TEST

START_TEST(memchr_12) {
  char str1[] = "abc";
  int c = 'a';
  size_t n = 0;
  ck_assert_ptr_eq(memchr(str1, c, n), s21_memchr(str1, c, n));
}
END_TEST

START_TEST(memchr_13) {
  char str1[] = "abc";
  int c = 'd';
  size_t n = 2;
  ck_assert_ptr_eq(memchr(str1, c, n), s21_memchr(str1, c, n));
}
END_TEST

START_TEST(memchr_14) {
  char str1[] = "abc";
  int c = 'd';
  size_t n = 2;
  ck_assert_ptr_eq(memchr(str1, c, n), s21_memchr(str1, c, n));
}
END_TEST

START_TEST(memchr_15) {
  char str1[] = "abc";
  int c = 'd';
  size_t n = 2;
  ck_assert_ptr_eq(memchr(str1, c, n), s21_memchr(str1, c, n));
}
END_TEST

START_TEST(memchr_16) {
  char str1[] = "abc";
  int c = 'd';
  size_t n = 1;
  ck_assert_ptr_eq(memchr(str1, c, n), s21_memchr(str1, c, n));
}
END_TEST

START_TEST(memchr_17) {
  char str1[] = "abc";
  int c = 'd';
  size_t n = 0;
  ck_assert_ptr_eq(memchr(str1, c, n), s21_memchr(str1, c, n));
}
END_TEST

START_TEST(memchr_18) {
  char str1[] = "abc";
  int c = 'd';
  size_t n = 4;
  ck_assert_ptr_eq(memchr(str1, c, n), s21_memchr(str1, c, n));
}
END_TEST

START_TEST(memchr_19) {
  char str1[] = "";
  int c = 'd';
  size_t n = 0;
  ck_assert_ptr_eq(memchr(str1, c, n), s21_memchr(str1, c, n));
}
END_TEST

START_TEST(memchr_21) {
  char str1[] = " ";
  int c = 'd';
  size_t n = 1;
  ck_assert_ptr_eq(memchr(str1, c, n), s21_memchr(str1, c, n));
}
END_TEST

START_TEST(memchr_22) {
  char str1[] = "abcabc";
  int c = 'b';
  size_t n = 3;
  ck_assert_ptr_eq(memchr(str1, c, n), s21_memchr(str1, c, n));
}
END_TEST

START_TEST(memchr_23) {
  char str1[] = "abcabc";
  int c = 'c';
  size_t n = 3;
  ck_assert_ptr_eq(memchr(str1, c, n), s21_memchr(str1, c, n));
}
END_TEST

START_TEST(memchr_24) {
  char str1[] = "abcabc";
  int c = 'd';
  size_t n = 3;
  ck_assert_ptr_eq(memchr(str1, c, n), s21_memchr(str1, c, n));
}
END_TEST

START_TEST(memchr_25) {
  char str1[] = "abcabc";
  int c = 'a';
  size_t n = 2;
  ck_assert_ptr_eq(memchr(str1, c, n), s21_memchr(str1, c, n));
}
END_TEST

START_TEST(memchr_26) {
  char str1[] = "abcabc";
  int c = 'b';
  size_t n = 2;
  ck_assert_ptr_eq(memchr(str1, c, n), s21_memchr(str1, c, n));
}
END_TEST

START_TEST(memchr_27) {
  char str1[] = "abcabc";
  int c = 'c';
  size_t n = 2;
  ck_assert_ptr_eq(memchr(str1, c, n), s21_memchr(str1, c, n));
}
END_TEST

START_TEST(memchr_28) {
  char str1[] = "abcabc";
  int c = 'a';
  size_t n = 1;
  ck_assert_ptr_eq(memchr(str1, c, n), s21_memchr(str1, c, n));
}
END_TEST

START_TEST(memchr_29) {
  char str1[] = "abcabc";
  int c = 'b';
  size_t n = 1;
  ck_assert_ptr_eq(memchr(str1, c, n), s21_memchr(str1, c, n));
}
END_TEST

START_TEST(memchr_30) {
  char str1[] = "abcabc";
  int c = 'c';
  size_t n = 1;
  ck_assert_ptr_eq(memchr(str1, c, n), s21_memchr(str1, c, n));
}
END_TEST

START_TEST(memchr_32) {
  char str1[] = "abcabc";
  int c = 'a';
  size_t n = 0;
  ck_assert_ptr_eq(memchr(str1, c, n), s21_memchr(str1, c, n));
}
END_TEST

START_TEST(memchr_33) {
  char str1[] = "abcabc";
  int c = 'd';
  size_t n = 3;
  ck_assert_ptr_eq(memchr(str1, c, n), s21_memchr(str1, c, n));
}
END_TEST

START_TEST(memchr_34) {
  char str1[] = "abcabc";
  int c = 'd';
  size_t n = 2;
  ck_assert_ptr_eq(memchr(str1, c, n), s21_memchr(str1, c, n));
}
END_TEST

START_TEST(memchr_35) {
  char str1[] = "abcabc";
  int c = 'd';
  size_t n = 2;
  ck_assert_ptr_eq(memchr(str1, c, n), s21_memchr(str1, c, n));
}
END_TEST

START_TEST(memchr_36) {
  char str1[] = "abcabc";
  int c = 'd';
  size_t n = 1;
  ck_assert_ptr_eq(memchr(str1, c, n), s21_memchr(str1, c, n));
}
END_TEST

START_TEST(memchr_37) {
  char str1[] = "abcabc";
  int c = 'd';
  size_t n = 0;
  ck_assert_ptr_eq(memchr(str1, c, n), s21_memchr(str1, c, n));
}
END_TEST

START_TEST(memchr_38) {
  char str1[] = "abcabc";
  int c = 'd';
  size_t n = 0;
  ck_assert_ptr_eq(memchr(str1, c, n), s21_memchr(str1, c, n));
}
END_TEST

START_TEST(memchr_39) {
  char str1[] = "abcabc";
  int c = 'a';
  size_t n = 3;
  ck_assert_ptr_eq(memchr(str1, c, n), s21_memchr(str1, c, n));
}
END_TEST

START_TEST(memchr_40) {
  char str1[] = "abc\nabc";
  int c = 'a';
  size_t n = 3;
  ck_assert_ptr_eq(memchr(str1, c, n), s21_memchr(str1, c, n));
}
END_TEST

START_TEST(memchr_41) {
  char str1[] = "abc\0abc";
  int c = 'a';
  size_t n = 3;
  ck_assert_ptr_eq(memchr(str1, c, n), s21_memchr(str1, c, n));
}
END_TEST

START_TEST(memchr_42) {
  char str1[] = "\0abcabc";
  int c = 'a';
  size_t n = 3;
  ck_assert_ptr_eq(memchr(str1, c, n), s21_memchr(str1, c, n));
}
END_TEST

START_TEST(memchr_43) {
  char str1[] = "abcabc\0";
  int c = 'a';
  size_t n = 3;
  ck_assert_ptr_eq(memchr(str1, c, n), s21_memchr(str1, c, n));
}
END_TEST

Suite *test_memchr(void) {
  Suite *s1 = suite_create("\033[45mS21_MEMCHR\033[0m");
  TCase *tc1_1 = tcase_create("memchr_tc");

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, memchr_1);
  tcase_add_test(tc1_1, memchr_2);
  tcase_add_test(tc1_1, memchr_3);
  tcase_add_test(tc1_1, memchr_4);
  tcase_add_test(tc1_1, memchr_5);
  tcase_add_test(tc1_1, memchr_6);
  tcase_add_test(tc1_1, memchr_7);
  tcase_add_test(tc1_1, memchr_8);
  tcase_add_test(tc1_1, memchr_9);
  tcase_add_test(tc1_1, memchr_10);
  tcase_add_test(tc1_1, memchr_11);
  tcase_add_test(tc1_1, memchr_12);
  tcase_add_test(tc1_1, memchr_13);
  tcase_add_test(tc1_1, memchr_14);
  tcase_add_test(tc1_1, memchr_15);
  tcase_add_test(tc1_1, memchr_16);
  tcase_add_test(tc1_1, memchr_17);
  tcase_add_test(tc1_1, memchr_18);
  tcase_add_test(tc1_1, memchr_19);

  tcase_add_test(tc1_1, memchr_21);
  tcase_add_test(tc1_1, memchr_22);
  tcase_add_test(tc1_1, memchr_23);
  tcase_add_test(tc1_1, memchr_24);
  tcase_add_test(tc1_1, memchr_25);
  tcase_add_test(tc1_1, memchr_26);
  tcase_add_test(tc1_1, memchr_27);
  tcase_add_test(tc1_1, memchr_28);
  tcase_add_test(tc1_1, memchr_29);
  tcase_add_test(tc1_1, memchr_30);

  tcase_add_test(tc1_1, memchr_32);
  tcase_add_test(tc1_1, memchr_33);
  tcase_add_test(tc1_1, memchr_34);
  tcase_add_test(tc1_1, memchr_35);
  tcase_add_test(tc1_1, memchr_36);
  tcase_add_test(tc1_1, memchr_37);
  tcase_add_test(tc1_1, memchr_38);
  tcase_add_test(tc1_1, memchr_39);
  tcase_add_test(tc1_1, memchr_40);
  tcase_add_test(tc1_1, memchr_41);
  tcase_add_test(tc1_1, memchr_42);
  tcase_add_test(tc1_1, memchr_43);

  suite_add_tcase(s1, tc1_1);
  return s1;
}