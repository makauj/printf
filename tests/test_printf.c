#include <limits.h>
#include <stdio.h>
#include <string.h>
#include "../main.h"

static int failures = 0;

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

int run_printf_behavior_tests(void)
{
	char expected[32];
	int expected_len;

	assert_equal_int("unknown specifier %q length", 2, _printf("%q"));
	assert_equal_int("null string substitution", 6, _printf("%s", (char *)NULL));

	expected_len = snprintf(expected, sizeof(expected), "%d", INT_MAX);
	assert_equal_int("INT_MAX formatting length", expected_len, _printf("%d", INT_MAX));

	expected_len = snprintf(expected, sizeof(expected), "%d", INT_MIN);
	assert_equal_int("INT_MIN formatting length", expected_len, _printf("%d", INT_MIN));

	return (failures);
}
