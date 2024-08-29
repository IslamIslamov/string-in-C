#include "../../includes/s21_mainTestsRun.h"

//////////////////////////////////////////////////////
//***********************TO UPPER**********************//
START_TEST(to_upper_test1) {
  char str[] = "good job";
  char expected[] = "GOOD JOB";
  char *got = s21_to_upper(str);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(to_upper_test2) {
  char str[] = "empty";
  char expected[] = "EMPTY";
  char *got = s21_to_upper(str);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(to_upper_test3) {
  char str[] = "1+1*1";
  char expected[] = "1+1*1";
  char *got = s21_to_upper(str);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(to_upper_test4) {
  char str[] = " ";
  char expected[] = " ";
  char *got = s21_to_upper(str);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(to_upper_test5) {
  char str[] = "";
  char expected[] = "";
  char *got = s21_to_upper(str);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(test_to_upper_01) {
  const char *src = "Hello, World!";
  char *result = s21_to_upper(src);
  ck_assert_str_eq(result, "HELLO, WORLD!");
  free(result);
}
END_TEST

START_TEST(test_to_upper_02) {
  const char *src = "lowercase";
  char *result = s21_to_upper(src);
  ck_assert_str_eq(result, "LOWERCASE");
  free(result);
}
END_TEST

START_TEST(test_to_upper_03) {
  const char *src = "12345";
  char *result = s21_to_upper(src);
  ck_assert_str_eq(result, "12345");
  free(result);
}
END_TEST

START_TEST(test_to_upper_04) {
  const char *src = "!@#$%^&*()";
  char *result = s21_to_upper(src);
  ck_assert_str_eq(result, "!@#$%^&*()");
  free(result);
}
END_TEST

START_TEST(test_to_upper_05) {
  const char *src = "";
  char *result = s21_to_upper(src);
  ck_assert_str_eq(result, "");
  free(result);
}
END_TEST

Suite *s21_to_upper_suite(void) {
  Suite *s;
  TCase *tc_upper;
  s = suite_create("s21_to_upper");
  tc_upper = tcase_create("To Lower Func");
  suite_add_tcase(s, tc_upper);
  tcase_add_test(tc_upper, test_to_upper_01);
  tcase_add_test(tc_upper, test_to_upper_02);
  tcase_add_test(tc_upper, test_to_upper_03);
  tcase_add_test(tc_upper, test_to_upper_04);
  tcase_add_test(tc_upper, test_to_upper_05);
  tcase_add_test(tc_upper, to_upper_test1);
  tcase_add_test(tc_upper, to_upper_test2);
  tcase_add_test(tc_upper, to_upper_test3);
  tcase_add_test(tc_upper, to_upper_test4);
  tcase_add_test(tc_upper, to_upper_test5);

  suite_add_tcase(s, tc_upper);
  return s;
}