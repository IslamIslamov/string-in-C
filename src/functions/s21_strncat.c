#include "../s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  if (dest != S21_NULL && src != S21_NULL && n > 0) {
    s21_size_t len_dest = s21_strlen(dest);
    s21_size_t i = 0;
    while (i < n && src[i] != '\0' && len_dest + i < s21_strlen(dest) + n) {
      dest[len_dest + i] = src[i];
      i++;
    }
    dest[len_dest + i] = '\0';
  }

  return dest;
}