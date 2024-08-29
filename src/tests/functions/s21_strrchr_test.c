#include "../../includes/s21_mainTestsRun.h"

START_TEST(s21_strrchr0) {
  char str1[] = "1234567890";
  int ch = '6';
  ck_assert_pstr_eq(strrchr(str1, ch), s21_strrchr(str1, ch));
}
END_TEST

START_TEST(s21_strrchr1) {
  char str1[] = "1234567890";
  int ch = 'a';
  ck_assert_pstr_eq(strrchr(str1, ch), s21_strrchr(str1, ch));
}
END_TEST

START_TEST(s21_strrchr2) {
  char str1[] = "12345";
  int ch = '\0';
  ck_assert_pstr_eq(strrchr(str1, ch), s21_strrchr(str1, ch));
}
END_TEST

START_TEST(s21_strrchr3) {
  char str1[] = "";
  int ch = '1';
  ck_assert_pstr_eq(strrchr(str1, ch), s21_strrchr(str1, ch));
}
END_TEST
START_TEST(s21_strrchr4) {
  char str1[] = "1234567890";
  int ch = '\n';
  ck_assert_pstr_eq(strrchr(str1, ch), s21_strrchr(str1, ch));
}
END_TEST
START_TEST(s21_strrchr5) {
  char str1[] = "12345555555567890";
  int ch = '5';
  ck_assert_pstr_eq(strrchr(str1, ch), s21_strrchr(str1, ch));
}
END_TEST
START_TEST(s21_strrchr6) {
  char str1[] = "\0";
  int ch = '\0';
  ck_assert_pstr_eq(strrchr(str1, ch), s21_strrchr(str1, ch));
}
END_TEST
START_TEST(s21_strrchr7) {
  char str1[] = "";
  int ch = '\0';
  ck_assert_pstr_eq(strrchr(str1, ch), s21_strrchr(str1, ch));
}
END_TEST
START_TEST(s21_strrchr8) {
  char str1[] = "1";
  int ch = '1';
  ck_assert_pstr_eq(strrchr(str1, ch), s21_strrchr(str1, ch));
}
END_TEST

Suite *s21_strrchr_suite() {
  Suite *s;
  TCase *tc_core;
  s = suite_create("s21_strrchr");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_strrchr0);
  tcase_add_test(tc_core, s21_strrchr1);
  tcase_add_test(tc_core, s21_strrchr2);
  tcase_add_test(tc_core, s21_strrchr3);
  tcase_add_test(tc_core, s21_strrchr4);
  tcase_add_test(tc_core, s21_strrchr5);
  tcase_add_test(tc_core, s21_strrchr6);
  tcase_add_test(tc_core, s21_strrchr7);
  tcase_add_test(tc_core, s21_strrchr8);
  suite_add_tcase(s, tc_core);
  return s;
}