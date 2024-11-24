#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "ft_printf.h"

void test_cases(const char *desc, const char *format, ...) {
    va_list args1, args2;

    char printf_buffer[1024] = {0};
    char ft_printf_buffer[1024] = {0};

    va_start(args1, format);
    int printf_result = vsnprintf(printf_buffer, sizeof(printf_buffer), format, args1);
    va_end(args1);

    va_start(args2, format);
    int ft_printf_result = vsnprintf(ft_printf_buffer, sizeof(ft_printf_buffer), format, args2);
    va_end(args2);

    printf("\nTest Case: %s\n", desc);
    printf("Expected (printf): %s\n", printf_buffer);
    printf("Actual   (ft_printf): %s\n", ft_printf_buffer);

    if (strcmp(printf_buffer, ft_printf_buffer) == 0 && printf_result == ft_printf_result) {
        printf("Result: ✅ Passed\n");
    } else {
        printf("Result: ❌ Failed\n");
        printf("Return values - printf: %d, ft_printf: %d\n", printf_result, ft_printf_result);
    }
}

int main() {

    test_cases("Character test", "%c", 'A');
    test_cases("String test", "%s", "Hello, World!");
    test_cases("Pointer test", "%p", (void *)0x12345678);
    test_cases("Integer test", "%d", -123);
    test_cases("Integer test (zero)", "%i", 0);
    test_cases("Unsigned test", "%u", 123456789);
    test_cases("Hexadecimal test (lowercase)", "%x", 0xabcdef);
    test_cases("Hexadecimal test (uppercase)", "%X", 0xABCDEF);
    test_cases("Percent symbol test", "%%");
    test_cases("Null string", "%s", NULL);
    test_cases("Empty string", "%s", "");
    test_cases("Large number", "%d", 2147483647);
    test_cases("Small number", "%d", -2147483648);
    test_cases("Unsigned zero", "%u", 0);
    test_cases("Hexadecimal zero", "%x", 0);
    test_cases("Pointer null", "%p", NULL);
	test_cases("Max long uisng flag d", "%d", LONG_MAX);
	test_cases("Min long uisng flag d", "%p", LONG_MIN);
	test_cases("Unsined long long max uisng flag d", "%d", ULLONG_MAX);
	test_cases("long long min uisng flag d", "%d", LLONG_MIN);
	test_cases("Max long uisng flag i", "%i", LONG_MAX);
	test_cases("Min long uisng flag i", "%i", LONG_MIN);
	test_cases("Unsined long long max uisng flag i", "%i", ULLONG_MAX);
	test_cases("long long min uisng flag i", "%i", LLONG_MIN);
	test_cases("Max long uisng flag i", "%i", LONG_MAX);
	test_cases("Min long uisng flag i", "%i", LONG_MIN);
	test_cases("Unsined long long max uisng flag i", "%i", ULLONG_MAX);
	test_cases("long long min uisng flag i", "%i", LLONG_MIN);
	test_cases("Max long uisng flag u", "%u", LONG_MAX);
	test_cases("Min long uisng flag u", "%u", LONG_MIN);
	test_cases("Unsined long long max uisng flag u", "%u", ULLONG_MAX);
	test_cases("long long min uisng flag u", "%u", LLONG_MIN);
	test_cases("Inappropriate flag usage", "%");
	test_cases("Invalid flag usage", "%k");
	test_cases("Two percentage characters", "%%%");
    test_cases("More percentage characters", "%%%");
    test_cases("More percentage characters and space", "% %");
    test_cases("UNITMAX uisng flag d", "%d", UINT_MAX);
    test_cases("Lot of zeros", "%d %i %u %p %x %X %c %s", 0,0,0,0,0,0,0,0);

	//compiling command gcc test.c -L. -lftprintf -o test
    return 0;
}
