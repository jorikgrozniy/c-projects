#ifndef TEST_H
#define TEST_H

#include <check.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "../s21_matrix.h"

int run_suite(Suite* suite);
void fill_matrix(matrix_t* A, int mode);
void set_matrix(matrix_t* A, ...);
// void print_matrix(matrix_t A);
Suite* test_eq();
Suite* test_sum();
Suite* test_sub();
Suite* test_mult_n();
Suite* test_mult();
Suite* test_transpose();
Suite* test_comp();
Suite* test_det();
Suite* test_inverse();

#endif