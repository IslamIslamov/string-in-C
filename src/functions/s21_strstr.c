#include "../s21_string.h"
char *s21_strstr(const char *haystack, const char *needle) {
  if (haystack == S21_NULL || needle == S21_NULL) {
    return S21_NULL;
  }
  if (needle[0] == '\0') {
    return (char *)haystack;
  }
  while (*haystack != '\0') {
    const char *h_ptr = haystack;
    const char *n_ptr = needle;
    while (*n_ptr != '\0' && *h_ptr == *n_ptr) {
      h_ptr++;
      n_ptr++;
    }
    if (*n_ptr == '\0') {
      return (char *)haystack;
    }
    haystack++;
  }
  return S21_NULL;
}
