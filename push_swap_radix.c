/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_radix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 13:14:51 by aramos-m          #+#    #+#             */
/*   Updated: 2025/03/02 19:55:42 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Crea una nueva lista con la posición de cada valor de la lista original
t_list  *sort_more_five(t_list *num)
{
    t_list  *fixed;
    t_list  *iter;
    t_list  *new_lst;
    int     *i;

    fixed = num;
    i = malloc(sizeof(int));
    new_lst = ft_lstnew(i);
    while (fixed)
    {
        *i = 0;
        iter = num;
        while (iter)
        {
            if (*((int *)(fixed->content)) > *((int *)(iter->content)))
                *i = *i + 1;
            iter = iter->next;
        }
        if (!fixed->next)
            ft_lstlast(new_lst)->next = NULL;
        else
        {
            i = malloc(sizeof(int));
            ft_lstadd_back(&new_lst, ft_lstnew(i));
        }
        fixed = fixed->next;
    }
    return (new_lst);
}

// Comprobar cada cifra con su equivalencia en binario para separarlo en dos stacks 0 y 1
void    radix(t_list *a, t_list *b, int size)
{
    int index;
    int count;

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
