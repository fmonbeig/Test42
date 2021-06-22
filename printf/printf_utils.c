/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 22:12:41 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/06/22 14:23:26 by fmonbeig         ###   ########.fr       */
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

void parse_layout(const char *format, t_layout *lay, int pos)
{
    // faire avec le positionning et faire des fonctions par flag
    if (format[pos] == '-')
       pos = parsing_left_justify(format, lay, pos);
    if (format[pos] == '0')
            pos = parsing_zero(format, lay, pos);
    if (format[pos] == '*')
        {
        lay->width = (int)va_arg(lay->info, int);
        pos++;
        }
    if (ft_isdigit(*format) && *format)
        lay->width = atoi(format);
    if (format[pos] == '.')
    {
        lay->prec = 1;
        pos++;
    }
    if (format[pos] == '*')
    {
        lay->width = (int)va_arg(lay->info, int);
        pos++;
    }
	if (ft_isdigit(*format) && *format)
        lay->width = atoi(format);
    if (is_format(*format))
        lay->conv = *format;
}

int print_format(const char *format, t_layout *lay, int pos)
{
    int i;
    
    parse_layout(format, lay, pos);
   printf("\n conv = %c", lay->conv);
   printf("\n justif = %d", lay->left_justif);
   printf("\n zero = %d", lay->zero);
   printf("\n width = %d\n", lay->width);
    if(lay->conv == 'd')
    {
    i = (int)va_arg(lay->info, int);
       ft_putnbr(i);
       return(ft_countnbr(i));
    }   
	return 0;
}

