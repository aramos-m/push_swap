/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfutils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 23:22:00 by aramos-m          #+#    #+#             */
/*   Updated: 2024/07/31 21:41:20 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(int c)
{
	return (write(1, &c, 1));
}

int	print_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	print_base(unsigned long long nb, char *base, int base_len)
{
	if (nb < (unsigned long long)base_len)
		return (print_char(base[nb]));
	return (print_base(nb / base_len, base, base_len)
		+ print_base(nb % base_len, base, base_len));
}

int	print_ptr(void *ptr)
{
	if (!ptr)
		return (write(1, "(nil)", 5));
	else
		return (print_str("0x")
			+ print_base((unsigned long long)ptr, HEX, 16));
}

int	print_int(int nb)
{
	long int	lnb;

	lnb = nb;
	if (nb < 0)
		return (print_char ('-') + print_base(-lnb, DEC, 10));
	return (print_base(nb, DEC, 10));
}
