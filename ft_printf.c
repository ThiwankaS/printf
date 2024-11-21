/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 20:58:52 by tsomacha          #+#    #+#             */
/*   Updated: 2024/11/21 19:06:24 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_formatconversion(char flag, va_list args)
{
	if (flag == 'c')
		return (ft_printchar(va_arg(args, int)));
	else if (flag == 's')
		return (ft_printstr(va_arg(args, char *)));
	else if (flag == 'p')
		return (ft_printpointer(va_arg(args, long long)));
	else if (flag == 'i' || flag == 'd')
		return (ft_printnbr_base(va_arg(args, int), 10, 0));
	else if (flag == 'u')
		return (ft_printnbr_base(va_arg(args, unsigned), 10, 0));
	else if (flag == 'x')
		return (ft_printnbr_base(va_arg(args, unsigned), 16, 0));
	else if (flag == 'X')
		return (ft_printnbr_base(va_arg(args, unsigned), 16, 1));
	else if (flag == '%')
		return (ft_printchar('%'));
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	int		printed;
	int		count;
	int		res;
	va_list	args;

	va_start(args, format);
	printed = 0;
	count = 0;
	while (format[count] && res != -1)
	{
		res = 0;
		if (format[count] == '%' && format[count + 1] != '\0')
		{
			res = ft_formatconversion(format[++count], args);
			if(res < 0)
				break ;
			printed += res;
		}
		else if (format[count] == '%' && format[count + 1] == '\0')
		{
			res = -1;
			break ;
		}
		else
		{
			res = ft_printchar(format[count]);
			if(res < 0)
				break ;
			printed += res;
		}
		count++;
	}
	va_end(args);
	if(res < 0)
		printed = res;
	return (printed);
}
