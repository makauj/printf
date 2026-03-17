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



