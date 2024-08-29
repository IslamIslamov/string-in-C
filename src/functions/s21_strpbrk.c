#include "../s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  char *res = S21_NULL;
  for (const char *s1 = str1; *s1; s1++) {
    for (const char *s2 = str2; *s2; s2++) {
      if (*s1 == *s2) {
        res = (char *)s1;
        break;
      }
    }
    if (res) break;
  }
  return res;
}