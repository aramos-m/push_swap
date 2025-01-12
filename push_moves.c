/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 21:21:34 by aramos-m          #+#    #+#             */
/*   Updated: 2025/01/12 23:30:57 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    sab(t_list **stack)
{
    t_list  *tmp;

    tmp = *stack->next;
    *stack->next = *stack->next->next;
    tmp->next = *stack;
    **stack = &tmp;
}

void    ss(t_list **stacka, t_list**stackb)
{
    sab(stacka);
    sab(stackb);
}

void    pab(t_list **stack1, t_list **stack2)
{
    t_list *tmp;
    
    tmp = *stack2->next;
    *stack2->next = *stack1;
    stack2 = tmp;
}

void    rab(t_list **stack)
{
    t_list *tmp;

    tmp = *stack->next;
    (ft_lslast(*stack))->next = *stack;
    *stack->next = NULL;
    **stack = &tmp;
}

void    rr(t_list **stacka, t_list **stackb)
{
    rab(stacka);
    rab(stackb);
}

void    rrab(t_list **stack)
{
    t_list *tmp;

    tmp = *stack;
    **stack = (ft_last(*stack));
    (prev_node(tmp, *stack))->next = NULL;
    *stack->next = &tmp;
}

void    rrr(t_list **stacka, t_list **stackb)
{
    rrab(**stacka);
    rrab(**stackb);
}