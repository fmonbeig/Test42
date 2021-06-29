/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 14:13:03 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/06/29 17:45:29 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/ft_printf.h"

int	parsing_left_justify(const char *format, t_layout *lay, int pos)
{
	while (format[pos] && format[pos] == '-')
		pos++;
	lay->left_justif = 1;
	if (lay->zero == 1)
		lay->zero = 0;
	return (pos);
}

int	parsing_zero(const char *format, t_layout *lay, int pos)
{
	while (format[pos] && format[pos] == '0')
		pos++;
	lay->zero = 1;
	if (lay->left_justif == 1)
		lay->zero = 0;
	return (pos);
}

int	parsing_width(const char *format, t_layout *lay, int pos)
{
	if (format[pos] == '*')
	{
		lay->width = (int)va_arg(lay->info, int);
		if (lay->width < 0)
		{
			lay->width *= -1;
			lay->left_justif = 1;
			lay->zero = 0;
		}
		pos++;
	}
	else if (ft_isdigit(format[pos]))
	{
		lay->width = atoi(&format[pos]);
		while (format[pos] && ft_isdigit(format[pos]))
			pos++;
	}
	if (format[pos] == '*' || ft_isdigit(format[pos]))
		pos = parsing_width (format, lay, pos);
	return (pos);
}

int	parsing_precision(const char *format, t_layout *lay, int pos)
{
	lay->flag_prec = 1;
	pos++;
	if (format[pos] == '*')
	{
		lay->prec = (int)va_arg(lay->info, int);
		if (lay->prec < 0)
		{
			lay->prec = 0;
			lay->prec_neg = 1;
		}
		pos++;
	}
	else if (ft_isdigit(format[pos]))
	{
		lay->prec = atoi(&format[pos]);
		while (format[pos] && ft_isdigit(format[pos]))
			pos++;
	}
	else
		lay->prec = 0;
	return (pos);
}

int	parse_layout(const char *format, t_layout *lay, int pos)
{
	while (format[pos] == '0' || format[pos] == '-')
	{
		if (format[pos] == '0')
			pos = parsing_zero(format, lay, pos);
		if (format[pos] == '-')
			pos = parsing_left_justify(format, lay, pos);
	}
	if (format[pos] == '*' || ft_isdigit(format[pos]))
		pos = parsing_width(format, lay, pos);
	if (format[pos] == '.')
		pos = parsing_precision(format, lay, pos);
	if (is_format(format[pos]))
		lay->conv = format[pos];
	return (pos + 1);
}
