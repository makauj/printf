#include "main.h"

/**
 * handle_octal - Handles the %o format specifier
 * @args: The argument list
 * @buf: The buffer to store the output
 * @buf_index: The current index in the buffer
 * @count: The character count
 */
void handle_octal(va_list args, char *buf, int *buf_index, int *count)
{
	unsigned int num = va_arg(args, unsigned int);
	char octal_str[12];
	int octal_index, j;

	if (num == 0)
	{
		buf[(*buf_index)++] = '0';
		(*count)++;
		return;
	}
	octal_index = 0;
	while (num > 0)
	{
		octal_str[octal_index++] = (num % 8) + '0';
		num /= 8;
	}

	for (j = octal_index - 1; j >= 0; j--)
	{
		buf[(*buf_index)++] = octal_str[j];
		(*count)++;
	}
}
