/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countnumber.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 15:51:34 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/06/23 09:56:25 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_countnbr(int n)
{
	long int	num;
    int  count;
	
    count = 0;
    num = n;
	if (num < 0)
	{
		num *= -1;
        count++;
	}
	while(num > 0)
	{
		num /= 10;
		count++;
	}
    return (count);
}
