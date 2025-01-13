/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:20:01 by aramos-m          #+#    #+#             */
/*   Updated: 2024/01/04 10:15:58 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*scat;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	scat = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!scat)
		return (NULL);
	while (s1[i])
		scat[j++] = s1[i++];
	i = 0;
	while (s2[i])
		scat[j++] = s2[i++];
	scat[j] = '\0';
	return (scat);
}
