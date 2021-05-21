/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 22:45:23 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/05/21 17:42:01 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_charset(char c, char const *set)
{
	while (*set && set)
	{
		if (c == *set)
			return (1);
		else
			set++;
	}
	return (0);
}

static int	size_malloc(char const *str, char const *set)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (is_charset(str[i], set))
			i++;
		else if (!is_charset(str[i], set))
		{
			i++;
			count++;
		}
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	size_t	sizeset;
	int		i;
	int		n;

	n = 0;
	i = 0;
	sizeset = ft_strlen(set);
	ptr = malloc(sizeof(char) * size_malloc(s1, set));
	if (!ptr)
		return (NULL);
	while (s1[i])
	{
		if (is_charset(s1[i], set))
			i++;
		else if (!is_charset(s1[i], set))
			ptr[n++] = s1[i++];
	}
	ptr[n] = 0;
	return (ptr);
}
