#include "main.h"

/**
 * handle_unknown - handles unknown specifiers
 * @specifier: specifier
 *
 * Return: output
 */
int handle_unknown(char specifier)
{
	char buffer[2];

	buffer[0] = '%';
	buffer[1] = specifier;

	return (write(STDOUT_FILENO, buffer, 2));
}
