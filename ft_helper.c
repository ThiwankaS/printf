/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 08:56:13 by tsomacha          #+#    #+#             */
/*   Updated: 2024/11/19 14:58:39 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(char *str)
{
	if(!str)
	{
		write(1,"(null)", 6);
		return (6);
	}
	int len = ft_strlen(str);
	write(1, str, len);
	return (len);
}

int	ft_printdigit(int c, int set_case)
{
	if(c < 10)
	{
		ft_printchar(c + 48);
	}
	else if(c >= 10 && c <= 15)
	{
		if(set_case)
			ft_printchar(c + 55);
		else
			ft_printchar(c + 87);
	}
	return (1);
}

int	ft_pointer(unsigned long nbr)
{
	int length;

	length = 0;
	if(nbr < 16)
		length += ft_printdigit(nbr, 0);
	else
	{
		length += ft_pointer((nbr / 16));
		length += ft_printdigit((nbr % 16), 0);
	}
	return (length);
}

int	ft_printpointer(unsigned long nbr)
{
	int length;

	length = 0;
	if(nbr == 0)
	{
		length += ft_printstr("(nil)");
	}
	else
	{
		length += ft_printstr("0x");
		length += ft_pointer(nbr);
	}
	return (length);
}
