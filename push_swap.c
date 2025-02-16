/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:37:55 by aramos-m          #+#    #+#             */
/*   Updated: 2025/02/16 20:46:06 by aramos-m         ###   ########.fr       */
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

// Crear el stack y rellenarlo
t_list	*fill_stack(char **argv)
{
	int		*value;
	int		i;
	t_list	*head;

	i = 0;
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
void	sort_three(t_list *head)
{	
	if (*(int*)head->content < *(int*)head->next->content)
	{
		if (*(int*)head->content < *(int*)ft_lstlast(head)->content) // Caso: 1 3 2
		{
			sab(&head, 'a');
			rab(&head, 'a');
		}
		else // Caso: 2 3 1
			rrab(&head, 'a');
	}
	else
	{
		if (*(int*)head->content < *(int*)ft_lstlast(head)->content || (ft_lstsize(head) < 3)) // Caso: 2 1 3
			sab(&head, 'a');
		else
		{
			if (*(int*)head->next->content < *(int*)ft_lstlast(head)->content) // Caso: 3 1 2
				rab(&head, 'a');
			else // Caso: 3 2 1
			{
				sab(&head, 'a');
				rrab(&head, 'a');
			}
		}
	}
}

void	move_minor(t_list **stacka, t_list **stackb, int i) // Ahorrar líneas iterador
{
	int	minor;
	int	pos;
	t_list	*tmp;

	tmp = *stacka;
	minor = *(int *)(*stacka)->content; // No se puede desreferenciar un void *	
	while ((*stacka)->next)
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
	if (pos == 3 || pos == 4)
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
	sort_three(stacka);
	while (ft_lstsize(stackb))	
		pab(&stacka, &stackb, 'a');
}
