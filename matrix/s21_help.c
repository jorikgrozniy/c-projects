#include "s21_help.h"

int is_matrix_correct(const matrix_t* A) {
  return (A == NULL || A->matrix == NULL || A->rows <= 0 || A->columns <= 0)
             ? 0
             : 1;
}

int is_matrix_square(const matrix_t* A) {
  return (A->rows == A->columns) ? 1 : 0;
}

int are_sizes_equal(const matrix_t* A, const matrix_t* B) {
  return (A->rows == B->rows) && (A->columns == B->columns) ? 1 : 0;
}

int is_mul_possible(const matrix_t* A, const matrix_t* B) {
  return (A->columns == B->rows) ? 1 : 0;
}

void negate_matrix(matrix_t* A) {
  if (is_matrix_correct(A)) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        A->matrix[i][j] *= -1;
      }
    }
  }
}

void create_minor(const matrix_t* A, int row, int col, matrix_t* result) {
  s21_create_matrix(A->rows - 1, A->columns - 1, result);
  for (int i = 0, k = 0; i < A->rows; i++) {
    for (int j = 0, l = 0; j < A->columns; j++) {
      if (i != row && j != col) result->matrix[k][l++] = A->matrix[i][j];
    }
    if (i != row) k++;
  }
}