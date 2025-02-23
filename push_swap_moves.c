/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 21:21:34 by aramos-m          #+#    #+#             */
/*   Updated: 2025/02/23 20:26:45 by aramos-m         ###   ########.fr       */
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

void	pab(t_list **dst, t_list **src, char ab)
{
	t_list	*tmp;

	tmp = (*src)->next;
	if (*dst)
		(*src)->next = *dst;
	else
		(*src)->next = NULL;
	*dst = *src;
	*src = tmp;
	ft_printf("p%c\n", ab);
} 


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
