#include "tests.h"

int main(void) {
  int failed = 0;
  Suite *s21_string_test[] = {
      test_strncmp(),   test_strncat(),   test_memset(),
      test_memcpy(),    test_memcmp(),    test_memchr(),
      test_strcspn(),   test_strerror(),  test_trim(),
      test_insert(),    test_to_upper(),  test_to_lower(),
      test_strstr(),    test_sscanf(),    test_strchr(),
      test_strlen(),    test_strncpy(),   test_strrchr(),
      test_strpbrk(),   test_strstr(),    test_strtok(),
      test_sprintf_d(), test_sprintf_c(), test_sprintf_s(),
      test_sprintf_f(), test_sprintf_u(), NULL};

  for (int i = 0; s21_string_test[i] != NULL; i++) {
    SRunner *sr = srunner_create(s21_string_test[i]);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }
  printf("========= FAILED: %d =========\n", failed);
  return 0;
}