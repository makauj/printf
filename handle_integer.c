#include "main.h"

/**
 * handle_integer - Handles the %d and %i format specifiers
 * @args: The argument list
 * @buf: The buffer to store the output
 * @buf_index: The current index in the buffer
 * @count: The character count
 */
void handle_integer(va_list args, char *buf, int *buf_index, int *count)
{
	int num = va_arg(args, int);
	char num_str[12];
	int num_chars, j;
	int is_positive = 1;

	if (num < 0)
	{
		buf[(*buf_index)++] = '-';
		(*count)++;
		num = -num;
	}
	num_chars = sprintf(num_str, "%d", num);
	for (j = 0; j < num_chars; j++)
	{
		buf[(*buf_index)++] = num_str[j];
		(*count)++;
	}

	apply_flags('\0', buf, buf_index, count, 'd', is_positive);
}

/**
 * handle_long_int - Handles the %ld and %li format specifiers
 * @args: The argument list
 * @buf: The buffer to store the output
 * @buf_index: The current index in the buffer
 * @count: The character count
 */
void handle_long_int(va_list args, char *buf, int *buf_index, int *count)
{
	long num = va_arg(args, long);
	char num_str[21]; /* Long integers can be up to 20 characters long */
	int num_chars, j;
	int is_positive = 1;

	if (num < 0)
	{
		buf[(*buf_index)++] = '-';
		(*count)++;
		num = -num;
		is_positive = 0;
	}

	num_chars = sprintf(num_str, "%ld", num);
	for (j = 0; j < num_chars; j++)
	{
		buf[(*buf_index)++] = num_str[j];
		(*count)++;
	}
	apply_flags('\0', buf, buf_index, count, 'd', is_positive);
}

/**
 * handle_short_int - Handles the %hd and %hi format specifiers
 * @args: The argument list
 * @buf: The buffer to store the output
 * @buf_index: The current index in the buffer
 * @count: The character count
 */
void handle_short_int(va_list args, char *buf, int *buf_index, int *count)
{
	short num = (short)va_arg(args, int);
	char num_str[7]; /* Short integers can be up to 6 characters long */
	int num_chars, j;
	int is_positive = 1;

	if (num < 0)
	{
		buf[(*buf_index)++] = '-';
		(*count)++;
		num = -num;
		is_positive = 0;
	}

	num_chars = sprintf(num_str, "%hd", num);
	for (j = 0; j < num_chars; j++)
	{
		buf[(*buf_index)++] = num_str[j];
		(*count)++;
	}

	apply_flags('\0', buf, buf_index, count, 'd', is_positive);
}
