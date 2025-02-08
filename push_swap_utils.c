/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 21:20:53 by aramos-m          #+#    #+#             */
/*   Updated: 2025/02/08 23:52:26 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*prev_node(t_list *head, t_list *node)
{
	while (head)
	{
		if (head->next == node)
			return (head);
		head = head->next;
	}
	return (NULL);
}

int	check_sort(t_list *a)
{
	while (a)
	{
		printf("checksort\n");
		if ((*(int *)(a->content)) > (*(int *)(a->next->content)))
			return (0); // Not sorted
		a = a->next;
	}
	return (1); // Sorted 
}

void	rrab(t_list **stack, char ab)
{
	t_list	*tmp;

	tmp = *stack;
	*stack = ft_lstlast(*stack);
	(prev_node(tmp, *stack))->next = NULL;
	(*stack)->next = tmp;
	if (ab != 'c')
		ft_printf("rr%c\n", ab);
}

void	rrr(t_list **stacka, t_list **stackb)
{
	rrab(stacka, 'c');
	rrab(stackb, 'c');
	ft_printf("rrr\n");
}
