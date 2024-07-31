/**
 * handle_hex - Handles the %x and %X format specifiers
 * @args: The argument list
 * @buf: The buffer to store the output
 * @buf_index: The current index in the buffer
 * @count: The character count
 * @spec: The hex format specifier (either 'x' or 'X')
 */
void handle_hex(va_list args, char *buf, int *buf_index, int *count, char spec)
{
	unsigned int num = va_arg(args, unsigned int);
	char hex_str[9];
	int hex_index = 0, j;
	char hex_char;

	hex_char = (spec == 'x') ? 'a' : 'A';

	if (num == 0)
	{
		buf[(*buf_index)++] = '0';
		(*count)++;
		return;
	}

	while (num > 0)
	{
		int digit = num % 16;

		if (digit < 10)
		{
			hex_str[hex_index++] = digit + '0';
		}
		else
		{
			hex_str[hex_index++] = digit - 10 + hex_char;
		}

		num /= 16;

	}
	for (j = hex_index - 1; j >= 0; j--)
	{
		buf[(*buf_index)++] = hex_str[j];
		(*count)++;
	}
}
