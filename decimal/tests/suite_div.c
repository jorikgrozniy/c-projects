#include "check.h"
#include "test.h"

void test_div(s21_decimal decimal1, s21_decimal decimal2, s21_decimal check);
void test_div_fail1(s21_decimal decimal1, s21_decimal decimal2, int code_check);
void test_div_fail2(s21_decimal decimal1, s21_decimal decimal2,
                    s21_decimal decimal_check, int code_check);

START_TEST(div_1) {
  s21_decimal x = {{0}};
  s21_decimal y = {{1, 0, 0, 0}};
  s21_decimal result = {{0}};
  s21_decimal correct = {{0}};
  s21_div(x, y, &result);
  ck_assert(s21_is_equal(result, correct));
}
END_TEST

START_TEST(div_2) {
  s21_decimal x = {{1, 0, 0, 0}};
  s21_decimal y = {{0}};
  s21_decimal result = {{0}};
  ck_assert(s21_div(x, y, &result) == 3);
}
END_TEST

START_TEST(div_3) {
  s21_decimal x = {{10}};
  s21_decimal y = {{5}};
  s21_decimal result = {{0}};
  s21_decimal correct = {{2, 0, 0, 0}};
  s21_div(x, y, &result);
  ck_assert(s21_is_equal(result, correct));
}
END_TEST

START_TEST(div_4) {
  s21_decimal x = {{5}};
  s21_decimal y = {{10}};
  s21_decimal result = {{0}};
  s21_decimal correct = {{5, 0, 0, 0}};
  s21_set_scale(&correct, 1);
  s21_div(x, y, &result);
  ck_assert(s21_is_equal(result, correct));
}
END_TEST

START_TEST(div_5) {
  s21_decimal x = {{1}};
  s21_decimal y = {{3}};
  s21_decimal result = {{0}};
  s21_decimal correct = {{0x5555555, 0x14B700CB, 0xAC544CA, 0}};
  s21_set_scale(&correct, 28);
  s21_div(x, y, &result);
  ck_assert(s21_is_equal(result, correct));
}
END_TEST

START_TEST(div_6) {
  s21_decimal x = {{2}};
  s21_decimal y = {{3}};
  s21_decimal result = {{0}};
  s21_decimal correct = {{0xAAAAAAB, 0x296E0196, 0x158A8994, 0}};
  s21_set_scale(&correct, 28);
  s21_div(x, y, &result);
  ck_assert(s21_is_equal(result, correct));
}
END_TEST

START_TEST(div_7) {
  s21_decimal x = {{1}};
  s21_set_scale(&x, 28);
  s21_decimal y = {{2}};
  s21_decimal result = {{0}};
  s21_decimal correct = {{0}};
  s21_div(x, y, &result);
  ck_assert(s21_is_equal(result, correct));
}
END_TEST

START_TEST(div_8) {
  s21_decimal x = {{11}};
  s21_set_scale(&x, 28);
  s21_decimal y = {{2}};
  s21_decimal result = {{0}};
  s21_decimal correct = {{6}};
  s21_set_scale(&correct, 28);
  s21_div(x, y, &result);
  ck_assert(s21_is_equal(result, correct));
}
END_TEST

START_TEST(div_9) {
  s21_decimal x = {{10}};
  s21_decimal y = {{1}};
  s21_set_scale(&y, 28);
  s21_decimal result = {{0}};
  ck_assert(s21_div(x, y, &result) == 1);
}
END_TEST

START_TEST(div_10) {
  s21_decimal x = {{10}};
  s21_set_sign(&x, 1);
  s21_decimal y = {{1}};
  s21_set_scale(&y, 28);
  s21_decimal result = {{0}};
  ck_assert(s21_div(x, y, &result) == 2);
}
END_TEST

START_TEST(test_div_manual1) {
  // 1.2640938749860586450804312205
  s21_decimal decimal1 = {{0x1888888D, 0xBE250261, 0x28D856E6, 0x1C0000}};
  // 2
  s21_decimal decimal2 = {{0x2, 0x0, 0x0, 0x0}};
  // 0.6320469374930293225402156102
  s21_decimal check = {{0x8C444446, 0x5F128130, 0x146C2B73, 0x1C0000}};

  test_div(decimal1, decimal2, check);
}

