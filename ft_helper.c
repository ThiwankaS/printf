/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 08:56:13 by tsomacha          #+#    #+#             */
/*   Updated: 2024/11/14 09:21:25 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(int c)
{
	write(1,&c,1);
	return (0);
}
int	ft_printstr(char *s)
{
	int	count;

	count = 0;
	while(s[count])
	{
		write(1,&s[count],1);
		count++;
	}
	return(0);
}

int	ft_printdigit(int c)
{
	if(c >=0 && c <= 9)
	{
		ft_printchar(c + 48);
	}
	else if(c >= 10 && c <= 15)
	{
		ft_printchar(c + 55);
	}
	return (0);
}
