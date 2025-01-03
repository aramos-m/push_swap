/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 21:20:53 by aramos-m          #+#    #+#             */
/*   Updated: 2025/01/03 21:54:17 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_list  *prev_node(t_list *head, t_list *node)
{
    while (head)
    {
        if (head->next == node)
            return head;
        head = head->next;
    }
    return (NULL);
}