/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists-review.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 14:31:14 by aramos-m          #+#    #+#             */
/*   Updated: 2024/12/22 21:05:14 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int				x;
	struct Node*	next;
} Node;

int	main(int argc, char* argv[])
{
	Node root;
	root.x = 15;
	root.next = malloc(sizeof(Node));
	root.next->x = -2;
	root.next->next = malloc(sizeof(Node));
	root.next->next->x = 22;
	root.next->next->next = NULL;

	Node* curr = &root;
	while (curr)
	{
		printf("%d\n", curr->x);
		curr = curr->next;
	}

	for (Node* curr = &root; curr; curr = curr->next)
	{


	free(root.next->next);
	free(root.next);
	return 0;
}