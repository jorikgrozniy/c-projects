#include "s21_matrix.h"

#include "s21_help.h"

int s21_create_matrix(int rows, int columns, matrix_t* result) {
  int code =
      (result == NULL || rows <= 0 || columns <= 0) ? INCORRECT_MATRIX : OK;
  if (code == OK) {
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double**)malloc(rows * sizeof(double*));

    for (int i = 0; i < rows; i++) {
      result->matrix[i] = (double*)malloc(columns * sizeof(double));
      for (int j = 0; j < columns; j++) {
        result->matrix[i][j] = 0.0;
      }
    }
  }
  return code;
}

void s21_remove_matrix(matrix_t* A) {
  if (A != NULL) {
    if (A->matrix != NULL) {
      for (int i = 0; i < A->rows; i++) {
        free(A->matrix[i]);
      }
      free(A->matrix);
    }
    A->rows = 0;
    A->columns = 0;
  }
}

int s21_eq_matrix(matrix_t* A, matrix_t* B) {
  int code = FAILURE;
  if (is_matrix_correct(A) && is_matrix_correct(B) && are_sizes_equal(A, B)) {
    code = SUCCESS;
    for (int i = 0; i < A->rows && code == SUCCESS; i++) {
      for (int j = 0; j < A->columns && code == SUCCESS; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > EPS) code = FAILURE;
      }
    }
  }
  return code;
}

int s21_sum_matrix(matrix_t* A, matrix_t* B, matrix_t* result) {
  int code = (is_matrix_correct(A) && is_matrix_correct(B))
                 ? (are_sizes_equal(A, B) ? OK : CALCULATION_ERROR)
                 : INCORRECT_MATRIX;
  if (code == OK) {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
      }
    }
  }
  return code;
}

int s21_sub_matrix(matrix_t* A, matrix_t* B, matrix_t* result) {
  negate_matrix(B);
  return s21_sum_matrix(A, B, result);
}

int s21_mult_number(matrix_t* A, double number, matrix_t* result) {
  int code = is_matrix_correct(A) ? OK : INCORRECT_MATRIX;
  if (code == OK) {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = number * A->matrix[i][j];
      }
    }
  }
  return code;
}

int s21_mult_matrix(matrix_t* A, matrix_t* B, matrix_t* result) {
  int code = (is_matrix_correct(A) && is_matrix_correct(B))
                 ? (is_mul_possible(A, B) ? OK : CALCULATION_ERROR)
                 : INCORRECT_MATRIX;
  if (code == OK) {
    s21_create_matrix(A->rows, B->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < B->columns; j++) {
        double sum = 0;
        for (int k = 0; k < B->rows; k++) {
          sum += A->matrix[i][k] * B->matrix[k][j];
        }
        result->matrix[i][j] = sum;
      }
    }
  }
  return code;
}

int s21_transpose(matrix_t* A, matrix_t* result) {
  int code = is_matrix_correct(A) ? OK : INCORRECT_MATRIX;
  if (code == OK) {
    s21_create_matrix(A->columns, A->rows, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[j][i] = A->matrix[i][j];
      }
    }
  }
  return code;
}

int s21_calc_complements(matrix_t* A, matrix_t* result) {
  int code = is_matrix_correct(A)
                 ? (is_matrix_square(A) ? OK : CALCULATION_ERROR)
                 : INCORRECT_MATRIX;
  if (code == OK) {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        matrix_t minor;
        double minor_det;

        create_minor(A, i, j, &minor);
        s21_determinant(&minor, &minor_det);
        result->matrix[i][j] = pow(-1, i + j) * minor_det;
        s21_remove_matrix(&minor);
      }
    }
  }
  return code;
}

int s21_determinant(matrix_t* A, double* result) {
  int code = is_matrix_correct(A)
                 ? (is_matrix_square(A) ? OK : CALCULATION_ERROR)
                 : INCORRECT_MATRIX;
  if (code == OK) {
    if (A->rows == 1)
      *result = A->matrix[0][0];
    else if (A->rows == 2)
      *result =
          A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
    else {
      *result = 0.0;
      for (int j = 0; j < A->columns; j++) {
        matrix_t minor;
        double minor_det;

        create_minor(A, 0, j, &minor);
        s21_determinant(&minor, &minor_det);
        *result += pow(-1, j) * A->matrix[0][j] * minor_det;
        s21_remove_matrix(&minor);
      }
    }
  }
  return code;
}

int s21_inverse_matrix(matrix_t* A, matrix_t* result) {
  double det;
  s21_determinant(A, &det);
  int code =
      is_matrix_correct(A)
          ? ((is_matrix_square(A) && det != 0.0) ? OK : CALCULATION_ERROR)
          : INCORRECT_MATRIX;
  if (code == OK) {
    matrix_t comp, comp_t;

    s21_calc_complements(A, &comp);
    s21_transpose(&comp, &comp_t);
    s21_mult_number(&comp_t, 1.0 / det, result);

    s21_remove_matrix(&comp);
    s21_remove_matrix(&comp_t);
  }
  return code;
}