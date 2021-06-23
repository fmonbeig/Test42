/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 15:40:39 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/06/23 17:51:36 by fmonbeig         ###   ########.fr       */
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

int print_argument(t_layout *lay)
{
    if (lay->conv == 'd' || lay->conv == 'i')
        return(print_integer(lay)); 
    if (lay->conv == '%')
    return(write(1,"%",1));
    if (lay->conv == 'c')
        return(print_character(lay)); 
    return 0;
}