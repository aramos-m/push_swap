/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 21:21:34 by aramos-m          #+#    #+#             */
/*   Updated: 2025/01/03 21:54:12 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void qsort (void* base, size_t num, size_t size, 
           int (*comparator)(const void*,const void*));

int comparador (const void* p1 , const void* p2 ); 
/*Elements to be compared (stack a and b).
Return values:
- (<0): the element pointed by p1 goes before the element pointed by p2
- (0): */

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