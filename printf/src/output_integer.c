/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_integer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 14:53:24 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/06/29 17:36:46 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/ft_printf.h"

void	print_width_integer(t_layout *lay, int space, int i)
{
	if (lay->zero == 1)
	{
		if (i < 0)
			lay->ret += write(1, "-", 1);
		print_zero(space, lay);
	}
	else
		print_space(space, lay);
}

void	print_precision_integer_justif(t_layout *lay, int space, int i)
{
	int	minus;
	int	len;

	minus = 0;
	lay->zero = 0;
	if (i < 0)
	{
		minus = 1;
		lay->ret += write(1, "-", 1);
	}
	len = lay->prec - (ft_countnbr(i) - minus);
	space = calcul_space_integer(lay, i, minus);
	print_zero(len, lay);
	ft_putnbr_printf(i, lay);
	if (space > 0)
		print_width_integer(lay, space, i);
}

void	print_precision_integer(t_layout *lay, int space, int i)
{
	int	minus;
	int	len;

	minus = 0;
	if (lay->prec_neg == 0)
		lay->zero = 0;
	if (lay->prec <= ft_countnbr(i) && lay->width <= ft_countnbr(i))
		lay->zero = 0;
	if (i < 0)
		minus = 1;
	len = lay->prec - (ft_countnbr(i) - minus);
	space = calcul_space_integer(lay, i, minus);
	if (space > 0)
		print_width_integer(lay, space, i);
	if (minus > 0 && lay->zero == 0)
		lay->ret += write(1, "-", 1);
	print_zero(len, lay);
	ft_putnbr_printf(i, lay);
}

int	calcul_space_integer(t_layout *lay, int i, int minus)
{
	int	len;

	len = ft_countnbr(i);
	if (i == 0 && lay->flag_prec == 1 && lay->prec == 0 && lay->prec_neg == 0)
		len = 0;
	if (lay->prec + minus >= lay->width)
		return (0);
	else if (lay->prec + minus < lay->width)
	{
		if (lay->width <= len)
			return (0);
		else if (lay->width >= len)
		{
			if (lay->prec + minus >= len)
				return (lay->width - lay->prec - minus);
			else
				return (lay->width - len);
		}
	}
	return (0);
}
