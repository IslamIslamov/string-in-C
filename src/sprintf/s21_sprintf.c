#include "../includes/s21_sprintf.h"

int s21_sprintf(char *buffer, const char *format, ...) {
  va_list arguments;
  va_start(arguments, format);

  s21_fill_buffer(buffer, format, arguments);

  va_end(arguments);
  return s21_strlen(buffer);
}

void s21_fill_buffer(char *buffer, const char *format_string,
                     va_list arguments) {
  int indices[2] = {0, 0};

  for (; indices[0] < (int)s21_strlen(format_string);
       indices[0]++, indices[1]++) {
    if (format_string[indices[0]] == '%' &&
        format_string[indices[0] + 1] != '%') {
      s21_string_format_process(format_string, indices, buffer, arguments);
    } else if (format_string[indices[0]] == '%' &&
               format_string[indices[0] + 1] == '%') {
      buffer[indices[1]] = format_string[indices[0]];
    } else {
      buffer[indices[1]] = format_string[indices[0]];
    }
  }

  buffer[indices[1]] = '\0';
}

void s21_string_format_process(const char *format, int *indices, char *buffer,
                               va_list arguments) {
  s21_format parameters = {0};

  for (; indices[0] < (int)s21_strlen(format) &&
         s21_strchr("cdifsugGeExXonp", format[indices[0]]) == NULL;
       indices[0]++) {
    switch (format[indices[0]]) {
      case '0':
        if (!parameters.is_precision && !parameters.zero && !parameters.width) {
          parameters.zero = 1;
        }
        break;
      case '+':
        parameters.plus = 1;
        break;
      case '-':
        parameters.minus = 1;
        break;
      case ' ':
        parameters.space = 1;
        break;
      case 'l':
        parameters.length = 'l';
        break;
      case 'h':
        parameters.length = 'h';
        break;
      case 'L':
        parameters.length = 'L';
        break;
      case '.':
        parameters.is_precision = 1;
        break;
      case '#':
        parameters.hash = 1;
        break;
    }

    if (parameters.is_precision && format[indices[0]] == '-')
      parameters.precision = 0;
    else if (parameters.is_precision && format[indices[0]] == '*')
      parameters.precision = va_arg(arguments, int);
    else if (parameters.is_precision &&
             (format[indices[0]] >= '0' && format[indices[0]] <= '9')) {
      parameters.precision =
          parameters.precision * 10 + (format[indices[0]] - '0');
    } else if (format[indices[0]] >= '0' && format[indices[0]] <= '9') {
      parameters.width = parameters.width * 10 + (format[indices[0]] - '0');
    } else if (format[indices[0]] == '*')
      parameters.width = va_arg(arguments, int);
  }

  parameters.specifier = format[indices[0]];

  s21_format_buffer_process(indices, buffer, arguments, parameters);
}

void s21_format_and_buffer_sub_for_i_d_specs(s21_format parameters,
                                             va_list arguments, char *buffer,
                                             int *indices) {
  if (parameters.length == 'l')
    s21_d_specificator(va_arg(arguments, long int), parameters, buffer, indices,
                       10);
  else if (parameters.length == 'h')
    s21_d_specificator((short)va_arg(arguments, int), parameters, buffer,
                       indices, 10);
  else if (parameters.length == 'L')
    s21_d_specificator(va_arg(arguments, long long), parameters, buffer,
                       indices, 10);
  else
    s21_d_specificator(va_arg(arguments, int), parameters, buffer, indices, 10);
}

void s21_format_buffer_process(int *indices, char *buffer, va_list arguments,
                               s21_format parameters) {
  if (parameters.specifier == 'c') {
    s21_c_specificator(va_arg(arguments, int), parameters, buffer, indices);
  } else if (parameters.specifier == 'd' || parameters.specifier == 'i') {
    s21_format_and_buffer_sub_for_i_d_specs(parameters, arguments, buffer,
                                            indices);
  } else if (parameters.specifier == 'f') {
    if (parameters.length == 'L')
      s21_f_specificator(va_arg(arguments, long double), parameters, buffer,
                         indices);
    else
      s21_f_specificator(va_arg(arguments, double), parameters, buffer,
                         indices);
  } else if (parameters.specifier == 's') {
    s21_s_specificator(arguments, parameters, buffer, indices);
  } else if (parameters.specifier == 'u') {
    s21_u_specificator(va_arg(arguments, uint64_t), parameters, buffer, indices,
                       10);
  } else if (parameters.specifier == 'g' || parameters.specifier == 'G') {
    if (parameters.length == 'L')
      s21_gG_specificator(va_arg(arguments, long double), parameters, buffer,
                          indices);
    else
      s21_gG_specificator(va_arg(arguments, double), parameters, buffer,
                          indices);
  } else if (parameters.specifier == 'e' || parameters.specifier == 'E') {
    if (parameters.length == 'L')
      s21_Ee_specificator(parameters, buffer, va_arg(arguments, long double),
                          indices);
    else
      s21_Ee_specificator(parameters, buffer, va_arg(arguments, double),
                          indices);
  } else if (parameters.specifier == 'x' || parameters.specifier == 'X')
    s21_xX_specificator(parameters, buffer, va_arg(arguments, int64_t),
                        indices);
  else if (parameters.specifier == 'n')
    indices[1]--;
  else if (parameters.specifier == 'o')
    s21_o_specificator(parameters, buffer, va_arg(arguments, int64_t), indices);
  else if (parameters.specifier == 'p')
    s21_p_specificator(parameters, buffer, va_arg(arguments, uint64_t),
                       indices);

  if (parameters.specifier == 'G' || parameters.specifier == 'E')
    s21_uppcase(buffer);
}

