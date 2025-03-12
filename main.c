/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 21:33:01 by aramos-m          #+#    #+#             */
/*   Updated: 2025/03/02 22:11:42 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_error(void)
{
	write(2, "Error\n", 6);
	return (0);
}

int	check_duplicate(t_list *stack)
{
	t_list	*iter;

	while (stack)
	{
		iter = stack->next;
		while (iter)
		{
			if (*(int *)(iter)->content == *(int *)(stack)->content)
				return (1);
			iter = iter->next;
		}
		stack = stack->next;
	}
	return (0);
}

t_list	*argv_to_lst(char **argv)
{
	char	**argv2;
	int		i;
	t_list	*tmp;
	t_list	*a;

	i = 1;
	a = 0;
	while (argv[i])
	{
		argv2 = ft_split(argv[i], ' ');
		tmp = fill_stack(argv2);
		if (!tmp)
			return (0);
		if (!a)
			a = tmp;
		else
			ft_lstlast(a)->next = tmp;
		i++;
	}
	return (a);
}

int	main(int argc, char **argv)
{
	t_list	*a;

	if (argc == 1)
		return (check_error());
	a = argv_to_lst(argv);
	if (!a || check_duplicate(a))
		return (check_error());
	if (ft_lstsize(a) < 6)
		sort_to_five(a, NULL);
	else
	{
		a = sort_more_five(a);
		radix(a, NULL, ft_lstsize(a));
	}
}
