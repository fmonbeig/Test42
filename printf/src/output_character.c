/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_character.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 17:25:04 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/06/25 16:56:32 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/ft_printf.h"

void print_width_character(int space, t_layout *lay)
{
    if (lay->zero == 1)
        print_zero(space);
    else
       print_space(space);
}

int return_count_character(t_layout *lay)
{
    if(lay->width >= 1)
    return(lay->width);
    else
    return (1);
}