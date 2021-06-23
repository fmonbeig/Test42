/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 15:40:39 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/06/23 14:55:31 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"



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