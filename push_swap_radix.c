/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_radix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 13:14:51 by aramos-m          #+#    #+#             */
/*   Updated: 2025/02/08 22:22:43 by aramos-m         ###   ########.fr       */
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

    while(fixed)
    {
        *i = 0;
        iter = num;
        while (iter)
        {
            if (*((int *)(fixed->content)) > *((int *)(iter->content)))
                *i = *i + 1;
            iter = iter->next;
        }
        fixed = fixed->next;
        i = malloc(sizeof(int));
        ft_lstadd_back(&new_lst, ft_lstnew(i));
    }
    return (new_lst);
}
