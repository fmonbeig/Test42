/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 14:17:04 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/05/20 16:21:26 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	i;
	size_t	size;

	i = -1;
	size = ft_strlen(s1);
	ptr = malloc(size * sizeof(char) + 1);
	if (!ptr)
		return (NULL);
	while (++i < size)
		ptr[i] = s1[i];
	ptr[i] = 0;
	return (ptr);
}
