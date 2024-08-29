#include "../../includes/s21_mainTestsRun.h"

// s21_memcmp
START_TEST(s21_memcmp0) {
  char s1[] = "ABC";
  char s2[] = "abc";
  ck_assert_int_eq(memcmp(s1, s2, 3), s21_memcmp(s1, s2, 3));
}
END_TEST

START_TEST(s21_memcmp1) {
  char s1[] = "ABC";
  ck_assert_int_eq(memcmp(s1, s1, 3), s21_memcmp(s1, s1, 3));
}
END_TEST

START_TEST(s21_memcmp2) {
  char s1[] = "ABC";
  ck_assert_int_eq(memcmp(s1, s1, 0), s21_memcmp(s1, s1, 0));
}
END_TEST

START_TEST(s21_memcmp3) {
  char s1[] = "ABC";
  ck_assert_int_eq(memcmp(s1, s1, 10), s21_memcmp(s1, s1, 10));
}
END_TEST

START_TEST(s21_memcmp4) {
  char s1[] = "ABCdddddd";
  char s2[] = "ABC2ddddd";

  ck_assert_int_eq(memcmp(s1, s2, 3), s21_memcmp(s1, s2, 3));
}
END_TEST

START_TEST(s21_memcmp5) {
  char *s1 = "";
  ck_assert_int_eq(memcmp(s1, s1, 3), s21_memcmp(s1, s1, 3));
}
END_TEST

Suite *s21_memcmp_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("s21_memcmp");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_memcmp0);
  tcase_add_test(tc_core, s21_memcmp1);
  tcase_add_test(tc_core, s21_memcmp2);
  tcase_add_test(tc_core, s21_memcmp3);
  tcase_add_test(tc_core, s21_memcmp4);
  tcase_add_test(tc_core, s21_memcmp5);

  suite_add_tcase(s, tc_core);
  return s;
}
