/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:14:14 by tsomacha          #+#    #+#             */
/*   Updated: 2024/11/21 13:18:54 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointer(unsigned long nbr)
{
	int	length;

	length = 0;
	if (nbr < 16)
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
	int	length;

	length = 0;
	if (nbr == 0)
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
