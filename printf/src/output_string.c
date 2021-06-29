/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 16:21:03 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/06/29 17:41:52 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/ft_printf.h"

void	print_width_string(t_layout *lay, int space)
{
	if (lay->zero == 1)
		print_zero(space, lay);
	else
		print_space(space, lay);
}

void	print_precision_string_justif(t_layout *lay, int space, char *str)
{
	if (lay->prec_neg == 1)
		lay->prec = ft_strlen_printf(str);
	space = calcul_space_string(lay, str);
	ft_putstr_limited_printf(str, lay->prec, lay);
	if (space > 0)
		print_width_string(lay, space);
}

void	print_precision_string(t_layout *lay, int space, char *str)
{
	if (lay->prec_neg == 1)
		lay->prec = ft_strlen_printf(str);
	space = calcul_space_string(lay, str);
	if (space > 0)
		print_width_string(lay, space);
	ft_putstr_limited_printf(str, lay->prec, lay);
}

int	calcul_space_string(t_layout *lay, char *str)
{
	int	len;

	len = ft_strlen_printf(str);
	if (lay->prec >= lay->width && lay->width > len)
		return (lay->width - len);
	else if (lay->prec < lay->width)
	{
		if (lay->prec >= len)
			return (lay->width - len);
		if (lay->prec < len)
			return (lay->width - lay->prec);
	}
	return (0);
}
