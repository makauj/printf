#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <stddef.h>
#include <stdint.h>

#define BUFFER_SIZE 1024

int _printf(const char *format, ...);
int handle_format(const char *format, va_list args, char *buf, size_t *buf_index);
void handle_char(va_list args, char *buf, size_t *buf_index, int *count);
void handle_string(va_list args, char *buf, size_t *buf_index, int *count);
void custom_string(va_list args, char *buf, size_t *buf_index, int *count);
void handle_integer(va_list args, char *buf, size_t *buf_index, int *count);
void handle_unsigned(va_list args, char *buf, size_t *buf_index, int *count);
void handle_octal(va_list args, char *buf, size_t *buf_index, int *count);
void handle_hex(va_list args, char *buf, size_t *buf_index, int *count, char spec);
void handle_binary(va_list args, char *buf, size_t *buf_index, int *count);
void handle_pointer(va_list args, char *buf, size_t *buf_index, int *count);
void my_itoa(long num, char *str, int base);
void my_ftoa(double num, char *str, int precision);
int handle_unknown(char specifier);
int flush_buffer(char *buf, size_t *buf_index);

#endif /* MAIN_H */

