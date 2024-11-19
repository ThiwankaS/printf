#include <stdio.h>
#include "libft/libft.h"
#include "ft_printf.h"

int main (int argc, char *argv[])
{
	if(argc > 1)
	{
		printf("original : %X\n",ft_atoi(argv[1]));
		ft_printf("custome : %X\n",ft_atoi(argv[1]));
	}
	return (0);
}
