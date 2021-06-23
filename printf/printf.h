/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 09:34:47 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/06/23 17:51:48 by fmonbeig         ###   ########.fr       */
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

int ft_printf(const char *format, ...);
t_layout	*ft_init_layout();
void    ft_reset_layout(t_layout *lay);
int is_format(char c);
int	ft_put_and_countchar(char c);

int parse_layout(const char *format, t_layout *lay, int pos);
int parsing_left_justify(const char *format, t_layout *lay, int pos);
int parsing_zero(const char *format, t_layout *lay, int pos);
int parsing_width(const char *format, t_layout *lay, int pos);
int parsing_precision(const char *format, t_layout *lay, int pos);
int print_argument(t_layout *lay);

int print_integer(t_layout *lay);
void print_width_integer(t_layout *lay, int space, int i);
void print_precision_integer(t_layout *lay, int space, int i);
void print_precision_integer_justif(t_layout *lay, int space, int i);
int return_count_integer(t_layout *lay, int i);
int calcul_space_integer(t_layout *lay, int i, int minus);

int print_character(t_layout *lay);
void print_width_character(int space);
int return_count_character(t_layout *lay);

#endif