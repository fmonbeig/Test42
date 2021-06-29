/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_character_and_pourcent.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 17:25:04 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/06/29 17:25:42 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/ft_printf.h"

void	print_width_character(int space, t_layout *lay)
{
	if (lay->zero == 1)
		print_zero(space, lay);
	else
		print_space(space, lay);
}

void	print_width_pourcent(int space, t_layout *lay)
{
	if (lay->zero == 1)
		print_zero(space, lay);
	else
		print_space(space, lay);
}
