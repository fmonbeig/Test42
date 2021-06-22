/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 09:34:47 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/06/22 18:46:05 by fmonbeig         ###   ########.fr       */
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
int parse_layout(const char *format, t_layout *lay, int pos);
int parsing_left_justify(const char *format, t_layout *lay, int pos);
int parsing_zero(const char *format, t_layout *lay, int pos);
int parsing_width(const char *format, t_layout *lay, int pos);
int parsing_precision(const char *format, t_layout *lay, int pos);
int print_argument(t_layout *lay);
void    ft_reset_layout(t_layout *lay);
int print_integer(t_layout *lay);
int print_character(t_layout *lay);
void print_zero_space(t_layout *lay, int space, int i);

#endif