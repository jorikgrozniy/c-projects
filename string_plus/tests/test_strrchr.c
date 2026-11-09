#include "tests.h"

START_TEST(strrchr_1) {
  const char str[] = "Hello, World!";
  int ch = 'o';
  ck_assert_ptr_eq(strrchr(str, ch), s21_strrchr(str, ch));
}
END_TEST

START_TEST(strrchr_2) {
  const char str[] = "Hello, World!";
  int ch = 'o';
  ck_assert_ptr_eq(strrchr(str, ch), s21_strrchr(str, ch));
}
END_TEST

START_TEST(strrchr_3) {
  const char str[] = "Hello, World!";
  int ch = 'z';
  ck_assert_ptr_eq(strrchr(str, ch), s21_strrchr(str, ch));
}
END_TEST

START_TEST(strrchr_4) {
  const char str[] = "";
  int ch = 'o';
  ck_assert_ptr_eq(strrchr(str, ch), s21_strrchr(str, ch));
}
END_TEST

START_TEST(strrchr_5) {
  const char str[] = {'H', 'e', 'l', 'l', 'o', '\0', 'W',
                      'o', 'r', 'l', 'd', '!', '\0'};
  int ch = '\0';
  ck_assert_ptr_eq(strrchr(str, ch), s21_strrchr(str, ch));
}
END_TEST

START_TEST(strrchr_6) {
  const char str[] = "Hello, World!";
  int ch = 'l';
  ck_assert_ptr_eq(strrchr(str, ch), s21_strrchr(str, ch));
}
END_TEST

START_TEST(strrchr_7) {
  const char *str =
      "This is a long string that contains many characters and numbers: "
      "1234567890";
  int ch = '0';
  ck_assert_ptr_eq(strrchr(str, ch), s21_strrchr(str, ch));
}
END_TEST

START_TEST(strrchr_8) {
  const char *str = "!@#$%^&*()_+{}[];':,.<>/?";
  int ch = ':';
  ck_assert_ptr_eq(strrchr(str, ch), s21_strrchr(str, ch));
}
END_TEST

Suite *test_strrchr(void) {
  Suite *s = suite_create("\033[45mS21_STRRCHR\033[0m");
  TCase *tc = tcase_create("strrchr");

  tcase_add_test(tc, strrchr_1);
  tcase_add_test(tc, strrchr_2);
  tcase_add_test(tc, strrchr_3);
  tcase_add_test(tc, strrchr_4);
  tcase_add_test(tc, strrchr_5);
  tcase_add_test(tc, strrchr_6);
  tcase_add_test(tc, strrchr_7);
  tcase_add_test(tc, strrchr_8);

  suite_add_tcase(s, tc);
  return s;
}