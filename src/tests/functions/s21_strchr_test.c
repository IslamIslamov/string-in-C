#include "../../includes/s21_mainTestsRun.h"

START_TEST(s21_strchr0) {
  char str1[] = "1234567890";
  int ch = '6';
  ck_assert_pstr_eq(strchr(str1, ch), s21_strchr(str1, ch));
}
END_TEST

START_TEST(s21_strchr1) {
  char str1[] = "1234567890";
  int ch = 'a';
  ck_assert_pstr_eq(strchr(str1, ch), s21_strchr(str1, ch));
}
END_TEST

START_TEST(s21_strchr2) {
  char str1[] = "12345";
  int ch = '6';
  ck_assert_pstr_eq(strchr(str1, ch), s21_strchr(str1, ch));
}
END_TEST

START_TEST(s21_strchr3) {
  char str1[] = "1234567890";
  int ch = '\n';
  ck_assert_pstr_eq(strchr(str1, ch), s21_strchr(str1, ch));
}
END_TEST

START_TEST(s21_strchr4) {
  char str1[] = "";
  int ch = 'a';
  ck_assert_pstr_eq(strchr(str1, ch), s21_strchr(str1, ch));
}
END_TEST

START_TEST(s21_strchr5) {
  char str1[] = "AA";
  int ch = 'a';
  ck_assert_pstr_eq(strchr(str1, ch), s21_strchr(str1, ch));
}
END_TEST

START_TEST(s21_strchr6) {
  char str1[] = "1234567890ttt";
  int ch = 't';
  ck_assert_pstr_eq(strchr(str1, ch), s21_strchr(str1, ch));
}
END_TEST

START_TEST(s21_strchr7) {
  char str1[] = "";
  int ch = '\0';
  ck_assert_pstr_eq(strchr(str1, ch), s21_strchr(str1, ch));
}
END_TEST

START_TEST(s21_strchr8) {
  char str1[] = "1234567890";
  int ch = '\0';
  ck_assert_pstr_eq(strchr(str1, ch), s21_strchr(str1, ch));
}
END_TEST

START_TEST(s21_strchr9) {
  char str1[] = "a";
  int ch = 'a';
  ck_assert_pstr_eq(strchr(str1, ch), s21_strchr(str1, ch));
}
END_TEST

Suite *s21_strchr_suite() {
  Suite *s;
  TCase *tc_core;
  s = suite_create("s21_strchr");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_strchr0);
  tcase_add_test(tc_core, s21_strchr1);
  tcase_add_test(tc_core, s21_strchr2);
  tcase_add_test(tc_core, s21_strchr3);
  tcase_add_test(tc_core, s21_strchr4);
  tcase_add_test(tc_core, s21_strchr5);
  tcase_add_test(tc_core, s21_strchr6);
  tcase_add_test(tc_core, s21_strchr7);
  tcase_add_test(tc_core, s21_strchr8);
  tcase_add_test(tc_core, s21_strchr9);
  suite_add_tcase(s, tc_core);
  return s;
}