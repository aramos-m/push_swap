/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_major.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 13:14:51 by aramos-m          #+#    #+#             */
/*   Updated: 2025/04/02 22:37:15 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*sort_more_five(t_list *num)
{
	t_list	*fixed;
	t_list	*iter;
	t_list	*new_lst;

	fixed = num;
	new_lst = ft_lstnew(malloc(sizeof(int)));
	while (fixed)
	{
		iter = num;
		while (iter)
		{
			if (*((int *)(fixed->content)) > *((int *)(iter->content)))
				*((int *)(fixed->content)) = *((int *)(fixed->content)) + 1;
			iter = iter->next;
		}
		if (!fixed->next)
			ft_lstlast(new_lst)->next = NULL;
		else
			ft_lstadd_back(&new_lst, ft_lstnew(malloc(sizeof(int))));
		fixed = fixed->next;
	}
	return (new_lst);
}

void	radix(t_list *a, t_list *b, int size)
{
	int	index;
	int	count;

	index = 0;
	while (!check_sort(a))
	{
		count = 1;
		while (count <= size)
		{
			if ((*(int *)(a->content)) & (1 << index))
				rab(&a, 'a');
			else
				pab(&b, &a, 'b');
			count++;
		}
		while (b)
			pab(&a, &b, 'a');
		index++;
	}
}
