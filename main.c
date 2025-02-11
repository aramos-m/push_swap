/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 21:33:01 by aramos-m          #+#    #+#             */
/*   Updated: 2025/02/11 21:18:32 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	num_len(int num)
{
	int	count;

	count = 0;

	if (num < 0)
		count = 1;
	while (num)
	{
		num = num / 10;
		count ++;
	}
	return (count);
}

int main(int argc, char **argv)
{
	t_list *a;
	t_list *b;
	int		i;
	char	**argv2;

    b = 0;
	i = 1;
	while (argv[i])
	{
		argv2 = ft_split(&argv[i], ' '); 
		if (!a)
			a = fill_stack(argv2);
		else
			ft_lstlast(a)->next = fill_stack(argv2);
		i++; // racanear líneas: &argv[i++]
	}
	if (argc < 7)
		sort_to_five(a, b);
    else
    {
        a = sort_more_five(a);
        radix(a, b, argc);
    }
}