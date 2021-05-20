/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 11:03:15 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/05/02 17:55:38 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memset(void *s, int c, size_t len)
{
    unsigned char *dest;

    dest = s;
    while (len > 0)
    {
        *dest = (unsigned char)c;
        dest++;
        len--;
    }
    return (s);
}
