#include "test.h"

int main() {
  int failed = 0;
  Suite* suites[] = {
      test_eq(),        test_sum(),  test_sub(), test_mult_n(),  test_mult(),
      test_transpose(), test_comp(), test_det(), test_inverse(), NULL};

  for (int i = 0; suites[i] != NULL; i++) {
    failed += run_suite(suites[i]);
  }

  printf("========= FAILED: %d =========\n", failed);
  return 0;
}

int run_suite(Suite* suite) {
  SRunner* suite_runner = srunner_create(suite);
  srunner_set_fork_status(suite_runner, CK_NOFORK);
  srunner_run_all(suite_runner, CK_NORMAL);
  int failed = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);
  return failed;
}

void fill_matrix(matrix_t* A, int mode) {
  double n = mode ? A->rows * A->columns : 1;
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      if (mode == 0)
        A->matrix[i][j] = n++;
      else if (mode == 1)
        A->matrix[i][j] = n--;
    }
  }
}

void set_matrix(matrix_t* A, ...) {
  va_list args;
  va_start(args, A);
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      A->matrix[i][j] = va_arg(args, double);
    }
  }
  va_end(args);
}

// void print_matrix(matrix_t A) {
//   for (int i = 0; i < A.rows; i++) {
//     for (int j = 0; j < A.columns; j++) {
//       printf("%lf ", A.matrix[i][j]);
//       if (j == A.columns - 1) putchar('\n');
//     }
//   }
// }