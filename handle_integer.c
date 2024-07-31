#include "main.h"

/**
 * handle_integer - Handles the %d and %i format specifiers
 * @args: The argument list
 * @buf: The buffer to store the output
 * @buf_index: The current index in the buffer
 * @count: The character count
 */
void handle_integer(va_list args, char *buf, int *buf_index, int *count)
{
	int num = va_arg(args, int);
	char num_str[12];
	int num_chars, j;

	if (num < 0)
	{
		buf[(*buf_index)++] = '-';
		(*count)++;
		num = -num;
	}
	num_chars = sprintf(num_str, "%d", num);
	for (j = 0; j < num_chars; j++)
	{
		buf[(*buf_index)++] = num_str[j];
		(*count)++;
	}
}
