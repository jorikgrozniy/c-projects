#ifndef TEST_H
#define TEST_H

#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "../s21_decimal.h"

#define TEST_ARITHMETIC_OK 0
#define TEST_ARITHMETIC_BIG 1
#define TEST_ARITHMETIC_SMALL 2
#define TEST_ARITHMETIC_ZERO_DIV 3

Suite* init_suite_common();

Suite* init_suite_comparsion();

Suite* init_suite_conversiont();

Suite* init_suite_add();

Suite* init_suite_sub();

Suite* init_suite_mul();

Suite* init_suite_other();

Suite* init_suite_mod();

Suite* init_suite_div();

Suite* comparsion_suite();

void init_decimal(s21_decimal* decimal);

#endif