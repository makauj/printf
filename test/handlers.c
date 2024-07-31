#include "main.h"
/**
 * handle_char - function to handle char
 * @args: arguments
 *
 * Return: char
 */

int handle_char(va_list args)
{
	char c = (char) va_arg(args, int);

	return (write(STDOUT_FILENO, &c, 1));
}

/**
 * handle_string - function to handle strings
 * @args: arguments
 *
 * Return: count
 */

int handle_string(va_list args)
{
	const char *str = va_arg(args, const char *);
	int count = 0;

	while (*str)
	{
		count += write(STDOUT_FILENO, str, 1);
		str++;
	}

	return (count);
}
/**
 * handle_int - functio to handle integers
 * @args: arguments
 *
 * Return: int
 */

int handle_int(va_list args)
{
	int num = va_arg(args, int);
	char buffer[32];

	my_itoa(num, buffer, 10);

	return (write(STDOUT_FILENO, buffer, strlen(buffer)));
}

/**
 * handle_unsigned - function to handle unsigned integers
 * @args: arguments
 *
 * Return: unsigned int
 */
int handle_unsigned(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char buffer[32];

	my_itoa(num, buffer, 10);

	return (write(STDOUT_FILENO, buffer, strlen(buffer)));
}

/**
 * handle_hex - function to handle hex data
 * @args: arguments
 * @uppercase: converts to uppercase
 *
 * Return: output
 */
int handle_hex(va_list args, int uppercase)
{
	unsigned int num = va_arg(args, unsigned int);
	char buffer[32];
	int i;

	my_itoa(num, buffer, 16);

	if (uppercase)
	{
		for (i = 0; buffer[i] != '\0'; i++)
		{
			if (buffer[i] >= 'a' && buffer[i] <= 'f')
			{
				buffer[i] -= 32;
			}
		}
	}

	return (write(STDOUT_FILENO, buffer, strlen(buffer)));
}

/**
 * handle_pointer - function to handle pointers
 * @args: arguments
 *
 * Return: output
 */

int handle_pointer(va_list args)
{
	void *p = va_arg(args, void *);
	char buffer[32];

	my_itoa((unsigned long)p, buffer, 16);

	return (write(STDOUT_FILENO, buffer, strlen(buffer)));
}

/**
 * handle_float - function to handle float
 * @args: arguments
 *
 * Return: output
 */

int handle_float(va_list args)
{
	double num = va_arg(args, double);
	char buffer[64];

	my_ftoa(num, buffer, 6);

	return (write(STDOUT_FILENO, buffer, strlen(buffer)));
}