START_TEST(test_div_manual2) {
  // 2
  s21_decimal decimal1 = {{0x2, 0x0, 0x0, 0x0}};
  // 1.2640938749860586450804312205
  s21_decimal decimal2 = {{0x1888888D, 0xBE250261, 0x28D856E6, 0x1C0000}};
  // 1.5821609767882606564463392905
  s21_decimal check = {{0x8B80B889, 0x20B8279E, 0x331F5430, 0x1C0000}};

  test_div(decimal1, decimal2, check);
}

START_TEST(test_div_manual3) {
  // 1431655765
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
  // 12.640938749860586450805
  s21_decimal decimal2 = {{0x2EB3EF75, 0x4444026F, 0x2AD, 0x150000}};
  // 113255494.17884722765619814067
  s21_decimal check = {{0x6D7C5EB3, 0x2C521AF0, 0x24984660, 0x140000}};

  test_div(decimal1, decimal2, check);
}

START_TEST(test_div_manual4) {
  // 1
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x0}};
  // 500
  s21_decimal decimal2 = {{0x1F4, 0x0, 0x0, 0x0}};
  // 0.002
  s21_decimal check = {{0x2, 0x0, 0x0, 0x30000}};

  test_div(decimal1, decimal2, check);
}

START_TEST(test_div_manual5) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // 10000000000000000000000000000
  s21_decimal check = {{0x10000000, 0x3E250261, 0x204FCE5E, 0x0}};

  test_div(decimal1, decimal2, check);
}

START_TEST(test_div_manual6) {
  // 7.9228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000000000001
  s21_decimal check = {{0x1, 0x0, 0x0, 0x1C0000}};

  test_div(decimal1, decimal2, check);
}

START_TEST(test_div_manual7) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -3
  s21_decimal check = {{0x3, 0x0, 0x0, 0x80000000}};

  test_div(decimal1, decimal2, check);
}

START_TEST(test_div_manual8) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 156064767525876035022225408
  s21_decimal decimal2 = {{0x0, 0x0, 0x811800, 0x0}};
  // -169.22068909868474138626644073
  s21_decimal check = {{0x8C085869, 0xC05E68BD, 0x36AD9B79, 0x801A0000}};

  test_div(decimal1, decimal2, check);
}

START_TEST(test_div_manual9) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -429496729.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0x0, 0x80010000}};
  // 61489146926681729710
  s21_decimal check = {{0xAAAAAAAE, 0x55555558, 0x3, 0x0}};

  test_div(decimal1, decimal2, check);
}

START_TEST(test_div_manual10) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // -79228162514264337593543950327
  s21_decimal check = {{0xFFFFFFF7, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_div(decimal1, decimal2, check);
}

START_TEST(test_div_manual11) {
  // 1.2640938749860586450804312207
  s21_decimal decimal1 = {{0x1888888F, 0xBE250261, 0x28D856E6, 0x1C0000}};
  // 2.0000000000000000000000000000
  s21_decimal decimal2 = {{0x20000000, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // 0.6320469374930293225402156104
  s21_decimal check = {{0x8C444448, 0x5F128130, 0x146C2B73, 0x1C0000}};

  test_div(decimal1, decimal2, check);
}

START_TEST(test_div_manual12) {
  // 3.6336660283201536
  s21_decimal decimal1 = {{0x811800, 0x811800, 0x0, 0x100000}};
  // 0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // 36336660283201536000000000000
  s21_decimal check = {{0x89800000, 0xFEE8FB1C, 0x7568FB1C, 0x0}};

  test_div(decimal1, decimal2, check);
}

START_TEST(test_div_manual13) {
  // 7.9228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // 0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // 79228162514264337593543950335
  s21_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_div(decimal1, decimal2, check);
}

START_TEST(test_div_manual14) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  // division by zero
  int code_check = TEST_ARITHMETIC_ZERO_DIV;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div_manual15) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div_manual16) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div_manual17) {
  // 0.0000000000000000000000000001
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail2(decimal1, decimal2, decimal_check, code_check);
}

