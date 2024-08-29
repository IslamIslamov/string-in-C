#include "../s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  const unsigned char *s1 = (unsigned char *)str1;
  const unsigned char *s2 = (unsigned char *)str2;
  int flag = 0;
  s21_size_t i = 0;
  while (flag == 0 && i < n) {
    flag = s1[i] - s2[i];
    i++;
  }
  return flag;
}