#include "../../includes/s21_mainTestsRun.h"

//////////////////////////////////////////////////////
//***********************INSERT**********************//
START_TEST(insert_test1) {
  char str[] = "Shlepa";
  char src[] = "I love my . He is very kind!";
  size_t index = 10;
  char expected[] = "I love my Shlepa. He is very kind!";
  char *got = (char *)s21_insert(src, str, index);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(insert_test2) {
  char str[] = "Hello, ";
  char src[] = "Aboba!";
  size_t index = 0;
  char expected[] = "Hello, Aboba!";
  char *got = (char *)s21_insert(src, str, index);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(insert_test3) {
  char str[] = "";
  char src[] = "";
  size_t index = 0;
  char *expected = "";
  char *got = (char *)s21_insert(src, str, index);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(insert_test4) {
  char *src = S21_NULL;
  char *str = S21_NULL;
  size_t index = 100;
  char *expected = S21_NULL;
  char *got = (char *)s21_insert(src, str, index);
  ck_assert_ptr_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(insert_test5) {
  char str[] = "Monkey";
  char src[] = "Space  ";
  size_t index = 6;
  char expected[] = "Space Monkey ";
  char *got = (char *)s21_insert(src, str, index);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(insert_test6) {
  const char *src = "";
  const char *str = "";
  size_t start_index = 0;
  char *result = s21_insert(src, str, start_index);
  ck_assert_str_eq(result, "");
  free(result);
}
END_TEST

START_TEST(insert_test7) {
  const char *src = "";
  const char *str = "bbb";
  size_t start_index = 0;
  char *result = s21_insert(src, str, start_index);
  ck_assert_str_eq(result, "bbb");
  free(result);
}
END_TEST

START_TEST(insert_test8) {
  const char *src = "aaaa";
  const char *str = "";
  size_t start_index = 2;
  char *result = s21_insert(src, str, start_index);
  ck_assert_str_eq(result, "aaaa");
  free(result);
}
END_TEST

START_TEST(insert_test9) {
  const char *src = "aaaa";
  const char *str = "bbb";
  size_t start_index = 5;
  char *expected_result = "aaaabbb";
  char *result = s21_insert(src, str, start_index);
  ck_assert_str_eq(result, expected_result);
  free(result);
}
END_TEST

Suite *s21_insert_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("s21_insert");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, insert_test1);
  tcase_add_test(tc_core, insert_test2);
  tcase_add_test(tc_core, insert_test3);
  tcase_add_test(tc_core, insert_test4);
  tcase_add_test(tc_core, insert_test5);
  tcase_add_test(tc_core, insert_test6);
  tcase_add_test(tc_core, insert_test7);
  tcase_add_test(tc_core, insert_test8);
  tcase_add_test(tc_core, insert_test9);

  suite_add_tcase(s, tc_core);
  return s;
}
