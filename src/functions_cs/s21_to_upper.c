#include "../s21_string.h"

void *s21_to_upper(const char *str) {
  char *result = malloc(s21_strlen(str) + 1);
  if (result) {
    for (int i = 0; str[i] != '\0'; i++) {
      if (str[i] >= 'a' && str[i] <= 'z') {
        result[i] = str[i] - 32;
      } else {
        result[i] = str[i];
      }
    }
    result[s21_strlen(str)] = '\0';
    return result;
  } else {
    return S21_NULL;
  }
}