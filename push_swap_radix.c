/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_radix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 13:14:51 by aramos-m          #+#    #+#             */
/*   Updated: 2025/01/26 22:31:42 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

// Crea una nueva lista con la posición de cada valor de la lista original
t_list  *sort_more_five(t_list *num)
{
    t_list  *fixed;
    t_list  *iter;
    t_list  *new_lst;
    int     *i;

    fixed = num;
    iter = num;
    i = malloc(sizeof(int));
    new_lst = ft_lstnew(i);

    while(fixed)
    {
        *i = 0;
        while (iter)
        {
            if (fixed->content > iter->content)
                *i++;
            iter = iter->next;
        }
        fixed = fixed->next;
        i = malloc(sizeof(int));
        ft_lstadd_back(&new_lst, ft_lstnew(i));
    }
    return (new_lst);
}

// Crear myArr con números desordenados
// Crear radixArr[10] de arrays vacío
// Recorrer el arr y ordenar los números en radixArr eg "12 50 34" / arr[0] = 12, arr[1] = 34, arr[2] = 50
// Recorrer cada x de myArr y buscar en las unidades
// Mover x de myArr al índice de radixArr que corresponda e.g. 431 = arr[1]
// Mover de nuevo cada x a myArr empezando desde radixArr[9]
// Repetir el proceso anterior con las decenas, centenas ...
