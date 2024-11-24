#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>
#include "ft_printf.h"

int main ()
{
	close(STDOUT_FILENO);

	int result1 = printf("Number: %d\n", INT_MAX);
	int result2 = ft_printf("Number: %d\n", INT_MAX);

	if (result1 <= 0)
	{
		fprintf(stderr, "Error printing (printf): ");
		perror("");
		fprintf(stderr, "result1 : %d\n",result1);
	}
	else
	{
		fprintf(stderr, "Printed %d characters by printf\n", result1);
	}

	if (result2 <= 0)
	{
		fprintf(stderr, "Error printing (ft_printf): ");
		perror("");
		fprintf(stderr, "result2 : %d\n",result2);
	}
	else
	{
		fprintf(stderr, "Printed %d characters by ft_printf\n", result2);
	}
	return (0);
}
