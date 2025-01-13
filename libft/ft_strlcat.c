/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 22:38:43 by aramos-m          #+#    #+#             */
/*   Updated: 2023/11/22 20:47:01 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	int		result;

	if (!dstsize)
		return (ft_strlen(src));
	if (dstsize <= (size_t)ft_strlen(dst))
		return (dstsize + (size_t)ft_strlen(src));
	j = 0;
	i = ft_strlen(dst);
	while (src[j] != '\0' && i + 1 < dstsize)
		dst[i++] = src[j++];
	dst[i] = '\0';
	result = (ft_strlen(dst) + ft_strlen(&src[j]));
	return ((size_t)result);
}
