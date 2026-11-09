#include "tests.h"

START_TEST(strtok_1) {
  char input[] = "This is a test";
  const char delim[] = " ";
  ck_assert_str_eq(s21_strtok(input, delim), strtok(input, delim));
}
END_TEST

START_TEST(strtok_2) {
  char input[] = "This,is,a,test";
  const char delim[] = ",";
  ck_assert_str_eq(s21_strtok(input, delim), strtok(input, delim));
}
END_TEST

START_TEST(strtok_3) {
  char input[] = "Another test";
  const char delim[] = " ";
  ck_assert_str_eq(s21_strtok(input, delim), strtok(input, delim));
}
END_TEST

START_TEST(strtok_4) {
  char input[] = "This_is_a_test";
  const char delim[] = "_";
  ck_assert_str_eq(s21_strtok(input, delim), strtok(input, delim));
}
END_TEST

// Другие тестовые функции
START_TEST(strtok_5) {
  char input[] = "1234567890";
  const char delim[] = "234";
  ck_assert_str_eq(s21_strtok(input, delim), strtok(input, delim));
}
END_TEST

START_TEST(strtok_6) {
  char input[] = "Hello, World!aaa";
  const char delim[] = " !";
  ck_assert_str_eq(s21_strtok(input, delim), strtok(input, delim));
}
END_TEST

START_TEST(strtok_9) {
  char input[] = "Test";
  const char delim[] = " ";
  ck_assert_str_eq(s21_strtok(input, delim), strtok(input, delim));
}
END_TEST

START_TEST(strtok_10) {
  char input[] = "Test";
  const char delim[] = "XYZ";
  ck_assert_str_eq(s21_strtok(input, delim), strtok(input, delim));
}
END_TEST

START_TEST(strtok_11) {
  char input[] = "   Test   ";
  const char delim[] = " ";
  ck_assert_str_eq(s21_strtok(input, delim), strtok(input, delim));
}
END_TEST

START_TEST(strtok_12) {
  char input[] = "This;is;a;test";
  const char delim[] = ";";
  ck_assert_str_eq(s21_strtok(input, delim), strtok(input, delim));
}
END_TEST

START_TEST(strtok_13) {
  char input[] = "This is a test";
  const char delim[] = "";
  ck_assert_str_eq(s21_strtok(input, delim), strtok(input, delim));
}
END_TEST

START_TEST(strtok_14) {
  char input[] = "This is a test";
  const char delim[] = "xyz";
  ck_assert_str_eq(s21_strtok(input, delim), strtok(input, delim));
}
END_TEST

START_TEST(strtok_15) {
  char input[] = "Test1 Test2 Test3";
  const char delim[] = "Test";
  ck_assert_str_eq(s21_strtok(input, delim), strtok(input, delim));
}
END_TEST

Suite *test_strtok(void) {
  Suite *s = suite_create("\033[45mS21_STRTOK\033[0m");
  TCase *tc = tcase_create("strtok");

  tcase_add_test(tc, strtok_1);
  tcase_add_test(tc, strtok_2);
  tcase_add_test(tc, strtok_3);
  tcase_add_test(tc, strtok_4);
  tcase_add_test(tc, strtok_5);
  tcase_add_test(tc, strtok_6);
  tcase_add_test(tc, strtok_9);
  tcase_add_test(tc, strtok_10);
  tcase_add_test(tc, strtok_11);
  tcase_add_test(tc, strtok_12);
  tcase_add_test(tc, strtok_13);
  tcase_add_test(tc, strtok_14);
  tcase_add_test(tc, strtok_15);

  suite_add_tcase(s, tc);
  return s;
}