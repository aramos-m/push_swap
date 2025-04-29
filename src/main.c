/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 21:33:01 by aramos-m          #+#    #+#             */
/*   Updated: 2025/04/03 21:13:02 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	free_split(char **result)
{
	int	i;

	i = 0;
	while (result[i] != 0)
	{
		free(result[i]);
		i++;
	}
	free(result);
}

int	check_error(t_list *a)
{
	if (a != 0)
		ft_lstclear(&a, free);
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

t_list	*argv_to_lst(char **argv, t_list *stacka, int i)
{
	char	**argv2;
	int		j;
	t_list	*tmp;

	stacka = 0;
	while (argv[i])
	{
		j = 0;
		argv2 = ft_split(argv[i++], ' ');
		while (argv2[j])
			trim_str(argv2[j++], 0);
		tmp = fill_stack(argv2);
		free_split(argv2);
		if (!tmp)
		{
			ft_lstclear(&stacka, free);
			return (0);
		}
		if (!stacka)
			stacka = tmp;
		else
			ft_lstlast(stacka)->next = tmp;
	}
	return (stacka);
}

int	main(int argc, char **argv)
{
	t_list	*stacka;

	stacka = 0;
	if (argc == 1)
		return (0);
	stacka = argv_to_lst(argv, stacka, 1);
	if (!stacka)
		return (0);
	if (check_duplicate(stacka))
		return (check_error(stacka));
	if (ft_lstsize(stacka) < 6)
		sort_to_five(stacka, NULL);
	else
	{
		stacka = sort_more_five(stacka);
		radix(stacka, NULL, ft_lstsize(stacka));
	}
	return (0);
}
