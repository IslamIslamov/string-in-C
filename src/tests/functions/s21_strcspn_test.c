#include "../../includes/s21_mainTestsRun.h"

START_TEST(s21_strcspn0) {
  char s1[] = "ABC-ABC";
  char s2[] = "-";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(s21_strcspn1) {
  char s1[] = "ksldfldlsfldsflkdsfdslflsdf";
  char s2[] = "abc";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(s21_strcspn2) {
  char s1[] = "ksldfldlsfldsflkdsfdslflsdf";
  char s2[] = " ";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST
START_TEST(s21_strcspn3) {
  char s1[] = "ksldfldlsfldsflkdsfdslflsdf";
  char s2[] = "ksld";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(s21_strcspn4) {
  char s1[] = "1234567890";
  char s2[] = "1234567890";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(s21_strcspn5) {
  char s1[] = " ";
  char s2[] = "1";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(s21_strcspn6) {
  char s1[] = "";
  char s2[] = "1234567890";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(s21_strcspn7) {
  char s1[] = "1234";
  char s2[] = "";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(s21_strcspn8) {
  char s1[] = "";
  char s2[] = "";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

Suite *s21_strcspn_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("s21_strcspn");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_strcspn0);
  tcase_add_test(tc_core, s21_strcspn1);
  tcase_add_test(tc_core, s21_strcspn2);
  tcase_add_test(tc_core, s21_strcspn3);
  tcase_add_test(tc_core, s21_strcspn4);
  tcase_add_test(tc_core, s21_strcspn5);
  tcase_add_test(tc_core, s21_strcspn6);
  tcase_add_test(tc_core, s21_strcspn7);
  tcase_add_test(tc_core, s21_strcspn8);

  suite_add_tcase(s, tc_core);

  return s;
}
