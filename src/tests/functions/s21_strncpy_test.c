#include "../../includes/s21_mainTestsRun.h"

START_TEST(s21_strncpy0) {
  char src[] = "12345\0006789";
  char dst1[] = "1111111111";
  char s21_src[] = "12345\0006789";
  char s21_dst1[] = "1111111111";
  s21_size_t n = 3;
  ck_assert_str_eq(strncpy(dst1, src, n), s21_strncpy(s21_dst1, s21_src, n));
}
END_TEST

START_TEST(s21_strncpy1) {
  char src[] = "12345\0006789";
  char dst1[] = "1111111111";
  char s21_src[] = "12345\0006789";
  char s21_dst1[] = "1111111111";
  s21_size_t n = 5;
  ck_assert_str_eq(strncpy(dst1, src, n), s21_strncpy(s21_dst1, s21_src, n));
}
END_TEST

START_TEST(s21_strncpy2) {
  char src[] = "12345\00067899999999999999999764i90hjdgctyd9999999";
  char dst1[] = "1111111111";
  char s21_src[] = "12345\0006789";
  char s21_dst1[] = "1111111111";
  s21_size_t n = 10;
  ck_assert_str_eq(strncpy(dst1, src, n), s21_strncpy(s21_dst1, s21_src, n));
}
END_TEST

START_TEST(s21_strncpy3) {
  char src[] = "";
  char dst1[] = "1111111111";
  char s21_src[] = "";
  char s21_dst1[] = "1111111111";
  s21_size_t n = 3;
  ck_assert_str_eq(strncpy(dst1, src, n), s21_strncpy(s21_dst1, s21_src, n));
}
END_TEST

START_TEST(s21_strncpy4) {
  char src[] = "12345\0006789";
  char dst1[] = "1111111111";
  char s21_src[] = "12345\0006789";
  char s21_dst1[] = "1111111111";
  s21_size_t n = 0;
  ck_assert_str_eq(strncpy(dst1, src, n), s21_strncpy(s21_dst1, s21_src, n));
}
END_TEST
START_TEST(s21_strncpy5) {
  char src[] = "12345\0006789";
  char dst1[] = "1111111111";
  char s21_src[] = "12345\0006789";
  char s21_dst1[] = "1111111111";
  s21_size_t n = 1;
  ck_assert_str_eq(strncpy(dst1, src, n), s21_strncpy(s21_dst1, s21_src, n));
}
END_TEST
START_TEST(s21_strncpy6) {
  char src[] = "qwertyuiop";
  char dst1[] = "1111111111111111111111111111";
  char s21_src[] = "qwertyuiop";
  char s21_dst1[] = "1111111111111111111111111111";
  s21_size_t n = 3;
  ck_assert_str_eq(strncpy(dst1, src, n), s21_strncpy(s21_dst1, s21_src, n));
}
END_TEST
START_TEST(s21_strncpy7) {
  char src[] = "";
  char dst1[] = "1";
  char s21_src[] = "";
  char s21_dst1[] = "1";
  s21_size_t n = 1;
  ck_assert_str_eq(strncpy(dst1, src, n), s21_strncpy(s21_dst1, s21_src, n));
}
END_TEST
START_TEST(s21_strncpy8) {
  char src[] = "";
  char dst1[] = "1111111111";
  char s21_src[] = "";
  char s21_dst1[] = "1111111111";
  s21_size_t n = 3;
  ck_assert_str_eq(strncpy(dst1, src, n), s21_strncpy(s21_dst1, s21_src, n));
}
END_TEST

Suite *s21_strncpy_suite() {
  Suite *s;
  TCase *tc_core;
  s = suite_create("s21_strncpy");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_strncpy0);
  tcase_add_test(tc_core, s21_strncpy1);
  tcase_add_test(tc_core, s21_strncpy2);
  tcase_add_test(tc_core, s21_strncpy3);
  tcase_add_test(tc_core, s21_strncpy4);
  tcase_add_test(tc_core, s21_strncpy5);
  tcase_add_test(tc_core, s21_strncpy6);
  tcase_add_test(tc_core, s21_strncpy7);
  tcase_add_test(tc_core, s21_strncpy8);
  suite_add_tcase(s, tc_core);
  return s;
}