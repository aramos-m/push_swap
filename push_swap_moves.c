/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 21:21:34 by aramos-m          #+#    #+#             */
/*   Updated: 2025/01/21 20:17:29 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sab(t_list **stack, char ab)
{
	t_list	*tmp;

	tmp = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	tmp->next = *stack;
	*stack = tmp;
	if (ab != 'c')
		ft_printf("s%c\n", ab);
}

void	ss(t_list **stacka, t_list**stackb)
{
	sab(stacka, 'c');
	sab(stackb, 'c');
	ft_printf("ss\n");
}

// Corregir el próximo día
void	pab(t_list **stack1, t_list **stack2, char ab)
{
	t_list	*tmp;

	tmp = (*stack2)->next;
	(*stack2)->next = *stack1;
	*stack1 = *stack2;
	*stack2 = tmp;
	ft_printf("p%c\n", ab);
}

// Corregir el próximo día
void	rab(t_list **stack, char ab)
{
	t_list	*tmp;

	tmp = (*stack)->next;
	ft_lstlast(*stack)->next = *stack;
	(*stack)->next = NULL;
	*stack = tmp;
	if (ab != 'c')
		ft_printf("r%c\n", ab);
}

void	rr(t_list **stacka, t_list **stackb)
{
	rab(stacka, 'c');
	rab(stackb, 'c');
	ft_printf("rr\n");
}
