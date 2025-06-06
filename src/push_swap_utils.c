/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 21:20:53 by aramos-m          #+#    #+#             */
/*   Updated: 2025/04/02 21:41:36 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_list	*prev_node(t_list *head, t_list *node)
{
	while (head)
	{
		if (head->next == node)
			return (head);
		head = head->next;
	}
	return (NULL);
}

int	check_sort(t_list *a)
{
	while (a->next)
	{
		if ((*(int *)(a->content)) > (*(int *)(a->next->content)))
			return (0);
		a = a->next;
	}
	return (1);
}

void	trim_str(char *argv2, int tmp)
{
	int	i;
	int	j;

	i = 0;
	if (argv2[i] == '-')
		tmp = ++i;
	else if (argv2[i] == '+')
		i++;
	if (argv2[i] == '-' || argv2[i] == '+')
	{
		return ;
	}
	while (argv2[i] == '0')
		i++;
	if (argv2[i] == '\0' && !(argv2[0] == '-' || argv2[0] == '+'))
		argv2 = "0";
	else
	{
		j = tmp;
		while (argv2[i] != '\0')
			argv2[j++] = argv2[i++];
		argv2[j] = '\0';
	}
	if (tmp == i)
		argv2[0] = '\0';
}

void	rrab(t_list **stack, char ab)
{
	t_list	*tmp;

	tmp = *stack;
	*stack = ft_lstlast(*stack);
	(prev_node(tmp, *stack))->next = NULL;
	(*stack)->next = tmp;
	if (ab != 'c')
		ft_printf("rr%c\n", ab);
}

void	rrr(t_list **stacka, t_list **stackb)
{
	rrab(stacka, 'c');
	rrab(stackb, 'c');
	ft_printf("rrr\n");
}
