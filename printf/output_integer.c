/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_integer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 14:53:24 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/06/23 14:55:36 by fmonbeig         ###   ########.fr       */
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
         while (space > 0)
    {
        write(1, "0", 1);
        space--;
    }
    }
    else
    {
        while (space > 0)
    {
       write(1, " ", 1);
       space--;     
    }
    }
}

void print_precision_integer_justif(t_layout *lay, int space, int i) // gerer le count
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
    space = lay->width - lay->prec - minus;
    while (len > 0)
    {
        write(1, "0", 1);
        len--;
    }
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
    space = lay->width - lay->prec - minus;
    if(space > 0)
    print_width_integer(lay,space,i);
     if (minus > 0)
    write(1, "-", 1);  
    while (len > 0)
    {
        write(1, "0", 1);
        len--;
    }
    ft_putnbr_no_minus(i);
}

int return_count_integer(t_layout *lay, int i)
{
    int minus;
    
    minus = 0;
    if (i < 0)
    minus = 1;
    if (lay->prec == 0 && lay->width == 0)
    return(ft_countnbr(i));
    else if (lay->prec > lay->width || lay->prec == lay->width)
    {
        if (lay->prec > ft_countnbr(i))
        return(lay->prec + minus);
        else
        return (ft_countnbr(i));
    }
    else if (lay->prec < lay->width)
    {
        if (lay->width > ft_countnbr(i))
        return(lay->width);
        else
        return (ft_countnbr(i));
    }
    return(0);
}

int print_integer(t_layout *lay)
{
    int i;
    int space;
    
    i = (int)va_arg(lay->info, int);
    space = lay->width - ft_countnbr(i);
    if (lay->left_justif == 1)
    {
        if (lay->prec > 0)
        print_precision_integer_justif(lay,space,i);
        else 
        {
        ft_putnbr(i);
        print_width_integer(lay,space,i);
        }
    }
    else
    {
    if (lay->prec > 0)
        print_precision_integer(lay,space,i);
        else
        {
    print_width_integer(lay,space,i);
    ft_putnbr_no_minus(i);
        }
    }
    return(return_count_integer(lay,i));
}