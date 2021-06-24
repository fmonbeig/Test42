/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countnbr_unsigned_int.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 15:33:46 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/06/24 15:38:24 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countnbr_unsigned_int(unsigned int n)
{
	unsigned long int	num;
    int count;
    
    count = 0;
	num = n;
    	while(num > 0)
	{
		num /= 10;
		count++;
	}
    return(count);
}