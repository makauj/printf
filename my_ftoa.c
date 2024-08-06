#include "main.h"

#define MAX_DIGITS 64

/**
 * my_ftoa - Converts a floating-point number to a string
 * @num: number to convert to string
 * @str: Destination of converted string
 * @precision: Number of digits after decimal
 */

void my_ftoa(double num, char *str, int precision)
{
	long int_part;
	double frac_part;
	char int_str[MAX_DIGITS];
	char frac_str[MAX_DIGITS];
	int i = 0, j = 0;

	int_part = (long) num;
	frac_part = num - int_part;

	my_itoa(int_part, int_str, 10);

	while (int_str[i] != '\0')
	{
		str[i] = int_str[i];
		i++;
	}

	str[i++] = '.';

	/* Process fractional part */
	for (j = 0; j < precision; j++)
	{
		frac_part *= 10;
		int digit = (int) frac_part;
		frac_str[j] = '0' + digit;
		frac_part -= digit;
	}

	frac_str[j] = '\0';

	/* Copy fractional part to result string */
	for (j = 0; frac_str[j] != '\0'; j++)
	{
		str[i++] = frac_str[j];
	}

	str[i] = '\0';
}
