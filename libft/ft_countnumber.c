/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countnumber.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 15:51:34 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/06/03 17:17:07 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"
#include "ft_putnbr.c"
#include "ft_putchar.c"

int ft_countnbr(int n)
{
	long int	num;
    static int  count;
	
    if (!count)
    count = 1;
    num = n;
	if (num < 0)
	{
		num *= -1;
        count++;
	}
	if (num > 9)
	{
        count++;
		ft_countnbr(num / 10);
		num = num % 10;
        
	}
    return (count);
}
