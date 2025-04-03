/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_major.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 13:14:51 by aramos-m          #+#    #+#             */
/*   Updated: 2025/04/03 21:24:59 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*sort_more_five(t_list *num)
{
	t_list	*fixed;
	t_list	*iter;
	t_list	*tmp_lst;
	t_list	*return_lst;

	fixed = num;
	tmp_lst = ft_lstnew(ft_calloc(sizeof(int), 1));
	return_lst = tmp_lst;
	while (fixed)
	{
		iter = num;
		while (iter)
		{
			if (*((int *)(fixed->content)) > *((int *)(iter->content)))
				*((int *)(tmp_lst->content)) = *((int *)(tmp_lst->content)) + 1;
			iter = iter->next;
		}
		if (fixed->next)
			ft_lstadd_back(&tmp_lst, ft_lstnew(ft_calloc(sizeof(int), 1)));
		fixed = fixed->next;
		tmp_lst = tmp_lst->next;
	}
	ft_lstclear(&num, free);
	return (return_lst);
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
