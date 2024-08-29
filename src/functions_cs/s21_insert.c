#include "../s21_string.h"

void *s21_insert(const char *src, const char *str, size_t start_index) {
  if (src == S21_NULL || str == S21_NULL) return S21_NULL;

  size_t src_len = s21_strlen(src);
  size_t str_len = s21_strlen(str);
  if (start_index >= src_len) start_index = src_len;

  size_t new_len = src_len + str_len + 1;
  char *res = (char *)malloc(new_len * sizeof(char));

  if (res != S21_NULL) {
    size_t i, j, m;
    for (i = 0, j = 0, m = 0; i < new_len - 1; i++) {
      if (i < start_index || !str[m])
        res[i] = src[j++];
      else
        res[i] = str[m++];
    }
    res[i] = '\0';
  }

  return res;
}
