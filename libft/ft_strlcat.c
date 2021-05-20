/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 16:53:25 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/05/02 17:56:15 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_strnstr.c"

size_t ft_strlcat(char *dst, const char *src, size_t dstsize)
{

    size_t i;
    size_t l;
    int j;

    i = 0;
    j = 0;
    l = ft_strlen(dst);
    if (l + 1 > dstsize || dstsize == 0)
        return (ft_strlen(src) + dstsize);
    while (dst[i])
        i++;
    while (i < dstsize - 1 && src[j])
    {
        dst[i] = src[j];
        i++;
        j++;
    }
    if (dstsize == 0)
        dst[i] = '\0';
    return (l + ft_strlen(src));
}