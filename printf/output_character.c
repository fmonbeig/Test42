/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_character.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 17:25:04 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/06/23 17:51:21 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

void print_width_character(int space)
{
        while (space > 0)
    {
       write(1, " ", 1);
       space--;     
    }
}

int return_count_character(t_layout *lay)
{
    if(lay->width >= 1)
    return(lay->width);
    else
    return (1);
}