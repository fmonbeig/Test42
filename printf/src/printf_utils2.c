/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 12:24:35 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/06/29 18:00:26 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/ft_printf.h"

void	ft_putnbr_base_pointer_0x(unsigned long int nbr,
		char *base, t_layout *lay)
{
	unsigned long int	size_base;

	if (lay->hex == 1 && lay->zero == 0)
	{
		lay->ret += write(1, "0x", 2);
		lay->hex = 0;
	}
	size_base = ft_strlen(base);
	if (nbr >= size_base)
	{
		ft_putnbr_base_pointer_0x(nbr / size_base, base, lay);
		nbr %= size_base;
	}
	lay->ret += write (1, &base[nbr], 1);
}

void	ft_putstr_printf(char *s, t_layout *lay)
{
	char	*null;

	null = "(null)";
	if (s == NULL)
	{
		while (*null)
			lay->ret += write(1, null++, 1);
		return ;
	}
	while (*s)
		lay->ret += write(1, s++, 1);
}

void	ft_putstr_limited_printf(char *s, int i, t_layout *lay)
{
	char	*null;

	null = "(null)";
	if (s == NULL)
	{
		while (*null && i > 0)
		{
			lay->ret += write(1, null++, 1);
			i--;
		}
		return ;
	}
	else
	{
		while (*s && i > 0)
		{
			lay->ret += write(1, s++, 1);
			i--;
		}
	}
}

size_t	ft_strlen_printf(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (6);
	while (s[i])
		i++;
	return (i);
}
