#include "../../includes/s21_mainTestsRun.h"

START_TEST(s21_strtok0) {
  char str[] = "test1/test2/test3/test4";
  char s21_str[] = "test1/test2/test3/test4";
  char delim[] = "/";
  char *s21_result = s21_strtok(s21_str, delim);
  char *base_result = strtok(str, delim);
  ck_assert_uint_eq(s21_strlen(s21_result), s21_strlen(base_result));
  ck_assert_pstr_eq(s21_result, base_result);
  while ((s21_result != 0) && (base_result != 0)) {
    s21_result = s21_strtok(NULL, delim);
    base_result = strtok(NULL, delim);
    ck_assert_pstr_eq(s21_result, base_result);
  }
}
END_TEST

START_TEST(s21_strtok1) {
  char str[] = "test1/test2/test3/test4";
  char s21_str[] = "test1/test2/test3/test4";
  char delim[] = "/t";
  char *s21_result = s21_strtok(s21_str, delim);
  char *base_result = strtok(str, delim);
  ck_assert_uint_eq(s21_strlen(s21_result), s21_strlen(base_result));
  ck_assert_pstr_eq(s21_result, base_result);
  while ((s21_result != 0) && (base_result != 0)) {
    s21_result = s21_strtok(NULL, delim);
    base_result = strtok(NULL, delim);
    ck_assert_pstr_eq(s21_result, base_result);
  }
}
END_TEST

START_TEST(s21_strtok2) {
  char str[] = "test1/test2/test3/test4";
  char s21_str[] = "test1/test2/test3/test4";
  char delim[] = "/ae ";
  char *s21_result = s21_strtok(s21_str, delim);
  char *base_result = strtok(str, delim);
  ck_assert_uint_eq(s21_strlen(s21_result), s21_strlen(base_result));
  ck_assert_pstr_eq(s21_result, base_result);
  while ((s21_result != 0) && (base_result != 0)) {
    s21_result = s21_strtok(NULL, delim);
    base_result = strtok(NULL, delim);
    ck_assert_pstr_eq(s21_result, base_result);
  }
}
END_TEST

START_TEST(s21_strtok3) {
  char str[] = "  test1/test  2 /  test3/test4";
  char s21_str[] = "  test1/test  2 /  test3/test4";
  char delim[] = "/";
  char *s21_result = s21_strtok(s21_str, delim);
  char *base_result = strtok(str, delim);
  ck_assert_uint_eq(s21_strlen(s21_result), s21_strlen(base_result));
  ck_assert_pstr_eq(s21_result, base_result);
  while ((s21_result != 0) && (base_result != 0)) {
    s21_result = s21_strtok(NULL, delim);
    base_result = strtok(NULL, delim);
    ck_assert_pstr_eq(s21_result, base_result);
  }
}
END_TEST

START_TEST(s21_strtok4) {
  char str[] = "";
  char s21_str[] = "";
  char delim[] = "/";
  char *s21_result = s21_strtok(s21_str, delim);
  char *base_result = strtok(str, delim);
  ck_assert_uint_eq(s21_strlen(s21_result), s21_strlen(base_result));
  ck_assert_pstr_eq(s21_result, base_result);
  while ((s21_result != 0) && (base_result != 0)) {
    s21_result = s21_strtok(NULL, delim);
    base_result = strtok(NULL, delim);
    ck_assert_pstr_eq(s21_result, base_result);
  }
}
END_TEST

START_TEST(s21_strtok5) {
  char str[] = "test1/test2/test3/test4";
  char s21_str[] = "test1/test2/test3/test4";
  char delim[] = "";
  char *s21_result = s21_strtok(s21_str, delim);
  char *base_result = strtok(str, delim);
  ck_assert_uint_eq(s21_strlen(s21_result), s21_strlen(base_result));
  ck_assert_pstr_eq(s21_result, base_result);
  while ((s21_result != 0) && (base_result != 0)) {
    s21_result = s21_strtok(NULL, delim);
    base_result = strtok(NULL, delim);
    ck_assert_pstr_eq(s21_result, base_result);
  }
}
END_TEST

