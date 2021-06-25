/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 15:17:03 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/06/25 16:54:59 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/ft_printf.h"


void print_width_unsigned(t_layout *lay, int space) 
{
    if (lay->zero == 1)
        print_zero(space);
    else
    print_space(space);
}

void print_precision_unsigned_justif(t_layout *lay, int space, int i)
{
    int len;

    lay->zero = 0;
    len = lay->prec - (ft_countnbr_unsigned_int(i));
    space = calcul_space_unsigned(lay, i);
    print_zero(len);
    ft_putnbr_unsigned_int(i);
    if(space > 0)
    print_width_unsigned(lay,space);
}

void print_precision_unsigned(t_layout *lay, int space, int i)
{
    int len;

    lay->zero = 0;
    len = lay->prec - (ft_countnbr_unsigned_int(i));
    space = calcul_space_unsigned(lay, i);
    if (space > 0)
    print_width_unsigned(lay, space);
    print_zero(len);
    ft_putnbr_unsigned_int(i);
}

int return_count_unsigned(t_layout *lay, int i)
{
    int len;

    len = ft_countnbr_unsigned_int(i);
    if (lay->prec == 0 && lay->width == 0)
    return (len);
    else if (lay->prec >= lay->width)
    {
        if (lay->prec > len)
            return (lay->prec);
        else
        return (len);
    }
    else if (lay->prec < lay->width)
    {
        if (lay->width > len)
        return(lay->width);
        else
        return (len);
    }
    return(0);
}

int calcul_space_unsigned(t_layout *lay, int i)
{
    int len;
    
    len = ft_countnbr_unsigned_int(i);
    if (lay->prec >= lay->width)
            return (0);
    else if (lay->prec < lay->width)
    {
        if (lay->width <= len)
        return(0);
        else if (lay->width >= len)
        {
        if (lay->prec >= len)
        return (lay->width - lay->prec);
        else
        return (lay->width - len);
        }
    }
    return(0);
}