#include "libft/libft.h"
#include "ft_printf.h"

int	ft_printnbr_base(int nbr, int base)
{
	if(nbr < 0)
	{
		ft_printchar('-');
		ft_printnbr_base(-nbr, base);
	}
	if(nbr < base)
	{
		ft_printdigit(nbr);
	}
	else
	{
		ft_printnbr_base(nbr / base, base);
		ft_printdigit(nbr % base);
	}
	return (0);
}
