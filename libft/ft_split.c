/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:15:58 by aramos-m          #+#    #+#             */
/*   Updated: 2023/11/21 21:40:09 by aramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*divide(char const *s, char c, int *pos)
{
	int		i;
	int		j;
	char	*split;

	i = *pos;
	j = 0;
	while (s[i] && s[i] != c)
		i++;
	split = ft_calloc(sizeof(char), (i - *pos + 1));
	if (!split)
		return (NULL);
	i = *pos;
	while (s[i] && s[i] != c)
		split[j++] = s[i++];
	*pos = i;
	return (split);
}

int	count_word(char const *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		word ++;
		while (s[i] && s[i] != c)
			i++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (word);
}

static void	free_result(char **result, int i)
{
	while (i > 0)
	{
		i--;
		free(result[i]);
	}
	free(result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	i = count_word(s, c);
	j = 0;
	result = ft_calloc(sizeof(char *), (i + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (s[j])
	{
		if (s[j] != c)
		{
			result[i] = divide(s, c, &j);
			if (!result[i++])
				return (free_result(result, i), NULL);
		}
		else
			j++;
	}
	return (result);
}