void s21_c_specificator(const char c, s21_format parameters, char *buffer,
                        int *indices) {
  if (parameters.width && !parameters.minus) {
    for (int j = 0; j < parameters.width - 1; j++) {
      buffer[indices[1]] = ' ';
      indices[1]++;
    }
    buffer[indices[1]] = c;
  } else if (parameters.width && parameters.minus) {
    buffer[indices[1]] = c;
    indices[1]++;
    for (int j = 0; j < parameters.width - 1; j++) {
      buffer[indices[1]] = ' ';
      indices[1]++;
    }
    indices[1]--;
  } else {
    buffer[indices[1]] = c;
  }
}

void s21_d_specificator(int64_t num, s21_format parameters, char *output_buffer,
                        int *insert_index, int base) {
  int is_negative = (num < 0);
  num = (is_negative) ? -num : num;

  char temp_buffer[BUFF_SIZE] = {'\0'};
  int temp_index = 0;

  if (num == 0 && !parameters.is_precision) {
    temp_buffer[temp_index++] = '0';
  } else {
    while (num != 0) {
      char digit = (char)((num % base) + (num % base < 10 ? '0' : 'a' - 10));
      temp_buffer[temp_index++] = digit;
      num /= base;
    }
  }

  int length = temp_index;

  while (length < parameters.precision) {
    temp_buffer[temp_index++] = '0';
    length++;
  }

  if (parameters.space && !is_negative) temp_buffer[temp_index] = ' ';
  if (parameters.plus && !is_negative) temp_buffer[temp_index] = '+';
  if (parameters.hash &&
      !(parameters.specifier == 'x' || parameters.specifier == 'X'))
    temp_buffer[temp_index] = '0';
  if (is_negative) temp_buffer[temp_index] = '-';

  if (parameters.specifier == 'X') s21_uppcase(temp_buffer);

  s21_format_flag(temp_buffer, parameters, output_buffer, insert_index, 0);
}

void s21_format_flag_helper(char *buffer, int *indices, int count, char c) {
  for (int j = 0; j < count; j++) {
    buffer[indices[1]++] = c;
  }
}

void s21_format_flag_edit(char *temp, s21_format parameters, char *buffer,
                          int *indices, int base_w) {
  if ((parameters.hash &&
       (parameters.specifier == 'x' || parameters.specifier == 'X')) ||
      parameters.specifier == 'p') {
    if (!s21_check_zeroes(temp) || parameters.specifier == 'p') {
      buffer[indices[1]++] = '0';
      buffer[indices[1]++] = (parameters.specifier == 'X') ? 'X' : 'x';
    }
  }
  for (int j = 0; j < base_w; j++) {
    buffer[indices[1]++] = temp[base_w - 1 - j];
  }
}

void s21_format_flag(char *temp, s21_format parameters, char *buffer,
                     int *indices, int mode) {
  int base_w = (int)s21_strlen(temp);

  if ((parameters.hash &&
       (parameters.specifier == 'x' || parameters.specifier == 'X')) ||
      parameters.specifier == 'p') {
    if (!s21_check_zeroes(temp) || parameters.specifier == 'p') {
      if (parameters.width) parameters.width -= 2;
    }
  } else if (parameters.width && parameters.hash &&
             (parameters.specifier == 'x' || parameters.specifier == 'X' ||
              parameters.specifier == 'p')) {
    parameters.width -= 2;
  }

  if (parameters.width && !parameters.minus) {
    s21_format_flag_helper(buffer, indices, parameters.width - mode - base_w,
                           parameters.zero ? '0' : ' ');
    s21_format_flag_edit(temp, parameters, buffer, indices, base_w);
  } else if (parameters.width && parameters.minus) {
    s21_format_flag_edit(temp, parameters, buffer, indices, base_w);

    s21_format_flag_helper(buffer, indices, parameters.width - mode - base_w,
                           ' ');
  } else {
    s21_format_flag_edit(temp, parameters, buffer, indices, base_w);
  }
  indices[1]--;
}

