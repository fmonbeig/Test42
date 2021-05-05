/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 18:06:55 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/04/30 09:57:49 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_strlen.c"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    unsigned int i;
    char *ptr;

    i = 0;
    if (len > ft_strlen(s))
    {
        if (!(ptr = malloc(ft_strlen(s) * sizeof(char) + 1)))
            return (NULL);
    }
    else
    {
        if (!(ptr = malloc(len * sizeof(char) + 1)))
            return (NULL);
    }
    while (s[i + start] && i < len)
    {
        ptr[i] = s[i + start];
        i++;
    }
    ptr[i] = 0;
    return (ptr);
}