START_TEST(test_div_manual18) {
  // 0.0000000074505801528346182749
  s21_decimal decimal1 = {{0xCAD4845D, 0x9F9C7BD, 0x4, 0x1C0000}};
  // 1152921504606846976
  s21_decimal decimal2 = {{0x0, 0x10000000, 0x0, 0x0}};
  // 0.0000000000000000000000000065
  s21_decimal decimal_check = {{0x41, 0x0, 0x0, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div_manual19) {
  // 0.0000000000000000000542101054
  s21_decimal decimal1 = {{0x204FCE3E, 0x0, 0x0, 0x1C0000}};
  // 8388608
  s21_decimal decimal2 = {{0x800000, 0x0, 0x0, 0x0}};
  // 0.0000000000000000000000000065
  s21_decimal decimal_check = {{0x41, 0x0, 0x0, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div_manual20) {
  // 8388608
  s21_decimal decimal1 = {{0x800000, 0x0, 0x0, 0x0}};
  // 0.0000000000000000000542101054
  s21_decimal decimal2 = {{0x204FCE3E, 0x0, 0x0, 0x1C0000}};
  // 154742514114351823414827745.38
  s21_decimal decimal_check = {{0x6306800A, 0xE4ABBB05, 0x32000031, 0x20000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div_manual21) {
  // 0.0000000000000000000020971522
  s21_decimal decimal1 = {{0x1400002, 0x0, 0x0, 0x1C0000}};
  // 8388608
  s21_decimal decimal2 = {{0x800000, 0x0, 0x0, 0x0}};
  // 0.0000000000000000000000000003
  s21_decimal decimal_check = {{0x3, 0x0, 0x0, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div_manual22) {
  // 8388608
  s21_decimal decimal1 = {{0x800000, 0x0, 0x0, 0x0}};
  // 0.0000000000000000000020971522
  s21_decimal decimal2 = {{0x1400002, 0x0, 0x0, 0x1C0000}};
  // 3999999618530309817284601470.5
  s21_decimal decimal_check = {{0x695280F1, 0x2D062C6F, 0x813F38AA, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div_manual23) {
  // 1
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x0}};
  // 39614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x0}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail2(decimal1, decimal2, decimal_check, code_check);
}

Suite* init_suite_div() {
  Suite* suite = suite_create("\033[45mS21_DIV\033[0m");

  TCase* tcase_div = tcase_create("division");
  tcase_add_test(tcase_div, div_1);
  tcase_add_test(tcase_div, div_2);
  tcase_add_test(tcase_div, div_3);
  tcase_add_test(tcase_div, div_4);
  tcase_add_test(tcase_div, div_5);
  tcase_add_test(tcase_div, div_6);
  tcase_add_test(tcase_div, div_7);
  tcase_add_test(tcase_div, div_8);
  tcase_add_test(tcase_div, div_9);
  tcase_add_test(tcase_div, div_10);

  tcase_add_test(tcase_div, test_div_manual1);
  tcase_add_test(tcase_div, test_div_manual2);
  tcase_add_test(tcase_div, test_div_manual3);
  tcase_add_test(tcase_div, test_div_manual4);
  tcase_add_test(tcase_div, test_div_manual5);
  tcase_add_test(tcase_div, test_div_manual5);
  tcase_add_test(tcase_div, test_div_manual6);
  tcase_add_test(tcase_div, test_div_manual7);
  tcase_add_test(tcase_div, test_div_manual8);
  tcase_add_test(tcase_div, test_div_manual9);
  tcase_add_test(tcase_div, test_div_manual10);
  tcase_add_test(tcase_div, test_div_manual11);
  tcase_add_test(tcase_div, test_div_manual12);
  tcase_add_test(tcase_div, test_div_manual13);
  tcase_add_test(tcase_div, test_div_manual14);
  tcase_add_test(tcase_div, test_div_manual15);
  tcase_add_test(tcase_div, test_div_manual16);
  tcase_add_test(tcase_div, test_div_manual17);
  tcase_add_test(tcase_div, test_div_manual18);
  tcase_add_test(tcase_div, test_div_manual19);
  tcase_add_test(tcase_div, test_div_manual20);
  tcase_add_test(tcase_div, test_div_manual21);
  tcase_add_test(tcase_div, test_div_manual22);
  tcase_add_test(tcase_div, test_div_manual23);

  suite_add_tcase(suite, tcase_div);

  return suite;
}

void test_div(s21_decimal decimal1, s21_decimal decimal2, s21_decimal check) {
  s21_decimal result;
  int code = s21_div(decimal1, decimal2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
}

void test_div_fail1(s21_decimal decimal1, s21_decimal decimal2,
                    int code_check) {
  s21_decimal result;
  int code = s21_div(decimal1, decimal2, &result);
  ck_assert_int_eq(code, code_check);
}

void test_div_fail2(s21_decimal decimal1, s21_decimal decimal2,
                    s21_decimal decimal_check, int code_check) {
  s21_decimal result;
  int code = s21_div(decimal1, decimal2, &result);

  ck_assert_int_eq(code, code_check);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}
