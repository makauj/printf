#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <criterion/criterion.h>
#include "../main.h"

/**
 * Function prototype
 */
extern int flush_buffer(char *buffer, size_t *buf_index);

Test(flush_buffer, writes_buffer_to_stdout)
{
    char buffer[BUFFER_SIZE] = "Hello, World!";
    size_t buf_index = 13;

    /* Redirect stdout to a pipe */
    int pipefd[2];
    cr_assert(pipe(pipefd) == 0, "Failed to create pipe");

    int stdout_backup = dup(STDOUT_FILENO);
    cr_assert(dup2(pipefd[1], STDOUT_FILENO) != -1, "Failed to redirect stdout");

    /* Test flush_buffer */
    int result = flush_buffer(buffer, &buf_index);
    cr_assert_eq(result, 0, "flush_buffer failed");
    cr_assert_eq(buf_index, 0, "Buffer index was not reset");

    /* Read from the pipe */
    char output[BUFFER_SIZE] = {0};
    read(pipefd[0], output, 13);
    cr_assert_str_eq(output, "Hello, World!", "Output does not match expected");

    /* Restore stdout */
    dup2(stdout_backup, STDOUT_FILENO);
    close(pipefd[0]);
    close(pipefd[1]);
}

Test(flush_buffer, handles_null_buffer)
{
    size_t buf_index = 13;
    int result = flush_buffer(NULL, &buf_index);
    cr_assert_eq(result, -1, "flush_buffer should fail with NULL buffer");
    cr_assert_eq(errno, EINVAL, "errno should be set to EINVAL");
}

Test(flush_buffer, handles_null_buf_index)
{
    char buffer[BUFFER_SIZE] = "Hello, World!";
    int result = flush_buffer(buffer, NULL);
    cr_assert_eq(result, -1, "flush_buffer should fail with NULL buf_index");
    cr_assert_eq(errno, EINVAL, "errno should be set to EINVAL");
}