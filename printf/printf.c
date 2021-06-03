/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 17:41:42 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/06/03 15:49:23 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int ft_printf(const char *format, ...)
{
va_list info;
va_start (info, format);
int count;
int i;

count = 0;
while (*format && *format != '%')
{
    putchar(format++);
    count++;
}

if (*format == '%')
{
    format++;
    if(format == 'd')
    {
       i = (int)va_arg(info, int);
       putnbr(i);
       count++;
    }
}


    
}

// Printf renvoie le nomnre de caractère à imprimer