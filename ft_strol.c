/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strol.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 08:56:13 by tsomacha          #+#    #+#             */
/*   Updated: 2024/11/14 09:21:25 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <stdlib.h>

long strtol(const char *nptr, char **endptr, int base)
{
	const char *s = nptr;
	long result = 0;
	int sign = 1;

	while (isspace((unsigned char)*s))
		s++;

	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	if (base == 0)
	{
		if (*s == '0')
		{
			if (*(s + 1) == 'x' || *(s + 1) == 'X')
			{
				base = 16;
				s += 2;
			}
			else
			{
				base = 8;
				s++;
			}
		}
		else
		{
			base = 10;
		}
	}
	if (base < 2 || base > 36)
	{
		errno = EINVAL;
		return (0);
	}
	while (*s)
	{
		int digit;
		if (*s >= '0' && *s <= '9')
			digit = *s - '0';
		else if (*s >= 'a' && *s <= 'z')
			digit = *s - 'a' + 10;
		else if (*s >= 'A' && *s <= 'Z')
			digit = *s - 'A' + 10;
		else
			break;
		if (digit >= base)
			break;
		if (result > (LONG_MAX - digit) / base)
		{
			errno = ERANGE;
			return (sign == 1 ? LONG_MAX : LONG_MIN);
		}
		result = result * base + digit;
		s++;
	}
	if (endptr != NULL)
		*endptr = (char *)(*s ? s : nptr);
	return (result * sign);
}
