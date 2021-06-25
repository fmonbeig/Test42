/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_argument2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 16:45:03 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/06/25 16:55:07 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/ft_printf.h"

int print_string(t_layout *lay)
{
    char *str;
    int space;
    
    str = (char *)va_arg(lay->info, char *);
    space = lay->width - ft_strlen(str);
    if (lay->left_justif == 1)
    {
        if (lay->prec > 0)
        print_precision_string_justif(lay, space, str);
        else 
        {
        ft_putstr(str);
        print_width_string(lay, space);
        }
    }
    else
    {
    if (lay->prec > 0)
        print_precision_string(lay, space, str);
        else
        {
    print_width_string(lay, space);
    ft_putstr(str);
        }
    }
    return (return_count_string(lay, str));
}

int print_pointer(t_layout *lay, char *base)
{
    unsigned long int i;
    int space;
    
    i = (unsigned long int)va_arg(lay->info, unsigned long int);
    space = lay->width - ft_countnbr_base_pointer(i,base);
    if (lay->left_justif == 1)
    {
        if (lay->prec > 0)
        print_precision_pointer_justif(lay, space, i, base);
        else
        {
        ft_putnbr_base_pointer_0x(i, base);
        print_width_pointer(lay, space);
        }
    }
    else
    {
    if (lay->prec > 0)
        print_precision_pointer(lay, space, i, base);
        else
        {
    print_width_pointer(lay, space);
    ft_putnbr_base_pointer_0x_special(i, base, lay);
        }
    }
    return (return_count_pointer(lay, i, base));
}