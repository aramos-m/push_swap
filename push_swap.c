/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 21:21:34 by aramos-m          #+#    #+#             */
/*   Updated: 2024/11/24 22:44:56 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void qsort (void* base, size_t num, size_t size, 
           int (*comparator)(const void*,const void*));

int comparador (const void* p1 , const void* p2 ); 
/*Elements to be compared (stack a and b).
Return values:
- (<0): the element pointed by p1 goes before the element pointed by p2
- (0): */

void    sa(t_list **stacka)
{
    t_list tmp;

    tmp = *stacka->next;
    *stacka->next = *stacka->next->next;
    tmp->next = *stacka;
    **stacka = &tmp;
}
void    pa(t_list **stacka, t_list **stackb)
{
    t_list tmp;
    
    tmp = stackb->next;
    stackb->next = stacka;
    stackb = tmp;
}