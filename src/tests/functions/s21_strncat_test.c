#include "../../includes/s21_mainTestsRun.h"

START_TEST(s21_strncat0) {
  char app[100] = "12345";
  char src1[10] = "000";
  s21_size_t n = 10;
  ck_assert_pstr_eq(strncat(src1, app, n), s21_strncat(src1, app, n));
}
END_TEST

START_TEST(s21_strncat1) {
  char app[10] = "12345";
  char src1[10] = "000";
  s21_size_t n = 1;
  ck_assert_pstr_eq(strncat(src1, app, n), s21_strncat(src1, app, n));
}
END_TEST

START_TEST(s21_strncat2) {
  char app[10] = "12345";
  char src1[10] = "000";
  s21_size_t n = 3;
  ck_assert_pstr_eq(strncat(src1, app, n), s21_strncat(src1, app, n));
}
END_TEST

START_TEST(s21_strncat3) {
  char app[10] = "1";
  char src1[10] = "";
  s21_size_t n = 5;
  ck_assert_pstr_eq(strncat(src1, app, n), s21_strncat(src1, app, n));
}
END_TEST

START_TEST(s21_strncat4) {
  char app[10] = "err";
  char src1[10] = "\0";
  s21_size_t n = 5;
  ck_assert_pstr_eq(strncat(src1, app, n), s21_strncat(src1, app, n));
}
END_TEST

START_TEST(s21_strncat5) {
  char app[10] = "123456";
  char src1[10] = "45";
  s21_size_t n = 0;
  ck_assert_pstr_eq(strncat(src1, app, n), s21_strncat(src1, app, n));
}
END_TEST

START_TEST(s21_strncat6) {
  char app[10] = "123";
  char src1[10] = "1";
  s21_size_t n = 1;
  ck_assert_pstr_eq(strncat(src1, app, n), s21_strncat(src1, app, n));
}
END_TEST

START_TEST(s21_strncat7) {
  char app[10] = "";
  char src1[10] = "1";
  s21_size_t n = 5;
  ck_assert_pstr_eq(strncat(src1, app, n), s21_strncat(src1, app, n));
}
END_TEST

START_TEST(s21_strncat8) {
  char app[10] = "";
  char src1[10] = "";
  s21_size_t n = 5;
  ck_assert_pstr_eq(strncat(src1, app, n), s21_strncat(src1, app, n));
}
END_TEST

Suite *s21_strncat_suite() {
  Suite *s;
  TCase *tc_core;
  s = suite_create("s21_strncat");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_strncat0);
  tcase_add_test(tc_core, s21_strncat1);
  tcase_add_test(tc_core, s21_strncat2);
  tcase_add_test(tc_core, s21_strncat3);
  tcase_add_test(tc_core, s21_strncat4);
  tcase_add_test(tc_core, s21_strncat5);
  tcase_add_test(tc_core, s21_strncat6);
  tcase_add_test(tc_core, s21_strncat7);
  tcase_add_test(tc_core, s21_strncat8);
  suite_add_tcase(s, tc_core);
  return s;
}