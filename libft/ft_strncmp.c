/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 14:32:50 by aramos-m          #+#    #+#             */
/*   Updated: 2023/11/21 21:23:54 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((i < n) && s2[i] && s1[i])
	{
		if (s2[i] != s1[i])
			return ((unsigned const char)s1[i] - (unsigned const char)s2[i]);
		i++;
	}
	if (i != n)
		return ((unsigned const char)s1[i] - (unsigned const char)s2[i]);
	return (0);
}
