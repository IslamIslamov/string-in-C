#include "../includes/s21_mainTestsRun.h"

int main() {
  // output_failed_count(run_all_tests());
  run_all_tests();

  return 0;
}

/*void output_failed_count(size_t failed_count) {
  printf("FAILED : %ld", failed_count);
} */

long long int run_all_tests() {
  SRunner *runner = srunner_create(NULL);

  add_all_suites_in_runner(&runner);

  srunner_run_all(runner, CK_NORMAL);

  size_t failed_count = srunner_ntests_failed(runner);

  srunner_free(runner);
  return failed_count;
}

void add_all_suites_in_runner(SRunner **runner) {
  add_string_sprintf_suite_in_runner(runner);
  add_string_h_suites_in_runner(runner);
  add_string_cs_suites_in_runner(runner);
}

void add_string_h_suites_in_runner(SRunner **runner) {
  srunner_add_suite(*runner, s21_strncat_suite());
  srunner_add_suite(*runner, s21_strlen_suite());
  srunner_add_suite(*runner, s21_memchr_suite());
  srunner_add_suite(*runner, s21_memcmp_suite());
  srunner_add_suite(*runner, s21_memcpy_suite());
  srunner_add_suite(*runner, s21_memset_suite());
  srunner_add_suite(*runner, s21_strcspn_suite());

  srunner_add_suite(*runner, s21_strchr_suite());
  srunner_add_suite(*runner, s21_strerror_suite());
  srunner_add_suite(*runner, s21_strncmp_suite());
  srunner_add_suite(*runner, s21_strncpy_suite());
  srunner_add_suite(*runner, s21_strpbrk_suite());
  srunner_add_suite(*runner, s21_strrchr_suite());
  srunner_add_suite(*runner, s21_strstr_suite());
  srunner_add_suite(*runner, s21_strtok_suite());
}

void add_string_sprintf_suite_in_runner(SRunner **runner) {
  srunner_add_suite(*runner, s21_sprintf_suite());
}

void add_string_cs_suites_in_runner(SRunner **runner) {
  srunner_add_suite(*runner, s21_insert_suite());
  srunner_add_suite(*runner, s21_to_lower_suite());
  srunner_add_suite(*runner, s21_to_upper_suite());
  srunner_add_suite(*runner, s21_trim_suite());
}
