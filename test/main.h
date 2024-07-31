#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>


static void reverse(char *str, int length);
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
void my_ftoa(double num, char *str, int precision);
int handle_unknown(char specifier);
void my_ftoa(double num, char *str, int precision);
#endif /* MAIN_H */

