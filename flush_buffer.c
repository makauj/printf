#include "main.h"

/**
 * flush_buffer - Writes the buffer to stdout and resets the buffer index
 * @buf: The buffer to write
 * @buf_index: The current index in the buffer
 */
void flush_buffer(char *buf, int *buf_index)
{
	write(1, buf, *buf_index);
	*buf_index = 0;
}

