/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_argument2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 16:45:03 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/06/24 16:20:41 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

int print_unsigned_int(t_layout *lay)
{
    int i;
    int space;
    
    i = (int)va_arg(lay->info, int);
    space = lay->width - ft_countnbr_unsigned_int(i);
    if (lay->left_justif == 1)
    {
        if (lay->prec > 0)
        print_precision_unsigned_justif(lay, space, i);
        else 
        {
        ft_putnbr_unsigned_int(i);
        print_width_unsigned(lay, space);
        }
    }
    else
    {
    if (lay->prec > 0)
        print_precision_unsigned(lay, space, i);
        else
        {
    print_width_unsigned(lay, space);
    ft_putnbr_unsigned_int(i);
        }
    }
    return (return_count_unsigned(lay, i));
}