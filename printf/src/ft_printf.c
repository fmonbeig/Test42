/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 17:41:42 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/06/29 16:42:11 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/ft_printf.h"

t_layout	*ft_init_layout(void)
{
	t_layout	*lay;

	lay = malloc(sizeof(*lay));
	if (!lay)
		return (NULL);
	lay->width = 0;
	lay->left_justif = 0;
	lay->zero = 0;
	lay->prec = 0;
	lay->flag_prec = 0;
	lay->prec_neg = 0;
	lay->conv = 0;
	lay->hex = 1;
	lay->ret = 0;
	return (lay);
}

void	ft_reset_layout(t_layout *lay)
{
	lay->width = 0;
	lay->left_justif = 0;
	lay->zero = 0;
	lay->prec = 0;
	lay->flag_prec = 0;
	lay->prec_neg = 0;
	lay->conv = 0;
	lay->hex = 1;
}

int	ft_printf(const char *format, ...)
{
	t_layout	*lay;
	int			pos;
	int			ret;

	lay = ft_init_layout();
	va_start (lay->info, format);
	pos = 0;
	while (format[pos])
	{
		while (format[pos] && format[pos] != '%')
			lay->ret += ft_put_and_countchar(format[pos++]);
		if (format[pos] == '%')
		{
			pos = parse_layout(format, lay, pos + 1);
			print_argument(lay);
			ft_reset_layout(lay);
		}
	}
	va_end(lay->info);
	ret = lay->ret;
	free(lay);
	return (ret);
}
