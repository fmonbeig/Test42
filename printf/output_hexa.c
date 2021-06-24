/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 11:55:26 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/06/24 14:42:47 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

void print_width_hexa(t_layout *lay, int space) 
{
    if (lay->zero == 1)
        print_zero(space);
    else
    print_space(space);
}

void print_precision_hexa_justif(t_layout *lay, int space, int i, char *base)
{
    int len;

    lay->zero = 0;
    len = lay->prec - (ft_countnbr_base(i,base));
    space = calcul_space_hexa(lay, i, base);
    print_zero(len);
    ft_putnbr_base(i, base);
    if(space > 0)
    print_width_hexa(lay,space);
}

void print_precision_hexa(t_layout *lay, int space, int i, char *base)
{
    int len;

    len = lay->prec - (ft_countnbr_base(i,base));
    space = calcul_space_hexa(lay, i, base);
    if (space > 0)
    print_width_hexa(lay, space);
    print_zero(len);
    ft_putnbr_base(i, base);
}

int return_count_hexa(t_layout *lay, int i, char *base)
{
    int len;

    len = ft_countnbr_base(i, base);
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

int calcul_space_hexa(t_layout *lay, int i, char *base)
{
    int len;
    
    len = ft_countnbr_base(i, base);
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