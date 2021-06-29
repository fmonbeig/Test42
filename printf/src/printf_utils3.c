/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 10:55:55 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/06/29 18:01:32 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/ft_printf.h"

void	ft_putnbr_printf(int n, t_layout *lay)
{
	long int	num;

	num = n;
	if (num == 0 && lay->flag_prec == 1 && lay->prec == 0 && lay->prec_neg == 0)
		return ;
	if (num < 0 && lay->zero == 0 && lay->flag_prec == 0)
		lay->ret += write(1, "-", 1);
	if (num < 0)
		num *= -1;
	if (num > 9)
	{
		ft_putnbr_printf(num / 10, lay);
		num = num % 10;
	}
	lay->ret += ft_put_and_countchar(num + '0');
}

void	ft_putnbr_unsigned_int_printf(unsigned int n, t_layout *lay)
{
	unsigned long int	num;

	num = n;
	if (num == 0 && lay->flag_prec == 1 && lay->prec == 0 && lay->prec_neg == 0)
	{
		return ;
	}
	if (num > 9)
	{
		ft_putnbr_unsigned_int_printf(num / 10, lay);
		num = num % 10;
	}
	lay->ret += ft_put_and_countchar(num + '0');
}

void	ft_putnbr_base_printf(unsigned int nbr, char *base, t_layout *lay)
{
	unsigned int	i;
	unsigned int	size_base;

	size_base = ft_strlen(base);
	i = nbr;
	if (i == 0 && lay->flag_prec == 1 && lay->prec == 0 && lay->prec_neg == 0)
	{
		return ;
	}
	while (i >= size_base)
	{
		ft_putnbr_base_printf(i / size_base, base, lay);
		i %= size_base;
	}
	lay->ret += write(1, &base[i], 1);
}
