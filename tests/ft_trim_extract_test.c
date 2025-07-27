#include <string.h>
#include <stdio.h>

#include "rushlib.h"

int	test_compare(int test_number, const char *expected, const char *result)
{
	int	test_result = strcmp(result, expected);
	fprintf(stderr, "[%s] TEST %d: Expected %s, Result = %s\n",
					test_result ? "FAIL" : "PASS",
					test_number, expected, result);

	return (test_result);
}

int main(void)
{
	// Allocated chunks intentionally not freed.
	test_compare(1, "no space at ends",
	ft_trim_extract("   no space at ends    "));

	test_compare(2, "",
	ft_trim_extract(""));

	test_compare(3, "   ",
	ft_trim_extract("   "));

	test_compare(4, "a   a",
	ft_trim_extract("a   a"));
	return (0);
}
