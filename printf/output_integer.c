/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_integer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 14:53:24 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/06/24 14:34:11 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

void print_width_integer(t_layout *lay, int space, int i) // creer un doc output ou width_printing + gerer le count
{
    if (lay->zero == 1)
    {
        if (i < 0)
            write(1, "-", 1);
        print_zero(space);
    }
    else
    print_space(space);
}

void print_precision_integer_justif(t_layout *lay, int space, int i)
{
    int minus;
    int len;

    minus = 0;
    lay->zero = 0;
    if (i < 0)
    {
    minus = 1;
    write(1, "-", 1);
    }
    len = lay->prec - (ft_countnbr(i) - minus);
    space = calcul_space_integer(lay, i, minus);
    print_zero(len);
    ft_putnbr_no_minus(i);
    if(space > 0)
    print_width_integer(lay,space,i);
}

void print_precision_integer(t_layout *lay, int space, int i)
{
    int minus;
    int len;

    minus = 0;
    lay->zero = 0;
    if (i < 0)
    minus = 1;
    len = lay->prec - (ft_countnbr(i) - minus);
    space = calcul_space_integer(lay, i, minus);
    if (space > 0)
    print_width_integer(lay,space,i);
     if (minus > 0)
    write(1, "-", 1);  
    print_zero(len);
    ft_putnbr_no_minus(i);
}

int return_count_integer(t_layout *lay, int i)
{
    int minus;
    int len;

    minus = 0;
    len = ft_countnbr(i);
    if (i < 0)
    minus = 1;
    if (lay->prec == 0 && lay->width == 0)
    return (len);
    else if (lay->prec >= lay->width)
    {
        if (lay->prec > len)
            return (lay->prec + minus);
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

int calcul_space_integer(t_layout *lay, int i, int minus)
{
    int len;

    len = ft_countnbr(i);
    if (lay->prec + minus >= lay->width)
            return (0);
    else if (lay->prec + minus < lay->width)
    {
        if (lay->width <= len)
        return(0);
        else if (lay->width >= len)
        {
        if (lay->prec + minus >= len)
        return (lay->width - lay->prec - minus);
        else
        return (lay->width - len);
        }
    }
    return(0);
}
