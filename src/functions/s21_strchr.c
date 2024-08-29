#include "../s21_string.h"

char *s21_strchr(const char *str, int c) {
  if (str == S21_NULL) return S21_NULL;
  while (*str != '\0') {
    if (*str == c) {
      return (char *)str;
    }
    str++;
  }
  if (*str == c) {
    return (char *)str;
  }
  return S21_NULL;
}