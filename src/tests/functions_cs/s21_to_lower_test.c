#include "../../includes/s21_mainTestsRun.h"

//////////////////////////////////////////////////////
//***********************TO LOWER**********************//
START_TEST(to_lower_test1) {
  char str[] = "ShLePa V TaZ1Ke?";
  char expected[] = "shlepa v taz1ke?";
  char *got = s21_to_lower(str);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(to_lower_test2) {
  char str[] = "123456789Q";
  char expected[] = "123456789q";
  char *got = s21_to_lower(str);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(to_lower_test3) {
  char str[] = "Space created";
  char expected[] = "space created";
  char *got = s21_to_lower(str);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(to_lower_test4) {
  char str[] = "";
  char expected[] = "";
  char *got = s21_to_lower(str);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(to_lower_test5) {
  char str[] = "";
  char expected[] = "";
  char *got = s21_to_lower(str);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(test_to_lower_01) {
  const char *src = "Hello, World!";
  char *result = s21_to_lower(src);
  ck_assert_str_eq(result, "hello, world!");
  free(result);
}
END_TEST

START_TEST(test_to_lower_02) {
  const char *src = "UPPERCASE";
  char *result = s21_to_lower(src);
  ck_assert_str_eq(result, "uppercase");
  free(result);
}
END_TEST

START_TEST(test_to_lower_03) {
  const char *src = "12345";
  char *result = s21_to_lower(src);
  ck_assert_str_eq(result, "12345");
  free(result);
}
END_TEST

START_TEST(test_to_lower_04) {
  const char *src = "!@#$%^&*()";
  char *result = s21_to_lower(src);
  ck_assert_str_eq(result, "!@#$%^&*()");
  free(result);
}
END_TEST

START_TEST(test_to_lower_05) {
  const char *src = "";
  char *result = s21_to_lower(src);
  ck_assert_str_eq(result, "");
  free(result);
}
END_TEST

Suite *s21_to_lower_suite(void) {
  Suite *s;
  TCase *tc_lower;
  s = suite_create("s21_to_lower");
  tc_lower = tcase_create("To Lower Func");
  suite_add_tcase(s, tc_lower);
  tcase_add_test(tc_lower, test_to_lower_01);
  tcase_add_test(tc_lower, test_to_lower_02);
  tcase_add_test(tc_lower, test_to_lower_03);
  tcase_add_test(tc_lower, test_to_lower_04);
  tcase_add_test(tc_lower, test_to_lower_05);
  tcase_add_test(tc_lower, to_lower_test1);
  tcase_add_test(tc_lower, to_lower_test2);
  tcase_add_test(tc_lower, to_lower_test3);
  tcase_add_test(tc_lower, to_lower_test4);
  tcase_add_test(tc_lower, to_lower_test5);

  suite_add_tcase(s, tc_lower);
  return s;
}