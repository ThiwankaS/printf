/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 20:58:52 by tsomacha          #+#    #+#             */
/*   Updated: 2024/11/18 15:57:01 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int	count;
	va_list	args;

	va_start(args, str);
	count = 0;
	while(str[count])
	{
		if(str[count] == '%')
		{
			count++;
			if(str[count] == 'c')
			{
				ft_printchar(va_arg(args, int));
			}
			else if(str[count] == 's')
			{
				ft_printstr(va_arg(args, char *));
			}
			else if(str[count] == 'p')
			{
				ft_printstr
			}
		}
		else
		{
			ft_printchar(str[count]);
		}
		count++;
	}
	va_end(args);
	return (1);
}
