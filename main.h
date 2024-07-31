#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int _printf(const char *format, ...);
int handle_format(const char *format, va_list args, char *buf, int *buf_index);
void handle_char(va_list args, char *buf, int *buf_index, int *count);
void handle_string(va_list args, char *buf, int *buf_index, int *count);
void custom_string(va_list args, char *buf, int *buf_index, int *count);
void handle_integer(va_list args, char *buf, int *buf_index, int *count);
void handle_unsigned(va_list args, char *buffer, int *buf_index, int *count);
void handle_octal(va_list args, char *buf, int *buf_index, int *count);
void handle_hex(va_list args, char *buf, int *buf_index, int *count, char specifier);
void handle_binary(va_list args, char *buf, int *buf_index, int *count);
void handle_pointer(va_list args, char *buf, int *buf_index, int *count);
void flush_buffer(char *buffer, int *buf_index);

void my_itoa(long num, char *str, int base);
void my_ftoa(double num, char *str, int precision);

#endif /* MAIN_H */
