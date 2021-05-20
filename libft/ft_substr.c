/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 18:06:55 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/05/20 17:08:47 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*ptr;

	i = 0;
	if (len > ft_strlen(s))
	{
		ptr = malloc(ft_strlen(s) * sizeof(char) + 1);
		if (!ptr)
			return (NULL);
	}
	else
	{
		ptr = malloc(len * sizeof(char) + 1);
		if (!ptr)
			return (NULL);
	}
	while (s[i + start] && i < len && start < ft_strlen(s))
	{
		ptr[i] = s[i + start];
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}
