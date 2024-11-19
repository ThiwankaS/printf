/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 08:53:33 by tsomacha          #+#    #+#             */
/*   Updated: 2024/11/19 14:37:22 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

int	ft_printchar(int c);
int	ft_printf(const char *format, ...);
int	ft_printstr(char *str);
int	ft_printdigit(int c, int set_case);
int	ft_printnbr_base(long nbr, int base, int set_case);
int	ft_printpointer(long nbr, int base, int set_case);

#endif
