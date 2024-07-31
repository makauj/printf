#include "main.h"

/**
 * custom_string - Handles the %S format specifier
 * @args: The argument list
 * @buf: The buffer to store the output
 * @buf_index: The current index in the buffer
 * @count: The character count
 */
void custom_string(va_list args, char *buf, int *buf_index, int *count)
{
	char *str = va_arg(args, char *);
	char hex[3];

	if (str == NULL)
	{
		str = "(null)";
	}
	while (*str)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			buf[(*buf_index)++] = '\\';
			buf[(*buf_index)++] = 'x';
			sprintf(hex, "%02X", (unsigned char)*str);
			buf[(*buf_index)++] = hex[0];
			buf[(*buf_index)++] = hex[1];
			(*count) += 4;
		}
		else
		{
			buf[(*buf_index)++] = *str;
			(*count)++;
		}
		str++;
	}
}
