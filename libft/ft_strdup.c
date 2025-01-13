/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 20:14:14 by aramos-m          #+#    #+#             */
/*   Updated: 2023/10/22 20:42:44 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*aux;

	aux = (char *)malloc(sizeof(*aux) * (ft_strlen(s) + 1));
	if (aux == NULL)
		return (NULL);
	else
		ft_strlcpy(aux, s, ft_strlen(s) + 1);
	return (aux);
}