void s21_check_value(int *m, long double *f) {
  if ((*f) < 0. && (*f) != 0.) {
    (*f) = -(*f);
    (*m) = 1;
  }
}

void s21_get_integer_part(s21_format parameters, long double *man) {
  long long del = 0;

  if (parameters.precision) {
    if (parameters.specifier == 'e' || parameters.specifier == 'E')
      del = pow(10, parameters.precision - 1);
    else
      del = pow(10, parameters.precision);
    (*man) = roundl((*man) * del) / del;
  } else {
    del = pow(10, 6);
    (*man) = roundl((*man) * del) / del;
  }

  if (!parameters.precision && parameters.is_precision) (*man) = roundl((*man));
}

int s21_set_integer_part(s21_format parameters, char *temp, long long *ipart) {
  int j = 0;
  if (!(!parameters.precision && parameters.is_precision) ||
      (parameters.specifier != 'f' && !parameters.precision))
    temp[j++] = '.';

  if ((*ipart) == 0) temp[j++] = '0';

  while ((*ipart) != 0) {
    temp[j] = (long int)(*ipart) % 10 + '0';
    j++;
    (*ipart) /= 10;
  }

  return j;
}

void s21_check_signs_and_spec(s21_format parameters, int m, char *temp, int j,
                              int *count) {
  if (parameters.space && !m) temp[j] = ' ';
  if (parameters.plus && !m) temp[j] = '+';
  if (m) temp[j] = '-';

  if (parameters.specifier == 'f' && !parameters.precision)
    (*count) = 6;
  else if (parameters.precision == 0 && parameters.is_precision)
    (*count) = 1;
  else if (parameters.precision)
    (*count) = parameters.precision;
}

void s21_set_float_part(s21_format parameters, long double man, int count,
                        int *indices, char *buffer) {
  if (!(!parameters.precision && parameters.is_precision)) {
    long long mani = man * pow(10, count) + 0.05;
    char temp1[BUFF_SIZE] = {'\0'};

    int k = 0;
    for (; k < count; k++) {
      temp1[k] = mani % 10 + '0';
      mani /= 10;
    }
    k--;
    for (; k >= 0; k--) {
      buffer[indices[1]++] = temp1[k];
    }
  }
}

void s21_f_specificator(long double f, s21_format parameters, char *buffer,
                        int *indices) {
  int m = 0;
  int count = 0;
  long double man = 0, ipartd = 0;
  long long ipart = 0;
  char temp[BUFF_SIZE] = {'\0'};

  s21_check_value(&m, &f);

  man += modfl(f, &ipartd);
  if (parameters.specifier == 'e' || parameters.specifier == 'E')
    ipart = round(ipartd);
  else
    ipart = ipartd;

  s21_get_integer_part(parameters, &man);
  int j = s21_set_integer_part(parameters, temp, &ipart);
  s21_check_signs_and_spec(parameters, m, temp, j, &count);
  s21_format_flag(temp, parameters, buffer, indices, count);
  indices[1]++;
  s21_set_float_part(parameters, man, count, indices, buffer);

  indices[1]--;
}

void s21_s_specificator(va_list arguments, s21_format parameters, char *buffer,
                        int *indices) {
  int j = 0;
  char temp[BUFF_SIZE] = {'\0'};
  const void *arg = s21_get_argument_type(arguments, parameters);

  if (arg != NULL) {
    s21_convert_to_string(temp, arg, BUFF_SIZE);
    s21_align_string_width(buffer, indices, parameters, &j);
    s21_copy_to_buffer(buffer, indices, temp, &j, parameters);
    s21_reverse_align_string_width(buffer, indices, parameters, &j);
    indices[1]--;
  } else {
    s21_strncat(buffer, "(null)", 10);
    indices[1] += 5;
  }
}

const void *s21_get_argument_type(va_list arguments, s21_format parameters) {
  if (parameters.length == 'l') {
    return va_arg(arguments, const wchar_t *);
  } else {
    return va_arg(arguments, const char *);
  }
}

void s21_convert_to_string(char *temp, const void *arg, size_t size) {
  if (sizeof(*arg) == sizeof(wchar_t)) {
    const wchar_t *wstr = (const wchar_t *)arg;
    wcstombs(temp, wstr, size);
  } else {
    const char *str = (const char *)arg;
    s21_strncpy(temp, str, size);
  }
}

void s21_align_string_width(char *buffer, int *indices, s21_format parameters,
                            int *j) {
  if (parameters.width && !parameters.minus) {
    for (int k = 0; k < parameters.width - *j; k++) {
      if (sizeof(buffer[indices[1]++]) != sizeof(char))
        buffer[indices[1]++] = ' ';
    }
  }
}

