/**
 * handle_binary - Handles the %b format specifier
 * @args: The argument list
 * @buf: The buffer to store the output
 * @buf_index: The current index in the buffer
 * @count: The character count
 */
void handle_binary(va_list args, char *buf, int *buf_index, int *count)
{
	unsigned int num = va_arg(args, unsigned int);
	char bin_str[32];
	int bin_index = 0, j;

	if (num == 0)
	{
		buf[(*buf_index)++] = '0';
		(*count)++;
		return;
	}

	while (num > 0)
	{
		bin_str[bin_index++] = (num % 2) + '0';
		num /= 2;
	}

	for (j = bin_index - 1; j >= 0; j--)
	{
		buf[(*buf_index)++] = bin_str[j];
		(*count)++;
	}
}
