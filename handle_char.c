#include "main.h"

/**
 * handle_char - Handles the %c format specifier
 * @args: The argument list
 * @buf: The buffer to store the output
 * @buf_index: The current index in the buffer
 * @count: The character count
 */

void handle_char(va_list args, char *buf, int *buf_index, int *count)
{
	buf[(*buf_index)++] = (char)va_arg(args, int);
	(*count)++;
}