void s21_copy_to_buffer(char *buffer, int *indices, const char *temp, int *j,
                        s21_format parameters) {
  while (*temp != '\0' &&
         (!parameters.is_precision || *j < parameters.precision)) {
    buffer[indices[1]++] = *temp++;
    (*j)++;
  }
}

void s21_reverse_align_string_width(char *buffer, int *indices,
                                    s21_format parameters, int *j) {
  if (parameters.width && parameters.minus) {
    for (int k = 0; k < parameters.width - *j; k++) {
      buffer[indices[1]++] = ' ';
    }
  }
}

void s21_u_specificator(uint64_t d, s21_format parameters, char *buffer,
                        int *indices, int base) {
  if (parameters.length == 'l')
    d = (uint64_t)d;
  else if (parameters.length == 'h')
    d = (uint16_t)d;
  else if (parameters.length == ' ')
    d = (uint32_t)d;

  char temp[BUFF_SIZE] = {'\0'};
  int j = 0;

  do {
    temp[j++] = "0123456789abcdef"[d % base];
    d /= base;
  } while (d != 0);

  int len = j;

  while (len < parameters.precision) {
    temp[j++] = '0';
    len++;
  }

  if (parameters.plus) temp[j] = '+';

  s21_format_flag(temp, parameters, buffer, indices, 0);
}

void s21_gG_specificator(long double f, s21_format parameters, char *buffer,
                         int *indices) {
  if (parameters.precision == 0 && parameters.is_precision)
    parameters.precision = 1;
  long double m_val = f + 0.000000001;
  int pow = 0;
  if ((int)f - f) {
    while ((int)m_val == 0) {
      pow++;
      m_val *= 10;
    }
  }
  if (pow > 4) {
    parameters.width -= 3;
    parameters.precision = 0;
    s21_f_specificator(m_val, parameters, buffer, indices);
  } else {
    parameters.precision = 10;
    s21_f_specificator(f, parameters, buffer, indices);
  }
  if (pow > 4) {
    s21_prepend_mantiss(buffer, pow, '-', indices);
  }
  s21_remove_trailing_zeroes(buffer, indices);
}

void s21_remove_trailing_zeroes(char *buffer, int *indices) {
  for (; buffer[indices[1]] == '0' || buffer[indices[1]] == '.'; indices[1]--) {
    if (buffer[indices[1]] == '.') {
      buffer[indices[1]] = '\0';
      break;
    } else
      buffer[indices[1]] = '\0';
  }
}

void s21_prepend_mantiss(char *buffer, int pow, char sign, int *indices) {
  buffer[indices[1]] = 'e';
  buffer[indices[1] + 1] = sign;
  buffer[indices[1] + 3] = pow % 10 + '0';
  pow /= 10;
  buffer[indices[1] + 2] = pow % 10 + '0';
  indices[1] += 3;
}

void s21_uppcase(char *str) {
  while (*str) {
    if (*str >= 'a' && *str <= 'z') *str = *str - 'a' + 'A';
    str++;
  }
}

void s21_Ee_specificator(s21_format parameters, char *buffer, long double val,
                         int *indices) {
  int pow = 0;
  char sign = (int)val == 0 ? '-' : '+';

  if ((int)val - val) {
    while ((int)val == 0) {
      pow++;
      val *= 10;
    }
  } else {
    sign = '+';
  }
  while ((int)val / 10 != 0) {
    pow++;
    val /= 10;
  }

  parameters.width -= 3;

  if (!parameters.is_precision) parameters.precision = 6;

  long double temp_val = val;

  if (parameters.precision == 0)
    temp_val = round(val);
  else
    parameters.precision += 1;

  s21_f_specificator(temp_val, parameters, buffer, indices);
  s21_prepend_mantiss(buffer, pow, sign, indices);
}

void s21_o_specificator(s21_format parameters, char *buffer, int64_t val,
                        int *indices) {
  s21_d_specificator(val, parameters, buffer, indices, 8);
}

void s21_xX_specificator(s21_format parameters, char *buffer, int64_t val,
                         int *indices) {
  s21_d_specificator(val, parameters, buffer, indices, 16);
}

int s21_check_zeroes(char *buffer) {
  int flag = 0;
  for (int indices = 0; buffer[indices]; indices++)
    if (buffer[indices] != '0') flag = -1;
  return flag == -1 ? 0 : 1;
}

void s21_p_specificator(s21_format parameters, char *buffer, int64_t val,
                        int *indices) {
  if (val)
    s21_d_specificator(val, parameters, buffer, indices, 16);
  else {
    s21_memset(buffer, 0, 1);
    s21_strncat(buffer, "(nil)", 10);
    indices[1] += 6;
  }
}