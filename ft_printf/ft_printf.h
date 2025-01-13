/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 19:10:50 by aramos-m          #+#    #+#             */
/*   Updated: 2024/07/30 21:51:04 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

# define HEX "0123456789abcdef"
# define HEXUP "0123456789ABCDEF"
# define DEC "0123456789"

/*FT_PRINTF FUNCTION*/
int		ft_printf(char const *fmt, ...);

/*AUX FUNCTION*/
int		print_char(int c);
int		print_str(char *str);
int		print_base(unsigned long long nb, char *base, int base_len);
int		print_ptr(void *ptr);
int		print_int(int nb);

#endif
