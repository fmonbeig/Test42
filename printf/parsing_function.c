/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 14:13:03 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/06/22 14:25:26 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

int parsing_left_justify(const char *format, t_layout *lay, int pos)
{
    while(format[pos] && format[pos] == '-')
    pos++;
    lay->left_justif = 1;
    if (lay->zero == 1)
    lay->zero = 0;
    return (pos);
}

int parsing_zero(const char *format, t_layout *lay, int pos)
{
    while(format[pos] && format[pos] == '0')
    pos++;
    lay->zero = 1;
    if (lay->left_justif == 1)
    lay->zero = 0;
    return (pos);
}