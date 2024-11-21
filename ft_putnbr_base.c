/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:32:01 by tsomacha          #+#    #+#             */
/*   Updated: 2024/11/19 15:02:20 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int ft_printnbr_base(long nbr, int base, int set_case) {
    int len = 0;

    if (nbr < 0) {
        len += ft_printchar('-');
        len += ft_printnbr_base((0 - nbr), base, set_case);
        return len;
    }

    if (nbr < base) {
        len += ft_printdigit(nbr, set_case);
    } else {
        len += ft_printnbr_base((nbr / base), base, set_case);
        len += ft_printdigit((nbr % base), set_case);
    }
    return len;
}


