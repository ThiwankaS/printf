/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 20:58:52 by tsomacha          #+#    #+#             */
/*   Updated: 2024/11/19 15:07:22 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_formatconversion(char flag, va_list args)
{
	int length;

	length = 0;
	if(flag == 'c')
		length += ft_printchar(va_arg(args, int));
	else if(flag == 's')
		length += ft_printstr(va_arg(args, char *));
	else if(flag == 'p')
		length += ft_printpointer(va_arg(args, long), 16 , 0);
	else if(flag == 'd' || flag == 'i' || flag == 'u')
		length += ft_printnbr_base(va_arg(args, long), 10 , 0);
	else if(flag == 'x')
		length += ft_printnbr_base(va_arg(args, long), 16, 0);
	else if(flag == 'X')
		length += ft_printnbr_base(va_arg(args, long), 16, 1);
	return (length);
}

int	ft_printf(const char *format, ...)
{
	int		printed;
	int 	count;
	va_list	args;

	va_start(args, format);
	printed = 0;
	count = 0;
	while (format[count])
	{
		if(format[count] == '%' && format[count + 1] != '\0')
		{
			count++;
			printed += ft_formatconversion(format[count], args);
		}
		else if (format[count] != '\0')
		{
			ft_printchar(format[count]);
			printed++;
		}
		count++;
	}
	va_end(args);
	return (printed);
}
