/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 11:37:50 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/06/25 16:54:53 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/ft_printf.h"

void print_width_pointer(t_layout *lay, int space) 
{
    if (lay->zero == 1)
    {
        write(1,"0x",2);
        print_zero(space);
    }
    else
       print_space(space);
}

void print_precision_pointer_justif(t_layout *lay, int space, unsigned long int i, char *base)
{
    int len;

    lay->zero = 0;
    len = lay->prec - (ft_countnbr_base_pointer(i,base));
    space = calcul_space_pointer(lay, i, base);
    ft_putnbr_base_pointer_0x(i, base);
    if (space > 0)
    print_width_pointer(lay,space);
}

void print_precision_pointer(t_layout *lay, int space, unsigned long int i, char *base)
{
    int len;

    len = lay->prec - ft_countnbr_base_pointer(i,base) + 2;
    space = calcul_space_pointer(lay, i, base) - 2;
    lay->zero = 0;
    if (space > 0)
    print_width_pointer(lay, space);
    write(1,"0x",2);
    print_zero(len);
    ft_putnbr_base_pointer(i, base);
}

int return_count_pointer(t_layout *lay, unsigned long int i, char *base)
{
    int len;

    len = ft_countnbr_base_pointer(i, base);
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

int calcul_space_pointer(t_layout *lay, unsigned long int i, char *base)
{
    int len;
    
    len = ft_countnbr_base_pointer(i, base);
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