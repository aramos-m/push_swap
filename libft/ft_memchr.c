/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 22:02:41 by aramos-m          #+#    #+#             */
/*   Updated: 2023/11/21 21:25:57 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*saux;

	i = 0;
	saux = (unsigned char *)s;
	while (i < n)
	{
		if ((unsigned char)c == saux[i])
			return (saux + i);
		i++;
	}
	return (0);
}
