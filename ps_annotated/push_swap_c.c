/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:37:55 by aramos-m          #+#    #+#             */
/*   Updated: 2025/03/02 22:22:46 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#define LSTLAST ft_lstlast 

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

// Crear el stack y rellenarlo
t_list	*fill_stack(char **argv)
{
	int		*value;
	int		i;
	t_list	*head;

	i = 0;
	head = 0;
	while (argv[i])
	{
		value = malloc(sizeof(int));
		if (!value)
		{
			ft_lstclear(&head, free);
			return (NULL);
		}
		*value = ft_atoi(argv[i]);
		if (ft_strlen(argv[i]) != num_len(*value))
			return (NULL);
		if (i == 0)
			head = ft_lstnew(value);
		else
			ft_lstadd_back(&head, ft_lstnew(value));
		i++;
	}
	return (head);
}

// Excepción: stack de 3 números
void	sort_three(t_list *h)
{
	if (*(int *)h->content < *(int *)h->next->content)
	{
		if (*(int *)h->content < *(int *)LSTLAST(h)->content)
		{
			sab(&h, 'a');
			rab(&h, 'a');
		}
		else
			rrab(&h, 'a');
	}
	else
	{
		if (*(int *)h->content < *(int *)LSTLAST(h)->content || (ft_lstsize(h) < 3))
			sab(&h, 'a');
		else
		{
			if (*(int *)h->next->content < *(int *)LSTLAST(h)->content)
				rab(&h, 'a');
			else
			{
				sab(&h, 'a');
				rrab(&h, 'a');
			}
		}
	}
}

void	move_minor(t_list **stacka, t_list **stackb, int i) // Ahorrar líneas iterador
{
	int		minor;
	int		pos;
	t_list	*tmp;

	tmp = *stacka;
	minor = *(int *)(*stacka)->content; // No se puede desreferenciar un void *	
	pos = 0;
	while ((*stacka))
	{
		if (*(int *)(*stacka)->content < minor)
		{
			minor = *(int *)(*stacka)->content;
			pos = i;
		}
		(*stacka) = (*stacka)->next;
		i++;
	}
	*stacka = tmp;
	if (pos == 2)
		rab(stacka, 'a');
	if (pos == 2 || pos == 1)
		rab(stacka, 'a');
	if (pos == 3)
		rrab(stacka, 'a');
	if (ft_lstsize(*stacka) > 4 && (pos == 3 || pos == 4))
		rrab(stacka, 'a');
	pab(stackb, stacka, 'b');
}

// Excepción: stack de 3 números
void	sort_to_five(t_list *stacka, t_list *stackb)
{
	if (check_sort(stacka) == 1)
		return ;
	stackb = 0;
	while (ft_lstsize(stacka) > 3)
		move_minor(&stacka, &stackb, 0);
	if (check_sort(stacka) == 0)
		sort_three(stacka);
	while (ft_lstsize(stackb))
		pab(&stacka, &stackb, 'a');
}
