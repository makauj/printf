#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <stddef.h>

#define BUFFER_SIZE 1024

void reverse(char *str, int length); /* Removed static keyword */
int _printf(const char *format, ...);
int handle_char(va_list args);
int handle_string(va_list args);
int handle_int(va_list args);
int handle_unsigned(va_list args);
int handle_hex(va_list args, int uppercase);
int handle_pointer(va_list args);
int handle_float(va_list args);
int handle_format(char specifier, va_list args);
void my_itoa(long num, char *str, int base);
void my_ftoa(double num, char *str, int precision); /* Removed duplicate declaration */
int handle_unknown(char specifier);
/* flush buffer: returns 0 on success, -1 on error (errno set) */
int flush_buffer(char *buf, size_t *buf_index);

#endif /* MAIN_H */

