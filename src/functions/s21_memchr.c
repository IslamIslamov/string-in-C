#include "../s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  const unsigned char *p_str = (const unsigned char *)str;
  unsigned char target = (unsigned char)c;
  for (s21_size_t i = 0; i < n; i++) {
    if (p_str[i] == target) return (char *)(p_str + i);
  }
  return S21_NULL;
}