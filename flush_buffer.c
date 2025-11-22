#include "main.h"
#include <unistd.h>
#include <errno.h>
#include <stddef.h>
#include <sys/types.h>

/**
 * flush_buffer - Writes the buffer to stdout and resets the buffer index.
 * @buf: The buffer to write (must be non-NULL).
 * @buf_index: Pointer to the current number of bytes in the buffer (must be non-NULL).
 *
 * Returns 0 on success, -1 on error (errno is set).
 */
int flush_buffer(char *buf, size_t *buf_index)
{
    if (buf == NULL || buf_index == NULL)
    {
        errno = EINVAL;
        return -1;
    }

    size_t to_write = *buf_index;
    char *p = buf;

    while (to_write > 0)
    {
        ssize_t written = write(STDOUT_FILENO, p, to_write);
        if (written > 0)
        {
            to_write -= (size_t)written;
            p += written;
            continue;
        }
        if (written == -1)
        {
            if (errno == EINTR)
                continue; /* retry on interrupt */
            return -1;    /* real error */
        }
    }

    *buf_index = 0;
    return 0;
}

