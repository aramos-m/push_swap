/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 20:24:45 by aramos-m          #+#    #+#             */
/*   Updated: 2024/10/13 16:38:45 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*flst;
	t_list	*result;

	result = 0;
	if (!lst || !*f || !del)
		return (NULL);
	while (lst)
	{
		flst = ft_lstnew(f(lst->content));
		if (!flst)
		{
			ft_lstclear(&result, del);
			return (NULL);
		}
		lst = lst->next;
		ft_lstadd_back(&result, flst);
	}
	return (result);
}
