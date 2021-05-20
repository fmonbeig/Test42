/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:03:30 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/05/03 17:20:38 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_strlen.c"

char *ft_strjoin(char const *s1, char const *s2)
{
    char *str;
    int i;

    i = 0;
    if (!s1 || !s2)
        return (NULL);
    if (!(str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
        return (NULL);
    while (*s1)
        str[i++] = *s1++;
    while (*s2)
        str[i++] = *s2++;
    str[i] = 0;
    return (str);
}