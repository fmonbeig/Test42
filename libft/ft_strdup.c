/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 14:17:04 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/05/02 17:56:08 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_strlen.c"

char *ft_strdup(const char *s1)
{
    char *ptr;
    size_t i;
    size_t size;

    i = -1;
    size = ft_strlen(s1);
    if (!(ptr = malloc(size * sizeof(char) + 1)))
        return (NULL);
    while (++i < size)
        ptr[i] = s1[i];
    ptr[i] = 0;
    return (ptr);
}