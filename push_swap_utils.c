/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 21:20:53 by aramos-m          #+#    #+#             */
/*   Updated: 2025/01/14 22:44:11 by aramos-m         ###   ########.fr       */
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
