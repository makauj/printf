#include "main.h"

/**
 * handle_unsigned - Handles the %u format specifier
 * @args: The argument list
 * @buf: The buffer to store the output
 * @buf_index: The current index in the buffer
 * @count: The character count
 */

void handle_unsigned(va_list args, char *buf, int *buf_index, int *count)
{
	unsigned int num = va_arg(args, unsigned int);
	char num_str[12];
	int num_chars, j;

	num_chars = sprintf(num_str, "%u", num);
	for (j = 0; j < num_chars; j++)
	{
		buf[(*buf_index)++] = num_str[j];
		(*count)++;
	}
}
