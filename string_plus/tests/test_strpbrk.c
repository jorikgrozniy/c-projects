#include "tests.h"

START_TEST(strpbrk_1) {
  const char str1[] = "Hello, World!";
  const char str2[] = "aeiou";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_2) {
  const char str1[] = "OpenAI GPT-3.5";
  const char str2[] = "GPT";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_3) {
  const char str1[] = "Testing the s21_strpbrk function";
  const char str2[] = "xyz";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_4) {
  const char str1[] = "1234567890";
  const char str2[] = "abc";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_5) {
  const char str1[] = "C++ Programming";
  const char str2[] = "C#";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_6) {
  const char str1[] = "abcdefg";
  const char str2[] = "xyz";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_7) {
  const char str1[] = "Hello, World!";
  const char str2[] = "WXYZ";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_8) {
  const char str1[] = "Testing the s21_strpbrk function";
  const char str2[] = "1234567890";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_9) {
  const char str1[] = "1234567890";
  const char str2[] = "!@#$%^&*()";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_10) {
  const char str1[] = "Hello, World!";
  const char str2[] = "";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_11) {
  const char str1[] = "hello world, friend of mine!";
  const char str2[] = ", !";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

Suite *test_strpbrk(void) {
  Suite *s = suite_create("\033[45mS21_STRPBRK\033[0m");
  TCase *tc = tcase_create("strpbrk");

  tcase_add_test(tc, strpbrk_1);
  tcase_add_test(tc, strpbrk_2);
  tcase_add_test(tc, strpbrk_3);
  tcase_add_test(tc, strpbrk_4);
  tcase_add_test(tc, strpbrk_5);
  tcase_add_test(tc, strpbrk_6);
  tcase_add_test(tc, strpbrk_7);
  tcase_add_test(tc, strpbrk_8);
  tcase_add_test(tc, strpbrk_9);
  tcase_add_test(tc, strpbrk_10);
  tcase_add_test(tc, strpbrk_11);

  suite_add_tcase(s, tc);
  return s;
}