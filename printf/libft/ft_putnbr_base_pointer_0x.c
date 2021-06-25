/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_pointer_0x.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 14:48:51 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/06/25 14:52:21 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base_pointer_0x(unsigned long int nbr, char *base)
{
	unsigned long int    size_base;
	static int i;

	i = 1;
	if (i == 1)
	write(1,"0x",2);
	i++;
	size_base = ft_strlen(base);

		if (nbr >= size_base)
		{
			ft_putnbr_base_pointer(nbr / size_base, base);
			nbr %= size_base;
		}
		write (1,&base[i],1);
}