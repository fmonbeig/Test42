/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 22:12:41 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/06/24 14:47:45 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

int	ft_put_and_countchar(char c)
{
	return(write(1, &c, 1));
}

void print_zero(int i)
{
    while (i > 0)
    {
       write(1, "0", 1);
       i--;     
    }
}

void print_space(int i)
{
    while (i > 0)
    {
       write(1, " ", 1);
       i--;     
    }
}

int is_format(char c)
{
    int i;
    char *format;
    format = "cspdiuxX%";
    
    i = 0;
    while(format[i])
    {
        if ( c == format[i])
        return (1);
        i++;
    }
    return(0);
}