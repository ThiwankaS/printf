#include <stdio.h>
#include "ft_printf.h"

int main ()
{

	int n = 42;
	int *ptr = NULL;
	int n1 = printf("test : %p", ptr);
	printf("\n");
	int n2 = ft_printf("test : %p", ptr);
	printf("\n");
	printf("n1 : %d n2 : %d \n", n1, n2);
	return (0);
}
