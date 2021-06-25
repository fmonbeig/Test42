/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 22:12:41 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/06/25 16:55:10 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/ft_printf.h"

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

void	ft_putnbr_base_pointer_0x_special(unsigned long int nbr, char *base, t_layout *lay)
{
	unsigned long int    size_base;
	static int i;

	i = 1;
	if (i == 1 && lay->zero == 0)
	write(1,"0x",2);
	i++;
	size_base = ft_strlen(base);

		if (nbr >= size_base)
		{
			ft_putnbr_base_pointer(nbr / size_base, base);
			nbr %= size_base;
		}
		write (1,&base[i],1);
}