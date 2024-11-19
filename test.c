#include <stdio.h>
#include "ft_printf.h"

int main (void)
{
	char *st1 = "bc";
	char *st2 = " de ";
	int n = 42;
	int *ptr = &n;
	printf("Test for character : %c %s %s %c\n", 'a', st1, st2, 'f');
	printf("Pointer : %p\n", ptr);
	printf("Pointer : %p\n", ptr);
	ft_printf("Test for character : %c %s %s %c\n", 'a', st1, st2, 'f');
	return (0);
}
