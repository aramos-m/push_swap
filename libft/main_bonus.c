/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <aramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 13:38:59 by aramos-m          #+#    #+#             */
/*   Updated: 2024/10/13 16:22:35 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_double1(void  *content)
{
	int	*num;
	num = (int *)content;
	*num += *num;
	return ;
}
void	*ft_double2(void *content)
{
	int	*num;
	num = (int *)content;
	*num += *num;
	return ((void *)num);
}

int main(void)
{
	/*BONUS PART*/
	printf("Esta es la función LSTNEW:\n");
	t_list	*new_node;
	new_node = ft_lstnew("Hola, soy Ana");
	printf("%s", new_node->content);
	printf('\n');

	printf("Esta es la función LSTADD_FRONT:\n");
	t_list	*a, *b;
	a = ft_lstnew("Ana");
	b = ft_lstnew("Soy");
	ft_lstadd_front(&a, b);
	printf("%s %s\n", b->content, b->next->content);
	printf('\n');

	printf("Esta es la función LSTSIZE:\n");
	t_list	*a, *b;
	a = ft_lstnew("Ana");
	b = ft_lstnew("Soy");
	ft_lstadd_front(&a, b);
	printf("%d\n", ft_lstsize(a));
	printf('\n');

	printf("Esta es la función LSTLAST:\n");
	t_list	*a, *b;
	a = ft_lstnew("Ana");
	b = ft_lstnew("Soy");
	ft_lstadd_front(&a, b);
	printf("%s\n", ft_lstlast(b)->content);
	printf('\n');
	
	printf("Esta es la función LSTADD_BACK:\n");
	t_list	*a, *b;
	a = ft_lstnew("Soy");
	b = ft_lstnew("Ana");
	ft_lstadd_back(&a, b);
	printf("%s %s", a->content, a->next->content);
	printf('\n');
	
	printf("Esta es la función LSTDELONE:\n");
	t_list	*a;
	char	*cont;
	cont = malloc(4);
	cont[0] = 'A';
	cont[1] = 'n';
	cont[2] = 'a';
	cont[3] = 0;
	a = ft_lstnew(cont);
	printf("%s\n", a->content);
	ft_lstdelone(a, free);
	if (a->content != "Ana")
		printf("Nodo eliminado");
	printf('\n');
	
	printf("Esta es la función LSTCLEAR:\n");
	t_list	*a, *b;
	char	*cont1, *cont2;
	cont1 = malloc(4);
	cont1[0] = 'A';
	cont1[1] = 'n';
	cont1[2] = 'a';
	cont1[3] = 0;
	cont2 = malloc(4);
	cont2[0] = 'A';
	cont2[1] = 'n';
	cont2[2] = 'a';
	cont2[3] = 0;
	a = ft_lstnew(cont1);
	b = ft_lstnew(cont2);
	a->next = b;
	printf("Content A: %s\nContent B: %s\n", a->content, a->next->content);
	ft_lstclear(&a, free);
	printf("%p\n", a);
	printf('\n');
	
	printf("Esta es la función LSTITER:\n");
	t_list	*a, *b;
	int		*cont1, *cont2;
	cont1 = malloc(sizeof(int *) * 1);
	cont2 = malloc(sizeof(int *) * 1);
	*cont1 = 3;
	*cont2 = 4;
	a = ft_lstnew(cont1);
	b = ft_lstnew(cont2);
	a->next = b;
	printf("Content A: %d\nContent B: %d\n", *(int *)a->content, *(int *)b->content);
	ft_lstiter(a, ft_double1);
	printf("Content A: %d\nContent B: %d\n", *(int *)a->content, *(int *)b->content);
	
	printf("Esta es la función LSTMAP:\n");
	t_list	*a, *b, *result;
	int		*cont1, *cont2;
	cont1 = malloc(sizeof(int *) *1);
	cont2 = malloc(sizeof(int *) *1);
	*cont1 = 3;
	*cont2 = 4;
	a = ft_lstnew(cont1);
	b = ft_lstnew(cont2);
	a->next = b;
	printf("Content A: %d\nContent B: %d\n", *(int *)a->content, *(int *)b->content);
	result = ft_lstmap(a, &ft_double2, free);
	printf("Content A: %d\nContent B: %d\n", *(int *)result->content, *(int *)result->next->content);
}
