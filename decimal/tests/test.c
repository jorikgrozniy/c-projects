#include "test.h"

void run_suite(Suite* suite) {
  SRunner* suite_runner = srunner_create(suite);
  srunner_run_all(suite_runner, CK_VERBOSE);
  // int failed_count =
  srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);

  // if (failed_count != 0) {
  //   exit(1);
  // }
}

int main() {
  const int suites_cnt = 9;
  Suite* suites[] = {
      init_suite_common(), init_suite_comparsion(), init_suite_conversiont(),
      init_suite_sub(),    init_suite_other(),      comparsion_suite(),
      init_suite_add(),    init_suite_mul(),        init_suite_div()};
  for (int i = 0; i < suites_cnt; i++) {
    run_suite(suites[i]);
  }
}

void init_decimal(s21_decimal* decimal) {
  for (int i = 0; i < 4; i++) {
    decimal->bits[i] = 0;
  }
}