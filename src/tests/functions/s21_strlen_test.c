#include "../../includes/s21_mainTestsRun.h"

START_TEST(s21_strlen0) {
  char str[] = "";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(s21_strlen1) {
  char str[] = "\0";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(s21_strlen2) {
  char str[] = "123456789";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(s21_strlen3) {
  char str[] = "Qwerty Uiop";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(s21_strlen4) {
  char str[] = "3";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

Suite *s21_strlen_suite() {
  Suite *s;
  TCase *tc_core;
  s = suite_create("s21_strlen");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_strlen0);
  tcase_add_test(tc_core, s21_strlen1);
  tcase_add_test(tc_core, s21_strlen2);
  tcase_add_test(tc_core, s21_strlen3);
  tcase_add_test(tc_core, s21_strlen4);
  suite_add_tcase(s, tc_core);
  return s;
}
