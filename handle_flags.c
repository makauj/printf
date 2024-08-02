#include "main.h"
/**
 * _flags - function that applies flags to the buffer
 * @flag: flag character
 * @buf: buffer to store the output
 * @buf_index: current index in the buffer
 * @count: count characters
 * @spec: format specifier
 * @is_positive: indicate if a no. is positive
 */
void _flags(char flag, char *buf, int *buf_index, int *count, char spec, int is_positive)
{
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
		if (spec == 'o')
		{
			buf[(*buf_index)++] = '0';
			(*count)++;
		}
		else if (spec == 'x')
		{
			buf[(*buf_index)++] = '0';
			buf[(*buf_index)++] = 'x';
			(*count) += 2;
		}
		else if (spec == 'X')
		{
			buf[(*buf_index)++] = '0';
			buf[(*buf_index)++] = 'X';
			(*count) += 2;
		}
	}
}
