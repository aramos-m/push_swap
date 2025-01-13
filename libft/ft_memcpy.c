/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 20:57:33 by aramos-m          #+#    #+#             */
/*   Updated: 2023/11/21 21:02:57 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*auxdest;
	const char	*auxsrc;

	if ((dest == NULL) && (src == NULL))
		return (NULL);
	i = 0;
	auxdest = dest;
	auxsrc = src;
	while (i < n)
	{
		auxdest[i] = auxsrc[i];
		i++;
	}
	return (dest);
}
