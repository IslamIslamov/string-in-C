#ifndef SRC_S21_SPRINTF_H
#define SRC_S21_SPRINTF_H

#include "../s21_string.h"

// #define S21_NULL (void *)0
typedef unsigned long s21_size_t;

typedef struct s21_format {
  int minus;
  int plus;
  int space;
  char length;
  int width;
  int zero;
  int precision;
  int is_precision;
  char specifier;
  int hash;
} s21_format;

typedef union {
  float f;
  struct {
    unsigned int mantisa : 23;
    unsigned int exponent : 8;
    unsigned int sign : 1;
  } parts;
} float_cast;

int s21_sprintf(char *buffer, const char *format, ...);
void s21_fill_buffer(char *buffer, const char *format_string,
                     va_list arguments);
void s21_string_format_process(const char *format, int *indices, char *buffer,
                               va_list arguments);
void s21_format_and_buffer_sub_for_c_spec(s21_format parameters,
                                          va_list arguments, char *buffer,
                                          int *indices);
void s21_format_and_buffer_sub_for_i_d_specs(s21_format parameters,
                                             va_list arguments, char *buffer,
                                             int *indices);
void s21_format_buffer_process(int *indices, char *buffer, va_list arguments,
                               s21_format parameters);
void s21_c_specificator(const char c, s21_format parameters, char *buffer,
                        int *indices);
void s21_d_specificator(int64_t num, s21_format parameters, char *output_buffer,
                        int *insert_index, int base);
void s21_format_flag_helper(char *buffer, int *indices, int count, char c);
void s21_format_flag_edit(char *temp, s21_format parameters, char *buffer,
                          int *indices, int base_w);
void s21_format_flag(char *temp, s21_format parameters, char *buffer,
                     int *indices, int mode);
void s21_check_value(int *m, long double *f);
void s21_get_integer_part(s21_format parameters, long double *man);
int s21_set_integer_part(s21_format parameters, char *temp, long long *ipart);
void s21_check_signs_and_spec(s21_format parameters, int m, char *temp, int j,
                              int *count);
void s21_set_float_part(s21_format parameters, long double man, int count,
                        int *indices, char *buffer);
void s21_f_specificator(long double f, s21_format parameters, char *buffer,
                        int *indices);
void s21_s_specificator(va_list arguments, s21_format parameters, char *buffer,
                        int *indices);
const void *s21_get_argument_type(va_list arguments, s21_format parameters);
void s21_convert_to_string(char *temp, const void *arg, size_t size);
void s21_align_string_width(char *buffer, int *indices, s21_format parameters,
                            int *j);
void s21_copy_to_buffer(char *buffer, int *indices, const char *temp, int *j,
                        s21_format parameters);
void s21_reverse_align_string_width(char *buffer, int *indices,
                                    s21_format parameters, int *j);
void s21_lc_specificator(wchar_t c1, s21_format parameters, char *buffer,
                         int *indices);
void s21_u_specificator(uint64_t d, s21_format parameters, char *buffer,
                        int *indices, int base);
void s21_gG_specificator(long double f, s21_format parameters, char *buffer,
                         int *indices);
void s21_remove_trailing_zeroes(char *buffer, int *indices);
void s21_prepend_mantiss(char *buffer, int pow, char sign, int *indices);
void s21_uppcase(char *str);
void s21_Ee_specificator(s21_format parameters, char *buffer, long double val,
                         int *indices);
void s21_o_specificator(s21_format parameters, char *buffer, int64_t val,
                        int *indices);
void s21_xX_specificator(s21_format parameters, char *buffer, int64_t val,
                         int *indices);
int s21_check_zeroes(char *buffer);
void s21_p_specificator(s21_format parameters, char *buffer, int64_t val,
                        int *indices);
void s21_uppcase(char *str);

#endif  // SRC_S21_SPRINTF_H