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

	va_start(args, format);

	while (*format)
	{
		if (*format == '%') 
		{
			format++;
			if (*format)
			{
				count += handle_format(*format, args);
			}
			else
			{
				count += write(STDOUT_FILENO, "%", 1);
			}
		}
		else
		{
			count += write(STDOUT_FILENO, format, 1);
		}
		format++;
	}

	va_end(args);

	return (count);
}