START_TEST(s21_strtok6) {
  char str[] = "test1/n /n test2/test3/test4";
  char s21_str[] = "test1/n /n test2/test3/test4";
  char delim[] = "/";
  char *s21_result = s21_strtok(s21_str, delim);
  char *base_result = strtok(str, delim);
  ck_assert_uint_eq(s21_strlen(s21_result), s21_strlen(base_result));
  ck_assert_pstr_eq(s21_result, base_result);
  while ((s21_result != 0) && (base_result != 0)) {
    s21_result = s21_strtok(NULL, delim);
    base_result = strtok(NULL, delim);
    ck_assert_pstr_eq(s21_result, base_result);
  }
}
END_TEST

START_TEST(s21_strtok7) {
  char str[] = "//////////";
  char s21_str[] = "//////////";
  char delim[] = "/";
  char *s21_result = s21_strtok(s21_str, delim);
  char *base_result = strtok(str, delim);
  ck_assert_uint_eq(s21_strlen(s21_result), s21_strlen(base_result));
  ck_assert_pstr_eq(s21_result, base_result);
  while ((s21_result != 0) && (base_result != 0)) {
    s21_result = s21_strtok(NULL, delim);
    base_result = strtok(NULL, delim);
    ck_assert_pstr_eq(s21_result, base_result);
  }
}
END_TEST

START_TEST(s21_strtok8) {
  char str[] = "test1/test2/test3/test4";
  char s21_str[] = "test1/test2/test3/test4";
  char delim[] = "/0";
  char *s21_result = s21_strtok(s21_str, delim);
  char *base_result = strtok(str, delim);
  ck_assert_uint_eq(s21_strlen(s21_result), s21_strlen(base_result));
  ck_assert_pstr_eq(s21_result, base_result);
  while ((s21_result != 0) && (base_result != 0)) {
    s21_result = s21_strtok(NULL, delim);
    base_result = strtok(NULL, delim);
    ck_assert_pstr_eq(s21_result, base_result);
  }
}
END_TEST

START_TEST(s21_strtok9) {
  char str[] = "test1/test2/test3/test4";
  char s21_str[] = "test1/test2/test3/test4";
  char delim[] = "6";
  char *s21_result = s21_strtok(s21_str, delim);
  char *base_result = strtok(str, delim);
  ck_assert_uint_eq(s21_strlen(s21_result), s21_strlen(base_result));
  ck_assert_pstr_eq(s21_result, base_result);
  while ((s21_result != 0) && (base_result != 0)) {
    s21_result = s21_strtok(NULL, delim);
    base_result = strtok(NULL, delim);
    ck_assert_pstr_eq(s21_result, base_result);
  }
}
END_TEST

START_TEST(s21_strtok10) {
  char str[] =
      "12345678//96543uytr21234567y    898765432123456789"
      "qwertyuiopsdfghjkl,mnbvcxrtyuiop/.,mnbvtyuiop      56789plkjhgfd";
  char s21_str[] =
      "12345678//96543uytr21234567y    898765432123456789"
      "qwertyuiopsdfghjkl,mnbvcxrtyuiop/.,mnbvtyuiop      56789plkjhgfd";
  char delim[] = " ut";
  char *s21_result = s21_strtok(s21_str, delim);
  char *base_result = strtok(str, delim);
  ck_assert_uint_eq(s21_strlen(s21_result), s21_strlen(base_result));
  ck_assert_pstr_eq(s21_result, base_result);
  while ((s21_result != 0) && (base_result != 0)) {
    s21_result = s21_strtok(NULL, delim);
    base_result = strtok(NULL, delim);
    ck_assert_pstr_eq(s21_result, base_result);
  }
}
END_TEST

Suite *s21_strtok_suite() {
  Suite *s;
  TCase *tc_core;
  s = suite_create("s21_strtok");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_strtok0);
  tcase_add_test(tc_core, s21_strtok1);
  tcase_add_test(tc_core, s21_strtok2);
  tcase_add_test(tc_core, s21_strtok3);
  tcase_add_test(tc_core, s21_strtok4);
  tcase_add_test(tc_core, s21_strtok5);
  tcase_add_test(tc_core, s21_strtok6);
  tcase_add_test(tc_core, s21_strtok7);
  tcase_add_test(tc_core, s21_strtok8);
  tcase_add_test(tc_core, s21_strtok9);
  tcase_add_test(tc_core, s21_strtok10);
  suite_add_tcase(s, tc_core);
  return s;
}