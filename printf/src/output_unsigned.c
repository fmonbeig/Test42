/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 15:17:03 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/06/29 17:44:10 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/ft_printf.h"

void	print_width_unsigned(t_layout *lay, int space)
{
	if (lay->zero == 1)
		print_zero(space, lay);
	else
		print_space(space, lay);
}

void	print_precision_unsigned_justif(t_layout *lay, int space, int i)
{
	int	len;

	lay->zero = 0;
	len = lay->prec - (ft_countnbr_unsigned_int(i));
	space = calcul_space_unsigned(lay, i);
	print_zero(len, lay);
	ft_putnbr_unsigned_int_printf(i, lay);
	if (space > 0)
		print_width_unsigned(lay, space);
}

void	print_precision_unsigned(t_layout *lay, int space, int i)
{
	int	len;

	if (lay->prec_neg == 0)
		lay->zero = 0;
	len = lay->prec - (ft_countnbr_unsigned_int(i));
	space = calcul_space_unsigned(lay, i);
	if (space > 0)
		print_width_unsigned(lay, space);
	print_zero(len, lay);
	ft_putnbr_unsigned_int_printf(i, lay);
}

int	calcul_space_unsigned(t_layout *lay, int i)
{
	int	len;

	len = ft_countnbr_unsigned_int(i);
	if (i == 0 && lay->flag_prec == 1 && lay->prec == 0 && lay->prec_neg == 0)
		len = 0;
	if (lay->prec >= lay->width)
		return (0);
	else if (lay->prec < lay->width)
	{
		if (lay->width <= len)
			return (0);
		else if (lay->width >= len)
		{
			if (lay->prec >= len)
				return (lay->width - lay->prec);
			else
				return (lay->width - len);
		}
	}
	return (0);
}
