/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_argument2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 16:45:03 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/06/29 17:54:18 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/ft_printf.h"

void	print_string(t_layout *lay)
{
	char	*str;
	int		space;

	str = (char *)va_arg(lay->info, char *);
	space = lay->width - ft_strlen_printf(str);
	if (lay->left_justif == 1)
	{
		if (lay->prec > 0 || lay->flag_prec == 1)
			print_precision_string_justif(lay, space, str);
		else
		{
			ft_putstr_printf(str, lay);
			print_width_string(lay, space);
		}
	}
	else
	{
		if (lay->prec > 0 || lay->flag_prec == 1)
			print_precision_string(lay, space, str);
		else
		{
			print_width_string(lay, space);
			ft_putstr_printf(str, lay);
		}
	}
}

void	print_pointer(t_layout *lay, char *base)
{
	unsigned long int	i;
	int					space;

	i = (unsigned long int)va_arg(lay->info, unsigned long int);
	space = lay->width - ft_countnbr_base_pointer(i, base);
	if (lay->left_justif == 1)
	{
		if (lay->prec > 0)
			print_precision_pointer_justif(lay, space, i, base);
		else
		{
			ft_putnbr_base_pointer_0x(i, base, lay);
			print_width_pointer(lay, space);
		}
	}
	else
	{
		if (lay->prec > 0)
			print_precision_pointer(lay, space, i, base);
		else
		{
			print_width_pointer(lay, space);
			ft_putnbr_base_pointer_0x_special(i, base, lay);
		}
	}
}

void	print_pourcent(t_layout *lay)
{
	char	c;
	int		space;

	c = '%';
	space = lay->width - 1;
	if (lay->left_justif == 1)
	{
		lay->ret += write(1, &c, 1);
		print_width_pourcent(space, lay);
	}
	else
	{
		print_width_pourcent(space, lay);
		lay->ret += write(1, &c, 1);
	}
}
