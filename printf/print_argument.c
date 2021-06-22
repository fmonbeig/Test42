/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 15:40:39 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/06/22 18:48:29 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

int print_integer(t_layout *lay)
{
    int i;
    int space;
    i = (int)va_arg(lay->info, int);
    
    space = lay->width - ft_countnbr(i);
    if (lay->left_justif == 1)
    {
        ft_putnbr(i);
        print_zero_space(lay,space,i);
    }
    else
    {
    print_zero_space(lay,space,i);
    ft_putnbr(i); // fabriquer un nouveau putnbr pour afficher sans le -  (ft_putnbr_no_minus)
    }

    
    return(ft_countnbr(i) + space);
}
/*
	lay->width = 0;
    lay->left_justif = 0;
    lay->zero = 0;
    lay->prec = 0;
*/


int print_character(t_layout *lay)
{
    char c;
    c = (char)va_arg(lay->info, int);
    return (write(1,&c,1));
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