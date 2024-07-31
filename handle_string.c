#include "main.h"

/**
 * handle_string - Handles the %s format specifier
 * @args: The argument list
 * @buf: The buffer to store the output
 * @buf_index: The current index in the buffer
 * @count: The character count
 */
void handle_string(va_list args, char *buf, int *buf_index, int *count)
{
	char *str = va_arg(args, char *);

	if (str == NULL)
	{
		str = "(null)";
	}
	while (*str)
	{
		buf[(*buf_index)++] = *str++;
		(*count)++;
	}
}
