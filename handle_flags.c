#include "main.h"
/**
 * apply_flags - function that applies flags to the buffer
 * @flag: flag character
 * @buf: buffer to store the output
 * @buf_index: current index in the buffer
 * @count: character count
 */
void apply_flags(char flag, char *buf, int *buf_index, int *count)
{
	char specifier;
	int is_positive;

	if (flag == '+')
	{
		if (is_positive)
		{
			buf[(*buf_index)++] = '+';
			(*count)++;
		}
	}
	else if (flag == ' ')
	{
		if (is_positive)
		{
			buf[(*buf_index)++] = ' ';
			(*count)++;
		}
	}
	else if (flag == '#')
	{
		if (specifier == 'o')
		{
			buf[(*buf_index)++] = '0';
			(*count)++;
		}
		else if (specifier == 'x')
		{
			buf[(*buf_index)++] = '0';
			buf[(*buf_index)++] = 'x';
			(*count) += 2;
		}
		else if (specifier == 'X')
		{
			buf[(*buf_index)++] = '0';
			buf[(*buf_index)++] = 'X';
			(*count) += 2;
		}
	}
}
