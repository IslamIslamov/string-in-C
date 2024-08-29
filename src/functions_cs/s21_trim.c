#include "../s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  size_t src_len = 0;
  size_t start_index = 0;
  size_t end_index = 0;
  size_t new_src_len = 0;
  char *new_src;

  if (src == S21_NULL) return S21_NULL;

  src_len = s21_strlen(src);

  if (src_len == 0) {
    new_src = (char *)malloc(sizeof(char));
    if (new_src) {
      if (new_src) new_src[0] = '\0';
    }
  } else {
    while (s21_is_trim_char(src[start_index], trim_chars)) {
      start_index++;
    }

    end_index = src_len;
    while (end_index > start_index &&
           s21_is_trim_char(src[end_index - 1], trim_chars)) {
      end_index--;
    }

    new_src_len = end_index - start_index;
    new_src = (char *)malloc(new_src_len + 1);
    if (new_src) {
      s21_memcpy(new_src, src + start_index, new_src_len);
      new_src[new_src_len] = '\0';
    }
  }

  return new_src;
}

bool s21_is_trim_char(char c, const char *trim_chars) {
  const char *new_trim_char = trim_chars == NULL ? " " : trim_chars;
  while (*new_trim_char != '\0') {
    if (c == *new_trim_char) {
      return true;
    }
    new_trim_char++;
  }
  return false;
}
