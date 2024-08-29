#include "../../includes/s21_mainTestsRun.h"

START_TEST(s21_strstr0) {
  char str1[] = "1234567890";
  char str2[] = "345";
  ck_assert_pstr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(s21_strstr1) {
  char str2[] = "1234567890";
  char str1[] = "345";
  ck_assert_pstr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(s21_strstr2) {
  char str1[] = "1234567890";
  char str2[] = "";
  ck_assert_pstr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(s21_strstr3) {
  char str1[] = "123477890";
  char str2[] = "345y";
  ck_assert_pstr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(s21_strstr4) {
  char str1[] = "";
  char str2[] = "345y";
  ck_assert_pstr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(s21_strstr5) {
  char str1[] = "";
  char str2[] = "";
  ck_assert_pstr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(s21_strstr6) {
  char str1[] = "123477890";
  char str2[] = "1";
  ck_assert_pstr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(s21_strstr7) {
  char str1[] = "123477890";
  char str2[] = "\0";
  ck_assert_pstr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(s21_strstr8) {
  char str1[] = "";
  char str2[] = "\0";
  ck_assert_pstr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

Suite *s21_strstr_suite() {
  Suite *s;
  TCase *tc_core;
  s = suite_create("s21_strstr");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_strstr0);
  tcase_add_test(tc_core, s21_strstr1);
  tcase_add_test(tc_core, s21_strstr2);
  tcase_add_test(tc_core, s21_strstr3);
  tcase_add_test(tc_core, s21_strstr4);
  tcase_add_test(tc_core, s21_strstr5);
  tcase_add_test(tc_core, s21_strstr6);
  tcase_add_test(tc_core, s21_strstr7);
  tcase_add_test(tc_core, s21_strstr8);
  suite_add_tcase(s, tc_core);
  return s;
}