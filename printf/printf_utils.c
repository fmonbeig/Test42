/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 22:12:41 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/06/22 18:49:33 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

int	ft_put_and_countchar(char c)
{
	return(write(1, &c, 1));
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

void print_zero_space(t_layout *lay, int space, int i) // renommer la fonction car elle est speciale integer  et peut etre creer un doc output ou printing
{
    if (lay->zero == 1)
    {
        if(i < 0)
        {
            write(1, "-", 1);
            space--;
        }
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

int parse_layout(const char *format, t_layout *lay, int pos)
{
    if (format[pos] == '-')
       pos = parsing_left_justify(format, lay, pos);
    if (format[pos] == '0')
            pos = parsing_zero(format, lay, pos);
    if (format[pos] == '*' || ft_isdigit(format[pos]))
            pos = parsing_width(format,lay, pos);
    if (format[pos] == '.')
   pos = parsing_precision(format,lay, pos);
    if (is_format(format[pos]))
        lay->conv = format[pos];
    return(pos + 1);
}
