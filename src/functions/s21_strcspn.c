#include "../s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t count = 0;
  int bull[256] = {0};
  while (*str2 != '\0') {
    bull[(unsigned char)(*str2)] = 1;
    str2++;
  }
  while (*str1 != '\0' && bull[(unsigned char)(*str1)] == 0) {
    count++;
    str1++;
  }
  return count;
}