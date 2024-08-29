#include "../s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *nextT = S21_NULL;
  if (str != S21_NULL) nextT = str;
  if (nextT == S21_NULL) return nextT;
  while (*nextT != '\0' && s21_strchr(delim, *nextT) != S21_NULL) nextT++;
  if (*nextT == '\0') {
    nextT = S21_NULL;
    return nextT;
  }
  char *startT = nextT;
  while (*nextT != '\0' && s21_strchr(delim, *nextT) == S21_NULL) nextT++;
  if (*nextT == '\0') {
    nextT = S21_NULL;
    return startT;
  }
  *nextT = '\0';
  nextT++;
  return startT;
}