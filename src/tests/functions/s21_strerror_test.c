#include "../../includes/s21_mainTestsRun.h"

START_TEST(s21_strerror0) {
  int number_error = 1;
  ck_assert_pstr_eq(strerror(number_error), s21_strerror(number_error));
}
END_TEST

START_TEST(s21_strerror1) {
  int number_error = 50;
  ck_assert_pstr_eq(strerror(number_error), s21_strerror(number_error));
}
END_TEST

START_TEST(s21_strerror2) {
  int number_error = 99;
  ck_assert_pstr_eq(strerror(number_error), s21_strerror(number_error));
}
END_TEST

START_TEST(s21_strerror3) {
  int number_error = 190;
  ck_assert_pstr_eq(strerror(number_error), s21_strerror(number_error));
}
END_TEST

START_TEST(s21_strerror4) {
  int number_error = -1;
  ck_assert_pstr_eq(strerror(number_error), s21_strerror(number_error));
}
END_TEST

Suite *s21_strerror_suite() {
  Suite *s;
  TCase *tc_core;
  s = suite_create("s21_strerror");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_strerror0);
  tcase_add_test(tc_core, s21_strerror1);
  tcase_add_test(tc_core, s21_strerror2);
  tcase_add_test(tc_core, s21_strerror3);
  tcase_add_test(tc_core, s21_strerror4);
  suite_add_tcase(s, tc_core);
  return s;
}