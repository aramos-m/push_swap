/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 20:07:39 by aramos-m          #+#    #+#             */
/*   Updated: 2025/01/14 21:15:44 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

/*PUSH_SWAP FUNCTION*/
t_list	*fill_stack(int argc, char **argv);
void	sort_stack_three(t_list *head);
void	move_minor(t_list **stacka, t_list **stackb, int i);
void	sort_stack_five(t_list *stacka, t_list *stackb);

/*PUSH_SWAP_MOVES*/
void	sab(t_list **stack, char ab);
void	ss(t_list **stacka, t_list**stackb);
void	pab(t_list **stack1, t_list **stack2, char ab);
void	rab(t_list **stack, char ab);
void	rr(t_list **stacka, t_list **stackb);

/*PUSH_SWAP_UTILS*/
t_list	*prev_node(t_list *head, t_list *node);
void	rrab(t_list **stack, char ab);
void	rrr(t_list **stacka, t_list **stackb);

#endif