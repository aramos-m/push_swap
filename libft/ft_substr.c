/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:31:33 by aramos-m          #+#    #+#             */
/*   Updated: 2024/10/01 22:31:31 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ssub;

	if (!s)
		return (NULL);
	if (start > (unsigned int)ft_strlen(s))
	{
		ssub = ft_calloc(sizeof(char), 1);
		if (!ssub)
			return (NULL);
	}
	else
	{
		if (len > (size_t)ft_strlen(s + start))
			len = (unsigned int)ft_strlen(s + start);
		ssub = ft_calloc(sizeof(char), len + 1);
		if (!ssub)
			return (NULL);
		ft_memmove(ssub, s + start, len);
	}
	return (ssub);
}
