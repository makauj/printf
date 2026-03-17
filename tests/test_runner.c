#include <stdio.h>
#include "../main.h"

static int failures = 0;

int run_printf_behavior_tests(void);

static void assert_equal_int(const char *name, int expected, int actual)
{
	if (expected != actual)
	{
		fprintf(stderr, "[FAIL] %s: expected %d, got %d\n", name, expected, actual);
		failures++;
	}
	else
	{
		fprintf(stderr, "[PASS] %s\n", name);
	}
}

int main(void)
{
	char local[BUFFER_SIZE] = "abc";
	size_t idx = 3;
	int rc;

	/* Basic behavioral tests for return values and output path stability. */
	assert_equal_int("_printf literal length", 5, _printf("hello"));
	assert_equal_int("_printf percent", 1, _printf("%%"));
	assert_equal_int("_printf string", 3, _printf("%s", "abc"));
	assert_equal_int("_printf integer", 2, _printf("%d", 42));
	assert_equal_int("_printf pointer non-null", 6, _printf("%p", (void *)0x1234));

	rc = flush_buffer(local, &idx);
	assert_equal_int("flush_buffer success", 0, rc);
	assert_equal_int("flush_buffer resets index", 0, (int)idx);

	failures += run_printf_behavior_tests();

	if (failures != 0)
	{
		fprintf(stderr, "\nTotal failures: %d\n", failures);
		return 1;
	}

	fprintf(stderr, "\nAll baseline tests passed.\n");
	return 0;
}
