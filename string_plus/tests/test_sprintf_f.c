#include "tests.h"

START_TEST(sprintf_1_f) {
  char str1[200] = {'\0'};
  char str2[200] = {'\0'};
  char *str3 = "%f TEST %.f TEST %4f TEST %4.f TEST %5.9f!";
  double num = 76.756589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_f) {
  char str1[200] = {'\0'};
  char str2[200] = {'\0'};
  char *str3 = "%f TEST %.f TEST %3f TEST %4.f TEST %5.9f!";
  double num = -76.756589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_f) {
  char str1[400] = {'\0'};
  char str2[400] = {'\0'};
  char *str3 = "%20.7f\n%20.7f\n%-20.5f!";
  double num = -76.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_f) {
  char str1[400] = {'\0'};
  char str2[400] = {'\0'};
  char *str3 = "test: %5f\ntest: %6.1f\ntest: %8.2f!";
  double num = 76.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_7_f) {
  char str1[400] = {'\0'};
  char str2[400] = {'\0'};
  char *str3 = "test: %10.5f\ntest: %12.4f!";
  double num = 76.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_8_f) {
  char str1[400] = {'\0'};
  char str2[400] = {'\0'};
  char *str3 = "test: %15.1f\ntest: %16.2f\ntest: %18.3f!";
  double num = -7648930.756589;
  sprintf(str1, str3, num, num, num), s21_sprintf(str2, str3, num, num, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_9_f) {
  char str1[400] = {'\0'};
  char str2[400] = {'\0'};
  char *str3 = "test: %10.4f\ntest: %25.5f!";
  double num = -7648930.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_10_f) {
  char str1[400] = {'\0'};
  char str2[400] = {'\0'};
  char *str3 = "test: %+15.f\ntest: %+16.f\ntest: %+18.0f!";
  double num = 938790.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_11_f) {
  char str1[400] = {'\0'};
  char str2[400] = {'\0'};
  char *str3 = "test: %+ 18.0f\ntest: %+10.f\ntest: %+25.f!";
  double num = 768790.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_12_f) {
  char str1[400] = {'\0'};
  char str2[400] = {'\0'};
  char *str3 = "test: %-26.1f\ntest: %-18.0f\ntest: %-10.f!";
  double num = 7648990.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_13_f) {
  char str1[400] = {'\0'};
  char str2[400] = {'\0'};
  char *str3 = "test: %-15.f\ntest: %-+25.f!";
  double num = 764790.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_14_f) {
  char str1[400] = {'\0'};
  char str2[400] = {'\0'};
  char *str3 = "test: %-15.4f!\ntest: %-26.1f!\ntest: %-18.0f!";
  double num = -365289.3462865487;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_20_f) {
  char str1[400] = {'\0'};
  char str2[400] = {'\0'};
  char *str3 = "test: %- 23.5f!\ntest: %+ 25.5f!";
  double num = 365289.346834;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_21_f) {
  char str1[400] = {'\0'};
  char str2[400] = {'\0'};
  char *str3 = "test: % 15f!\ntest: % -26f!\ntest: %- 18f!";
  double num = -365789.34;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_22_f) {
  char str1[400] = {'\0'};
  char str2[400] = {'\0'};
  char *str3 = "test: %+- 14f!\ntest: %+ 10f!\ntest: % +25f!";
  double num = -365789.34;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_23_f) {
  char str1[400] = {'\0'};
  char str2[400] = {'\0'};
  char *str3 = "test: % 14f!\ntest: % -27f!\ntest: %- 19f!";
  double num = 365789.34;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_24_f) {
  char str1[400] = {'\0'};
  char str2[400] = {'\0'};
  char *str3 = "test: %+- 16f!\ntest: %+ 44f!\ntest: % +35f!";
  double num = 365789.34;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_32_f) {
  char str1[400] = {'\0'};
  char str2[400] = {'\0'};
  char *str3 = "test: %15f!\ntest: %-026f!\ntest: %+18f!";
  double num = -947.6785643;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_33_f) {
  char str1[400] = {'\0'};
  char str2[400] = {'\0'};
  char *str3 = "test: %+- 010.2f!\ntest: %- 025.5f\ntest: %+- 18.4f!";
  double num = -947.6785643;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *test_sprintf_f(void) {
  Suite *s = suite_create("\033[45mS21_SPRINTF_F\033[0m");
  TCase *tc = tcase_create("sprintf_f");

  tcase_add_test(tc, sprintf_1_f);
  tcase_add_test(tc, sprintf_2_f);
  tcase_add_test(tc, sprintf_4_f);
  tcase_add_test(tc, sprintf_6_f);
  tcase_add_test(tc, sprintf_7_f);
  tcase_add_test(tc, sprintf_8_f);
  tcase_add_test(tc, sprintf_9_f);
  tcase_add_test(tc, sprintf_10_f);
  tcase_add_test(tc, sprintf_11_f);
  tcase_add_test(tc, sprintf_12_f);
  tcase_add_test(tc, sprintf_13_f);
  tcase_add_test(tc, sprintf_14_f);
  tcase_add_test(tc, sprintf_20_f);
  tcase_add_test(tc, sprintf_21_f);
  tcase_add_test(tc, sprintf_22_f);
  tcase_add_test(tc, sprintf_23_f);
  tcase_add_test(tc, sprintf_24_f);
  tcase_add_test(tc, sprintf_32_f);
  tcase_add_test(tc, sprintf_33_f);
  suite_add_tcase(s, tc);
  return s;
}