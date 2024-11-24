/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 20:58:52 by tsomacha          #+#    #+#             */
/*   Updated: 2024/11/24 13:17:07 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(int c)
{
	return (write(1, &c, 1));
}

static int	ft_formatconversion(char flag)
{
	printf("flage value : %c\n", flag);

	return (0);

}

static int ft_handleformat(const char *format, int *count, int *error)
{
	int	res;
	int	printed;
	int step;

	res = 0;
	printed = 0;
	step = *count;
	if (format[step] == '%' && format[step + 1] != '\0')
	{
		res = ft_formatconversion('A');
		if(res < 0)
			*error = -1;
		printed += res;
	}
	else if (format[step] == '%' && format[step + 1] == '\0')
		*error = -1;
	else
	{
		res = ft_printchar(format[step]);
		if(res < 0)
			*error = -1;
		printed += res;
	}
	return (printed);
}

int	ft_printf(const char *format, ...)
{
	int		printed;
	int		count;
	int		error;
	va_list	args;

	va_start(args, format);
	printed = 0;
	count = 0;
	while (format[count] && error != -1)
	{
		error = 0;
		printed = ft_handleformat(format, &count, &error);
		count++;
	}
	va_end(args);
	if(error < 0)
		printed = error;
	return (printed);
}
