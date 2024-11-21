#include <stdio.h>
#include "ft_printf.h"

int main ()
{
	printf(" 01 : %i\n ", 0);
	printf(" 02 : %i\n ", -1);
    printf(" 20 : %i\n ", -100);
    printf(" 21 : %i\n ", -101);
    // printf(" 22 : %d\n ", INT_MAX);
    // printf(" 23 : %d\n ", INT_MIN);
    // printf(" 24 : %ld\n ", LONG_MAX);
    // printf(" 25 : %ld\n ", LONG_MIN);
    // printf(" 26 : %d\n ", UINT_MAX);
    // printf(" 27 : %ld\n ", ULONG_MAX);
    // printf(" 28 : %lld\n ", 9223372036854775807LL);
	// printf(" 29 : %d %d %ld %ld %ld %d %d\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);

	ft_printf(" 01 : %i\n ", 0);
	ft_printf(" 02 : %i\n ", -1);
    ft_printf(" 20 : %i\n ", -100);
    ft_printf(" 21 : %i\n ", -101);
    // ft_printf(" 22 : %d\n", INT_MAX);
    // ft_printf(" 23 : %d\n ", INT_MIN);
    // ft_printf(" 24 : %ld\n ", LONG_MAX);
    // ft_printf(" 25 : %ld\n ", LONG_MIN);
    // ft_printf(" 26 : %d\n ", UINT_MAX);
    // ft_printf(" 27 : %ld\n ", ULONG_MAX);
    // ft_printf(" 28 : %ld\n ", 9223372036854775807LL);
	// ft_printf(" 29 : %d %d %ld %ld %ld %d %d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);

	return (0);
}
