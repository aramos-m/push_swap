/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:37:55 by aramos-m          #+#    #+#             */
/*   Updated: 2025/04/01 22:09:12 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three(t_list **h)
{
	if (*(int *)(*h)->content < *(int *)(*h)->next->content)
	{
		if (*(int *)(*h)->content < *(int *)ft_lstlast(*h)->content)
		{
			sab(h, 'a');
			rab(h, 'a');
		}
		else
			rrab(h, 'a');
	}
	else
	{
		if (*(int *)(*h)->content < *(int *)ft_lstlast(*h)->content)
			sab(h, 'a');
		else
		{
			if (*(int *)(*h)->next->content < *(int *)ft_lstlast(*h)->content)
				rab(h, 'a');
			else
			{
				sab(h, 'a');
				rrab(h, 'a');
			}
		}
	}
}

void	move_minor(t_list **stacka, t_list **stackb, int i, int pos)
{
	int		minor;
	t_list	*tmp;

	tmp = *stacka;
	minor = *(int *)(*stacka)->content;
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

void	sort_to_five(t_list *stacka, t_list *stackb)
{
	if (check_sort(stacka) == 1)
	{
		ft_lstclear(&stacka, free);
		return ;
	}
	if (ft_lstsize(stacka) == 2)
	{
		sab(&stacka, 'a');
		ft_lstclear(&stacka, free);
		return ;
	}
	while (ft_lstsize(stacka) > 3)
		move_minor(&stacka, &stackb, 0, 0);
	if (check_sort(stacka) == 0)
		sort_three(&stacka);
	while (ft_lstsize(stackb))
		pab(&stacka, &stackb, 'a');
	ft_lstclear(&stacka, free);
}
