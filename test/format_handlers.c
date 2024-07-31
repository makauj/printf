#include "main.h"
#include <unistd.h>

/**
 * format_handler - function to determines which format handler to use
 * @specifier: The format specifier character (e.g., 'c', 'd', 's')
 * @args: A va_list containing the arguments
 * Return: count
 */
int handle_format(char specifier, va_list args)
{
	int count = 0;

	switch (specifier)
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
			count += handle_unknown(specifier);
			break;
	}

	return (count);
}
