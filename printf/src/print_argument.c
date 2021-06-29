/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 15:40:39 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/06/29 17:54:49 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/ft_printf.h"

void	print_character(t_layout *lay)
{
	char	c;
	int		space;

	c = (char)va_arg(lay->info, int);
	space = lay->width - 1;
	if (lay->left_justif == 1)
	{
		lay->ret += write(1, &c, 1);
		print_width_character(space, lay);
	}
	else
	{
		print_width_character(space, lay);
		lay->ret += write(1, &c, 1);
	}
}

void	print_integer(t_layout *lay)
{
	int	i;
	int	space;

	i = (int)va_arg(lay->info, int);
	space = lay->width - ft_countnbr(i);
	if (lay->left_justif == 1)
	{
		if (lay->flag_prec > 0)
			print_precision_integer_justif(lay, space, i);
		else
		{
			ft_putnbr_printf(i, lay);
			print_width_integer(lay, space, i);
		}
	}
	else
	{
		if (lay->flag_prec > 0)
			print_precision_integer(lay, space, i);
		else
		{
			print_width_integer(lay, space, i);
			ft_putnbr_printf(i, lay);
		}
	}
}

void	print_hexa(t_layout *lay, char *base)
{
	int	i;
	int	space;

	i = (int)va_arg(lay->info, int);
	space = lay->width - ft_countnbr_base(i, base);
	if (lay->left_justif == 1)
	{
		if (lay->flag_prec > 0)
			print_precision_hexa_justif(lay, space, i, base);
		else
		{
			ft_putnbr_base_printf(i, base, lay);
			print_width_hexa(lay, space);
		}
	}
	else
	{
		if (lay->flag_prec > 0)
			print_precision_hexa(lay, space, i, base);
		else
		{
			print_width_hexa(lay, space);
			ft_putnbr_base_printf(i, base, lay);
		}
	}
}

void	print_unsigned_int(t_layout *lay)
{
	int	i;
	int	space;

	i = (int)va_arg(lay->info, int);
	space = lay->width - ft_countnbr_unsigned_int(i);
	if (lay->left_justif == 1)
	{
		if (lay->flag_prec > 0)
			print_precision_unsigned_justif(lay, space, i);
		else
		{
			ft_putnbr_unsigned_int_printf(i, lay);
			print_width_unsigned(lay, space);
		}
	}
	else
	{
		if (lay->flag_prec > 0)
			print_precision_unsigned(lay, space, i);
		else
		{
			print_width_unsigned(lay, space);
			ft_putnbr_unsigned_int_printf(i, lay);
		}
	}
}

void	print_argument(t_layout *lay)
{
	if (lay->conv == 'd' || lay->conv == 'i')
		print_integer(lay);
	if (lay->conv == '%')
		print_pourcent(lay);
	if (lay->conv == 'c')
		print_character(lay);
	if (lay->conv == 'x' )
		print_hexa(lay, "0123456789abcdef");
	if (lay->conv == 'X')
		print_hexa(lay, "0123456789ABCDEF");
	if (lay->conv == 'u')
		print_unsigned_int(lay);
	if (lay->conv == 's')
		print_string(lay);
	if (lay->conv == 'p')
		print_pointer(lay, "0123456789abcdef");
}
