#ifndef S21_HELP_H
#define S21_HELP_H

#include "s21_matrix.h"

int is_matrix_correct(const matrix_t* A);
int is_matrix_square(const matrix_t* A);
int are_sizes_equal(const matrix_t* A, const matrix_t* B);
int is_mul_possible(const matrix_t* A, const matrix_t* B);
void negate_matrix(matrix_t* A);
void create_minor(const matrix_t* A, int row, int col, matrix_t* result);

#endif