/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 23:25:23 by aramos-m          #+#    #+#             */
/*   Updated: 2024/07/31 23:15:20 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(char specifier, va_list args)
{
	if (specifier == 'c')
		return (print_char(va_arg(args, int)));
	else if (specifier == 's')
		return (print_str(va_arg(args, char *)));
	else if (specifier == 'p')
		return (print_ptr(va_arg(args, void *)));
	else if (specifier == 'd' || specifier == 'i')
		return (print_int(va_arg(args, int)));
	else if (specifier == 'u')
		return (print_base(va_arg(args, unsigned int), DEC, 10));
	else if (specifier == 'x')
		return (print_base(va_arg(args, unsigned int), HEX, 16));
	else if (specifier == 'X')
		return (print_base(va_arg(args, unsigned int), HEXUP, 16));
	else if (specifier == '%')
		return (print_char('%'));
	return (0);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, fmt);
	while (fmt[i])
	{
		if (fmt[i] == '%' && fmt[i + 1])
		{
			len += print_format(fmt[i + 1], args);
			i++;
		}
		else
			len += write(1, &fmt[i], 1);
		i++;
	}
	va_end (args);
	return (len);
}
