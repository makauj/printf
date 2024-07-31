#include "main.h"

/**
 * handle_format - Handles the format string and arguments
 * @format: The format string
 * @args: The argument list
 * @buf: The buffer to store the output
 * @buf_index: The current index in the buffer
 *
 * Return: The number of characters printed
 */

int handle_format(const char *format, va_list args, char *buf, int *buf_index)
{
	int i, count = 0;

	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					handle_char(args, buf, buf_index, &count);
					break;
				case 's':
					handle_string(args, buf, buf_index, &count);
					break;
				case 'S':
					handle_custom_string(args, buf, buf_index, &count);
					break;
				case '%':
					buf[(*buf_index)++] = '%';
					count++;
					break;
				case 'd':
				case 'i':
					handle_integer(args, buf, buf_index, &count);
					break;
				case 'u':
					handle_unsigned(args, buf, buf_index, &count);
					break;
				case 'o':
					handle_octal(args, buf, buf_index, &count);
					break;
				case 'x':
				case 'X':
					handle_hex(args, buf, buf_index, &count, format[i]);
					break;
				case 'b':
					handle_binary(args, buf, buf_index, &count);
					break;
				case 'p':
					handle_pointer(args, buf, buf_index, &count);
					break;
				default:
					buf[(*buf_index)++] = '%';
					buf[(*buf_index)++] = format[i];
					count += 2;
					break;
			}
		}
		else
		{
			buf[(*buf_index)++] = format[i];
			count++;
		}
		if (*buf_index >= BUFFER_SIZE - 1)
		{
			flush_buffer(buffer, buf_index);
		}
	}
	return (count);
}
