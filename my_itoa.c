#include "main.h"

/**
 * my_itoa - function to convert an integer into a string
 * @num: The integer to convert
 * @str: The destination string where the result will be stored
 * @base: The numeric base for conversion (10 for decimal, 16 for hex)
 */

void my_itoa(long num, char *str, int base)
{
	char *digits = "0123456789abcdef";
	char buf[64];
	int i = 0, j = 0, k, is_negative = 0;

	if (num == 0)
	{
		str[j++] = '0';
		str[j] = '\0';
		return;
	}

	if (num < 0 && base == 10)
	{
		is_negative = 1;
		num = -num;
	}

	while (num != 0)
	{
		buf[i++] = digits[num % base];
		num /= base;
	}

	if (is_negative)
	{
		buf[i++] = '-';
	}

	for (k = i - 1; k >= 0; k--)
	{
		str[j++] = buf[k];
	}

	str[j] = '\0';
}

/**
 * my_ftoa - function to convert a floating-point number to a string
 * @num: floating point number to convert
 * @str: Destination string
 * @precision: No. of digits after decimal point
 */

void my_ftoa(double num, char *str, int precision)
{
	long int_part = (long)num;
	double frac_part = num - int_part;
	char int_str[32], frac_str[32];
	int i = 0, j;

	my_itoa(int_part, int_str, 10);

	while (int_str[i] != '\0')
	{
		str[i] = int_str[i];
		i++;
	}

	str[i++] = '.';

	for (j = 0; j < precision; j++)
	{
		frac_part *= 10;
	}

	my_itoa((long)frac_part, frac_str, 10);
	for (j = 0; frac_str[j] != '\0'; j++)
	{
		str[i++] = frac_str[j];
	}
	str[i] = '\0';
}

