/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 16:21:03 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/06/25 16:54:56 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/ft_printf.h"


void print_width_string(t_layout *lay, int space) 
{
    if (lay->zero == 1)
        print_zero(space);
    else
    print_space(space);
}

void print_precision_string_justif(t_layout *lay, int space, char *str)
{
    space = calcul_space_string(lay, str);
    ft_putstr_limited(str, lay->prec);
    if(space > 0)
    print_width_string(lay,space);
}

void print_precision_string(t_layout *lay, int space, char *str)
{
    space = calcul_space_string(lay, str);
    if (space > 0)
    print_width_string(lay, space);
    ft_putstr_limited(str, lay->prec);
}

int return_count_string(t_layout *lay, char *str)
{
    int len;

    len = ft_strlen(str);
    if (lay->prec == 0 && lay->width == 0)
    return (len);
    else if (lay->prec >= lay->width)
    {
        if (lay->prec > len)
            return (len);
        else if (lay->prec <= len)
        return (lay->prec);
    }
    else if (lay->prec < lay->width)
    {
    if (lay->width <= len)
    return(len);
    else
    return(lay->width);
    }
    return(0);
}

int calcul_space_string(t_layout *lay, char *str)
{
    int len;
    
    len = ft_strlen(str);
    if (lay->prec >= lay->width)
            return (0);
    else if (lay->prec < lay->width)
        return (lay->width - lay->prec);
    return(0);
}