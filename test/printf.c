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
			switch (*format)
			{
				case 'c':
					count += handle_char(args);
					break;
				case 's':
					count += handle_string(args);
					break;
				case 'd':
				case 'i':
					count += handle_int(args);
					break;
				case 'u':
					count += handle_unsigned(args);
					break;
				case 'x':
					count += handle_hex(args, 0);
					break;
				case 'X':
					count += handle_hex(args, 1);
					break;
				case 'p':
					count += handle_pointer(args);
					break;
				case 'f':
					count += handle_float(args);
					break;
				case '%':
					count += write(STDOUT_FILENO, "%", 1);
					break;
				default:
					count += write(STDOUT_FILENO, "%", 1);
					count += write(STDOUT_FILENO, format, 1);
					break;
			}
		}
		else
		{
			count += write(STDOUT_FILENO, format, 1);
		}
		format++;
	}

	va_end(args);

	return count;
}

