#include "main.h"

/**
 * handle_pointer - Handles the %p format specifier
 * @args: The argument list
 * @buf: The buffer to store the output
 * @buf_index: The current index in the buffer
 * @count: The character count
 */
void handle_pointer(va_list args, char *buf, int *buf_index, int *count)
{
	void *ptr = va_arg(args, void *);
	unsigned long addr = (unsigned long)ptr;
	char hex_str[17];
	int hex_index = 0, j;
	int digit;

	buf[(*buf_index)++] = '0';
	buf[(*buf_index)++] = 'x';
	(*count) += 2;

	if (addr == 0)
	{
		buf[(*buf_index)++] = '0';
		(*count)++;
		return;
	}

	while (addr > 0)
	{
		digit = addr % 16;

		if (digit < 10)
		{
			hex_str[hex_index++] = digit + '0';
		}
		else
		{
			hex_str[hex_index++] = digit - 10 + 'a';
		}
		addr /= 16;
	}
	for (j = hex_index - 1; j >= 0; j--)
	{
		buf[(*buf_index)++] = hex_str[j];
		(*count)++;
	}
}
