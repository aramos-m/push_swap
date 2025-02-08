/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 21:33:01 by aramos-m          #+#    #+#             */
/*   Updated: 2025/02/09 00:30:46 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_list *a;
	t_list *b;
	//char **arg2;

    a = 0;
    b = 0;
	//argc = 4;
	//arg2 = ft_split("ana,2,23,6", ',');
	a = fill_stack(argc, argv);
	if (argc < 7)
		sort_to_five(a, b);
    else
    {
        a = sort_more_five(a);
        radix(a, b, argc);
    }
}