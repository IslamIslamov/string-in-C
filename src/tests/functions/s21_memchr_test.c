#include "../../includes/s21_mainTestsRun.h"

// s21_memchr

START_TEST(s21_memchr0) {
  char str[100] = {'\0'};
  int c = 32;
  for (int i = 0; i < 100; i++) {
    srand(i);
    int tmp = rand();
    int n = tmp % 126 < 32 ? tmp % 126 + 32 : tmp % 126;
    str[i] = (char)n;
    if (i % 15 == 0) {
      c = n;
    }
    if (i % 10 == 0) {
      ck_assert_pstr_eq((char *)memchr(str, c, 100),
                        (char *)s21_memchr(str, c, 100));
    }
  }
}
END_TEST

START_TEST(s21_memchr1) {
  char str[] = "https://something.com/dot.zero";
  int c = ' ';
  ck_assert_pstr_eq((char *)memchr(str, c, 31), (char *)s21_memchr(str, c, 31));
}
END_TEST

START_TEST(s21_memchr2) {
  char str[] = "https://something.com/dot.zero";
  int c = '.';
  ck_assert_pstr_eq((char *)memchr(str, c, 31), (char *)s21_memchr(str, c, 31));
}
END_TEST

START_TEST(s21_memchr3) {
  char str[] = "https://something.com/dot.zero";
  int c = 'h';
  ck_assert_pstr_eq((char *)memchr(str, c, 0), (char *)s21_memchr(str, c, 0));
}
END_TEST

START_TEST(s21_memchr4) {
  char str[] = "https:";
  int c = '\0';
  ck_assert_pstr_eq((char *)memchr(str, c, 7), (char *)s21_memchr(str, c, 7));
}
END_TEST

START_TEST(s21_memchr5) {
  char str[] = "";
  int c = '1';
  ck_assert_pstr_eq((char *)memchr(str, c, 1), (char *)s21_memchr(str, c, 1));
}
END_TEST

Suite *s21_memchr_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("s21_memchr");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_memchr0);
  tcase_add_test(tc_core, s21_memchr1);
  tcase_add_test(tc_core, s21_memchr2);
  tcase_add_test(tc_core, s21_memchr3);
  tcase_add_test(tc_core, s21_memchr4);
  tcase_add_test(tc_core, s21_memchr5);

  suite_add_tcase(s, tc_core);
  return s;
}
