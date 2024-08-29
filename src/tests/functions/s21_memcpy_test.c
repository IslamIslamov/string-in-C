#include "../../includes/s21_mainTestsRun.h"

// s21_memcpy
START_TEST(s21_memcpy0) {
  char dest[50] = {'\0'};
  char src[] = "this line one";
  ck_assert_str_eq(memcpy(dest, src, 14), s21_memcpy(dest, src, 14));
}
END_TEST

START_TEST(s21_memcpy1) {
  char dest[50] = {'\0'};
  char src[] = "this line one";
  ck_assert_str_eq(memcpy(dest, src, 5), s21_memcpy(dest, src, 5));
}
END_TEST

START_TEST(s21_memcpy2) {
  char dest[50] = {'\0'};
  char src[] = "this line one";
  ck_assert_str_eq(memcpy(dest, src, 0), s21_memcpy(dest, src, 0));
}
END_TEST

START_TEST(s21_memcpy3) {
  char dest[50] = {'\0'};
  char src[] = "";
  ck_assert_str_eq(memcpy(dest, src, 1), s21_memcpy(dest, src, 1));
}
END_TEST

Suite *s21_memcpy_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("s21_memcpy");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_memcpy0);
  tcase_add_test(tc_core, s21_memcpy1);
  tcase_add_test(tc_core, s21_memcpy2);
  tcase_add_test(tc_core, s21_memcpy3);

  suite_add_tcase(s, tc_core);
  return s;
}
