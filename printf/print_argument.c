/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 15:40:39 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/06/24 16:20:17 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"


int print_character(t_layout *lay)
{
    char c;
    int space;
    
    c = (char)va_arg(lay->info, int);
    space = lay->width - 1;
    if (lay->left_justif == 1)
    {
        write(1,&c,1);
        print_width_character(space);
    }
    else
    {
    print_width_character(space);
    write(1,&c,1);
    }
    return (return_count_character(lay));
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

int print_hexa(t_layout *lay, char *base)
{
    int i;
    int space;
    
    i = (int)va_arg(lay->info, int);
    space = lay->width - ft_countnbr_base(i, base);
    if (lay->left_justif == 1)
    {
        if (lay->prec > 0)
        print_precision_hexa_justif(lay, space, i, base);
        else 
        {
        ft_putnbr_base(i, base);
        print_width_hexa(lay, space);
        }
    }
    else
    {
    if (lay->prec > 0)
        print_precision_hexa(lay, space, i, base);
        else
        {
    print_width_hexa(lay, space);
    ft_putnbr_base(i, base);
        }
    }
    return (return_count_hexa(lay, i, base));
}

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

int print_argument(t_layout *lay)
{
    if (lay->conv == 'd' || lay->conv == 'i')
        return(print_integer(lay)); 
    if (lay->conv == '%')
    return(write(1,"%",1));
    if (lay->conv == 'c')
        return(print_character(lay));
    if (lay->conv == 'x' )
        return(print_hexa(lay, "0123456789abcdef")); 
    if (lay->conv == 'X')
    return(print_hexa(lay, "0123456789ABCDEF")); 
    if (lay->conv == 'u')
    return(print_unsigned_int(lay));
     if (lay->conv == 's')
    return(print_string(lay));
    return 0;
}