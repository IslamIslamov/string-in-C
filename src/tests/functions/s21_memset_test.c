#include "../../includes/s21_mainTestsRun.h"

START_TEST(s21_memset0) {
  char str[] = "Lindf fkdlsfjot fdosfi2";
  ck_assert_str_eq(memset(str, 'S', 5), s21_memset(str, 'S', 5));
}
END_TEST

START_TEST(s21_memset1) {
  char str[] = "Lindf fkdlsfjot fdosfi2";
  ck_assert_str_eq(memset(str, 'S', 1), s21_memset(str, 'S', 1));
}
END_TEST

START_TEST(s21_memset2) {
  char str[] = "Lindf fkdlsfjot fdosfi2";
  ck_assert_str_eq(memset(str, 'S', 23), s21_memset(str, 'S', 23));
}
END_TEST

START_TEST(s21_memset3) {
  char str[] = "Lindf fkdlsfjot fdosfi2";
  ck_assert_str_eq(memset(str, 0, 23), s21_memset(str, 0, 23));
}
END_TEST

START_TEST(s21_memset4) {
  char str[] = "Lindf fkdlsfjot fdosfi2";
  ck_assert_str_eq(memset(str, 700, 23), s21_memset(str, 700, 23));
}
END_TEST

START_TEST(s21_memset5) {
  char str[] = "2";
  ck_assert_str_eq(memset(str, 700, 1), s21_memset(str, 700, 1));
}
END_TEST

START_TEST(s21_memset6) {
  char str[] = "2";
  ck_assert_str_eq(memset(str, '\0', 1), s21_memset(str, '\0', 1));
}
END_TEST

Suite *s21_memset_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("s21_memset");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_memset0);
  tcase_add_test(tc_core, s21_memset1);
  tcase_add_test(tc_core, s21_memset2);
  tcase_add_test(tc_core, s21_memset3);
  tcase_add_test(tc_core, s21_memset4);
  tcase_add_test(tc_core, s21_memset5);
  tcase_add_test(tc_core, s21_memset6);

  suite_add_tcase(s, tc_core);
  return s;
}
