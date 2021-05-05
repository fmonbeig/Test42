/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 14:12:31 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/05/02 17:54:38 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_bzero.c"

void *ft_calloc(size_t count, size_t size)
{
    void *ptr;

    if (!(ptr = malloc(count * size)))
        return (NULL);
    ft_bzero(ptr, count * size);
    return (ptr);
}