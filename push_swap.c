/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:37:55 by aramos-m          #+#    #+#             */
/*   Updated: 2025/01/12 23:30:16 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

/* Crear el stack y rellenarlo*/
t_list	*fill_stack(int argc, char **argv)
{
	int		*value;
	int		i;
	t_list	*head;

	value = malloc(sizeof(int));
	if (!value)
		return (NULL);
	*value = ft_atoi(argv[1]);
	head = ft_lstnew(value);
	if (!head)
	{
		free(value);
		return (NULL);
	}

	i = 2;
	while (argv[i])
	{
		value = malloc(sizeof(int));
		if (!value)
		{
			ft_lstclear(&head, free);
			return (NULL);
		}
		*value = ft_atoi(argv[i]);
		ft_lstadd_back(&head, ft_lstnew(value));
		i++;
	}
	return (head);
}

/*Excepción: stack de 3 números*/
void	sort_stack_three(t_list *head)
{
	if (head->content < head->next->content)
	{
		if (head->content < ft_last(head)) // Caso: 1 3 2
		{
			rab(head);
			sab(head);
			rrab(head);
		}
		else // Caso: 2 3 1
			rrab(head);
	}
	else
	{
		if (head->content > ft_last(head)) // Caso: 2 1 3
			sab(head);
		else
		{
			if (head->content->next < ft_last(head)) // Caso: 3 1 2
				rab(head);
			else // Caso: 3 2 1
				rrab(head);
		}
	}
}

void	move_minor(t_list *stacka)
{
	int	minor;
	int	pos;
	int	i;

	i = 0;
	minor = stacka->content;
	while (stacka->next)
	{
		if (stacka->content < minor)
		{
			minor = stacka->content;
			pos = i;
		}
		stacka = stacka->next;
		i++;
	}
	if (pos == 2)
		rab(stacka);
	if (pos == 2 || pos == 1)
		rab(stacka);
	if (pos == 3)
		rrab(stacka);
	if (pos == 3 || pos == 4)
		rrab(stacka);
	sab(stacka);
	return (stacka);
}

/*Excepción: stack de 3 números*/

// Deshaceme de dos números para utilizar sort_stack_three
// Ordenar los tres números restantes con 'sort_stack_three' 