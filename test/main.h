#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

void my_itoa(long num, char *str, int base);
void my_ftoa(double num, char *str, int precision);
int _printf(const char *format, ...);

#endif /* MAIN_H */

