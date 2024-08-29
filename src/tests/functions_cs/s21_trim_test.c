#include "../../includes/s21_mainTestsRun.h"

//////////////////////////////////////////////////////
//***********************TRIM**********************//
START_TEST(all_empty) {
  char str[] = "";
  char trim_ch[] = "";
  char expected[] = "";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(str_empty) {
  char str[] = "";
  char trim_ch[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
  char expected[] = "";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(trim_empty) {
  char str[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
  char trim_ch[] = "";
  char expected[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(trim_and_str_eq) {
  char str[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
  char trim_ch[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
  char expected[] = "";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(trim_test1) {
  char str[] = "+!!++Abo+ba++00";
  char trim_ch[] = "+!0-";
  char expected[] = "Abo+ba";
  char *got = (char *)s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(trim_test2) {
  char str[] = "Ab000cd0";
  char trim_ch[] = "003";
  char expected[] = "Ab000cd";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(trim_test3) {
  char str[] = "DoNotTouch";
  char trim_ch[] = "Not";
  char expected[] = "DoNotTouch";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(trim_test4) {
  char str[] = "&* !!sc21 * **";
  char trim_ch[] = "&!* ";
  char expected[] = "sc21";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(trim_test5) {
  char str[] = " Good morning!    ";
  char trim_ch[] = " ";
  char expected[] = "Good morning!";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(empty_spaces) {
  char str[] = "        abc         ";
  char trim_ch[] = "";
  char expected[] = "        abc         ";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(null_ptr_trim_chars) {
  char str[] = " abc ";
  char *trim_ch = NULL;
  char expected[] = "abc";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(test_trim_01) {
  const char *src = "   Hello, World!   ";
  const char *trim_chars = " ";
  char *result = s21_trim(src, trim_chars);
  ck_assert_str_eq(result, "Hello, World!");
  free(result);
}
END_TEST

START_TEST(test_trim_02) {
  const char *src = "Hello, World!";
  const char *trim_chars = " ";
  char *result = s21_trim(src, trim_chars);
  ck_assert_str_eq(result, "Hello, World!");
  free(result);
}
END_TEST

START_TEST(test_trim_03) {
  const char *src = "";
  const char *trim_chars = " ";
  char *result = s21_trim(src, trim_chars);
  ck_assert_str_eq(result, "");
  free(result);
}
END_TEST

START_TEST(test_trim_04) {
  const char *src = "!!!---Hello, World!!---!!!";
  const char *trim_chars = "!-";
  char *result = s21_trim(src, trim_chars);
  ck_assert_str_eq(result, "Hello, World");
  free(result);
}
END_TEST

START_TEST(test_trim_05) {
  const char *src = "\t  \nHello, World!\t\n ";
  const char *trim_chars = " \t\n";
  char *result = s21_trim(src, trim_chars);
  ck_assert_str_eq(result, "Hello, World!");
  free(result);
}
END_TEST

START_TEST(test_trim_06) {
  const char *src = "abcdefg";
  const char *trim_chars = "abcdefg";
  char *result = s21_trim(src, trim_chars);
  ck_assert_str_eq(result, "");
  free(result);
}
END_TEST

START_TEST(test_trim_07) {
  const char *src = "   Hello, World!   ";
  const char *trim_chars = "";
  char *result = s21_trim(src, trim_chars);
  ck_assert_str_eq(result, "   Hello, World!   ");
  free(result);
}
END_TEST

Suite *s21_trim_suite(void) {
  Suite *s;
  TCase *tc_trim;
  s = suite_create("s21_trim");
  tc_trim = tcase_create("To Lower Func");
  suite_add_tcase(s, tc_trim);
  tcase_add_test(tc_trim, test_trim_01);
  tcase_add_test(tc_trim, test_trim_02);
  tcase_add_test(tc_trim, test_trim_03);
  tcase_add_test(tc_trim, test_trim_04);
  tcase_add_test(tc_trim, test_trim_05);
  tcase_add_test(tc_trim, test_trim_06);
  tcase_add_test(tc_trim, test_trim_07);
  tcase_add_test(tc_trim, all_empty);
  tcase_add_test(tc_trim, str_empty);
  tcase_add_test(tc_trim, trim_empty);
  tcase_add_test(tc_trim, trim_and_str_eq);

  tcase_add_test(tc_trim, trim_test1);
  tcase_add_test(tc_trim, trim_test2);
  tcase_add_test(tc_trim, trim_test3);
  tcase_add_test(tc_trim, trim_test4);
  tcase_add_test(tc_trim, trim_test5);
  tcase_add_test(tc_trim, empty_spaces);
  tcase_add_test(tc_trim, null_ptr_trim_chars);

  return s;
}
