/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 18:48:49 by aramos-m          #+#    #+#             */
/*   Updated: 2024/10/02 21:43:01 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	msize;

	msize = count * size;
	if ((long long)count < 0 && (long long)size < 0)
		return (NULL);
	if ((msize) == SIZE_MAX || (long long)msize < 0)
		return (NULL);
	ptr = malloc(msize);
	if (ptr == NULL)
		return (NULL);
	else
		ft_bzero((void *)ptr, msize);
	return (ptr);
}
