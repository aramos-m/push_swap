/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:22:54 by aramos-m          #+#    #+#             */
/*   Updated: 2024/10/13 16:39:27 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digit(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	fill_snumber(int n, char *snumber, int i)
{
	snumber[i] = '\0';
	while (n != 0)
	{
		if (snumber[i] != '-')
		{
			snumber[i - 1] = (n % 10) + '0';
			n /= 10;
		}
		i--;
	}
}

char	*ft_itoa(int n)
{
	char	*snumber;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (n == 0)
		return (ft_strdup("0"));
	i = count_digit(n);
	snumber = (char *)malloc(sizeof(char) * (i + 1));
	if (!snumber)
		return (NULL);
	if (n < 0)
	{
		snumber[0] = '-';
		n *= -1;
	}
	fill_snumber(n, snumber, i);
	return (snumber);
}
