#include "../../includes/s21_mainTestsRun.h"

START_TEST(s21_strpbrk0) {
  char str[] = "0123456789";
  char sym[] = "369";
  ck_assert_pstr_eq(strpbrk(str, sym), s21_strpbrk(str, sym));
}
END_TEST

START_TEST(s21_strpbrk1) {
  char str[] = "0123456789";
  char sym[] = "aaa";
  ck_assert_pstr_eq(strpbrk(str, sym), s21_strpbrk(str, sym));
}
END_TEST

START_TEST(s21_strpbrk2) {
  char str[] = "";
  char sym[] = "369";
  ck_assert_pstr_eq(strpbrk(str, sym), s21_strpbrk(str, sym));
}
END_TEST

START_TEST(s21_strpbrk3) {
  char str[] = "0123456789";
  char sym[] = "";
  ck_assert_pstr_eq(strpbrk(str, sym), s21_strpbrk(str, sym));
}
END_TEST

START_TEST(s21_strpbrk4) {
  char str[] = "";
  char sym[] = "";
  ck_assert_pstr_eq(strpbrk(str, sym), s21_strpbrk(str, sym));
}
END_TEST

START_TEST(s21_strpbrk5) {
  char str[] = "Hello";
  char sym[] = "hello";
  ck_assert_pstr_eq(strpbrk(str, sym), s21_strpbrk(str, sym));
}
END_TEST

START_TEST(s21_strpbrk6) {
  char str[] = "01";
  char sym[] = "1";
  ck_assert_pstr_eq(strpbrk(str, sym), s21_strpbrk(str, sym));
}
END_TEST

START_TEST(s21_strpbrk7) {
  char str[] = "1101012012012";
  char sym[] = "01";
  ck_assert_pstr_eq(strpbrk(str, sym), s21_strpbrk(str, sym));
}
END_TEST

START_TEST(s21_strpbrk8) {
  char str[] = "Hello World";
  char sym[] = "Wo";
  ck_assert_pstr_eq(strpbrk(str, sym), s21_strpbrk(str, sym));
}
END_TEST

Suite *s21_strpbrk_suite() {
  Suite *s;
  TCase *tc_core;
  s = suite_create("s21_strpbrk");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_strpbrk0);
  tcase_add_test(tc_core, s21_strpbrk1);
  tcase_add_test(tc_core, s21_strpbrk2);
  tcase_add_test(tc_core, s21_strpbrk3);
  tcase_add_test(tc_core, s21_strpbrk4);
  tcase_add_test(tc_core, s21_strpbrk5);
  tcase_add_test(tc_core, s21_strpbrk6);
  tcase_add_test(tc_core, s21_strpbrk7);
  tcase_add_test(tc_core, s21_strpbrk8);
  suite_add_tcase(s, tc_core);
  return s;
}