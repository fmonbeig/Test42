/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 23:11:03 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/05/05 20:10:18 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_strdup.c"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    int size;
    int i;
    char *ptr;
    
    i = 0;
    ptr = ft_strdup(s);
    while(ptr[i])
    {
     ptr[i] = f(i, ptr[i]);
    i++;
    }
return (ptr);
}
