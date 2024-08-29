#ifndef S21_MAIN_TESTS_RUN_H
#define S21_MAIN_TESTS_RUN_H

#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"

Suite *s21_memchr_suite(void);
Suite *s21_memcmp_suite(void);
Suite *s21_memcpy_suite(void);
Suite *s21_memset_suite(void);
Suite *s21_strcspn_suite(void);
Suite *s21_strchr_suite(void);
Suite *s21_strerror_suite(void);
Suite *s21_strlen_suite(void);
Suite *s21_strncat_suite(void);
Suite *s21_strncmp_suite(void);
Suite *s21_strncpy_suite(void);
Suite *s21_strpbrk_suite(void);
Suite *s21_strrchr_suite(void);
Suite *s21_strstr_suite(void);
Suite *s21_strtok_suite(void);

Suite *s21_sprintf_suite(void);

Suite *s21_insert_suite(void);
Suite *s21_trim_suite(void);
Suite *s21_to_lower_suite(void);
Suite *s21_to_upper_suite(void);

long long int run_all_tests();
void add_all_suites_in_runner(SRunner **runner);
void add_string_h_suites_in_runner(SRunner **runner);
void add_string_cs_suites_in_runner(SRunner **runner);
void add_string_sprintf_suite_in_runner(SRunner **runner);
void output_failed_count(size_t failed_count);

#endif