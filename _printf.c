#include "main.h"

/**
 * _printf - Produces output according to a format string.
 * @format: The format string.
 *
 * Return: Number of characters printed, or -1 on error.
 */
int _printf(const char *format, ...)
{
	char *buffer;
	size_t buf_index = 0;
	va_list args;
	int count;

	if (format == NULL)
		return (-1);

	buffer = malloc(BUFFER_SIZE);
	if (buffer == NULL)
		return (-1);

	va_start(args, format);
	count = handle_format(format, args, buffer, &buf_index);
	va_end(args);

	if (buf_index > 0 && flush_buffer(buffer, &buf_index) == -1)
	{
		free(buffer);
		return (-1);
	}

	free(buffer);
	return (count);
}
