#include "../../includes/s21_mainTestsRun.h"

START_TEST(s21_strncmp0) {
  char str1[16] = "1234567890";
  char str2[16] = "1234567890";
  s21_size_t n = 10;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(s21_strncmp1) {
  char str1[16] = "1234567890";
  char str2[16] = "1234507890";
  s21_size_t n = 0;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(s21_strncmp2) {
  char str1[16] = "";
  char str2[16] = "1234507890";
  s21_size_t n = 5;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(s21_strncmp3) {
  char str1[16] = "3334567890";
  char str2[16] = "1234507890";
  s21_size_t n = 3;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(s21_strncmp4) {
  char str1[16] = "33345678a90";
  char str2[16] = "1a234507890";
  s21_size_t n = 7;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(s21_strncmp5) {
  char str1[16] = "3334567890";
  char str2[16] = "1234507890";
  s21_size_t n = 0;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(s21_strncmp6) {
  char str1[16] = "3334567890";
  char str2[16] = "1234507890";
  s21_size_t n = 13;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(s21_strncmp7) {
  char str1[16] = "3334567890";
  char str2[16] = "1234507890";
  s21_size_t n = 3;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(s21_strncmp8) {
  char str1[16] = "";
  char str2[16] = "";
  s21_size_t n = 1;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(s21_strncmp9) {
  char str1[16] = "3334567890";
  char str2[16] = "";
  s21_size_t n = 3;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

Suite *s21_strncmp_suite() {
  Suite *s;
  TCase *tc_core;
  s = suite_create("s21_strncmp");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_strncmp0);
  tcase_add_test(tc_core, s21_strncmp1);
  tcase_add_test(tc_core, s21_strncmp2);
  tcase_add_test(tc_core, s21_strncmp3);
  tcase_add_test(tc_core, s21_strncmp4);
  tcase_add_test(tc_core, s21_strncmp5);
  tcase_add_test(tc_core, s21_strncmp6);
  tcase_add_test(tc_core, s21_strncmp7);
  tcase_add_test(tc_core, s21_strncmp8);
  tcase_add_test(tc_core, s21_strncmp9);
  suite_add_tcase(s, tc_core);
  return s;
}