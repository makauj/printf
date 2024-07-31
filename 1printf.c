#include "main.h"
/**
 * _printf - Produces output according to a format
 * @format: The format string
 *
 * Return: The number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	char buffer[BUFFER_SIZE];
	int buf_index = 0;

	if (format == NULL)
	{
		return (-1);
	}

	va_start(args, format);

	count = handle_format(format, args, buffer, &buf_index);

	if (buf_index > 0)
	{
		flush_buffer(buffer, &buf_index);
	}
	va_end(args);

	return (count);
}
