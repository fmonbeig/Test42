/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 10:07:53 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/05/21 11:08:52 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wordcount(const char *str, char c)
{
	int	i;
	int	count;
	int	state;

	state = 1;
	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			state = 1;
		}
		else if (str[i] != c && state == 1)
		{
			state = 0;
			count++;
		}
		i++;
	}
	return (count);
}

static int	size_word(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		words;
	int		index;
	int		i;

	index = -1;
	words = wordcount(s, c);
	ptr = malloc(sizeof(char *) * words + 1);
	if (!ptr)
		return (NULL);
	while (++index < words)
	{
		while (*s == c)
			s++;
		ptr[index] = malloc(sizeof(char) * size_word(s, c) + 1);
		if (!ptr[index])
			return (NULL);
		i = 0;
		while (*s != c && *s)
			ptr[index][i++] = *s++;
		ptr[index][i] = 0;
	}
	ptr[index] = 0;
	return (ptr);
}
