/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 23:08:06 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/05/05 12:24:52 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int size_int(long n)
{
    int i;

    i = 0;
    if (n == 0)
        i++;
    if (n < 0)
    {
        n *= -1;
        i++;
    }
    while (n)
    {
        n /= 10;
        i++;
    }
    return (i);
}

char *ft_itoa(int n)
{
    long num;
    char *ptr;
    int size;

    num = n;
    size = size_int(n);
    if (!(ptr = malloc(sizeof(char) * size + 1)))
        return (NULL);
    ptr[size--] = 0;
    if (num < 0)
    {
        ptr[0] = '-';
        num *= -1;
    }
    if (num == 0)
        ptr[0] = '0';
    while (num)
    {
        ptr[size--] = (num % 10) + '0';
        num /= 10;
    }
    return (ptr);
}