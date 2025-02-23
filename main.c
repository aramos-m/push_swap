/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 21:33:01 by aramos-m          #+#    #+#             */
/*   Updated: 2025/02/23 20:53:08 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_error(void)
{
	ft_printf("Error\n");
	return (0);
}

int main(int argc, char **argv)
{
	t_list *a;
	t_list *b;
	t_list *tmp;
	int		i;
	char	**argv2;

	a = NULL;
    b = NULL;
	i = 1;

	if (argc == 1)
		return(check_error());
	while (argv[i])
	{
		argv2 = ft_split(argv[i], ' '); 
		tmp = fill_stack(argv2);
		if (!tmp)
			return (check_error());
		if (!a)
			a = tmp;
		else
			ft_lstlast(a)->next = tmp;
		i++; // racanear líneas: &argv[i++]
	}
	if (ft_lstsize(a) < 6)
		sort_to_five(a, b);
    else
    {
        a = sort_more_five(a);
        radix(a, b, ft_lstsize(a));
    }
}