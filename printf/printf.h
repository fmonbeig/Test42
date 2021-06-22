/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 09:34:47 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/06/22 14:18:25 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>


typedef struct s_layout
{
    va_list info;
	int width;
    int left_justif;
    int zero;
    int prec;
    char conv;
}				t_layout;

int is_format(char c);
int ft_printf(const char *format, ...);
int	ft_put_and_countchar(char c);
void parse_layout(const char *format, t_layout *lay, int pos);
int print_format(const char *format, t_layout *lay, int pos);
int parsing_left_justify(const char *format, t_layout *lay, int pos);


#endif