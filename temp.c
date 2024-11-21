#include <stdio.h>

int main ()
{
	printf("output : original \n");
	int res1 = printf("hello error : % ");
	printf("\n");
	printf("output : custome \n");
	int res2 = ft_printf("hello error : % ");
	printf("\n value printf : %d\n",res1);
	printf("\n value ft_print: %d\n",res2);
	return (0);
}
