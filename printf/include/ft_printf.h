/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 09:34:47 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/06/25 16:54:07 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

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

int print_hexa(t_layout *lay, char *base);
void print_width_hexa(t_layout *lay, int space);
void print_precision_hexa_justif(t_layout *lay, int space, int i, char *base);
void print_precision_hexa(t_layout *lay, int space, int i, char *base);
int return_count_hexa(t_layout *lay, int i, char *base);
int calcul_space_hexa(t_layout *lay, int i, char *base);

int print_unsigned_int(t_layout *lay);
void print_width_unsigned(t_layout *lay, int space);
void print_precision_unsigned_justif(t_layout *lay, int space, int i);
void print_precision_unsigned(t_layout *lay, int space, int i);
int return_count_unsigned(t_layout *lay, int i);
int calcul_space_unsigned(t_layout *lay, int i);

int print_string(t_layout *lay);
void print_width_string(t_layout *lay, int space);
void print_precision_string_justif(t_layout *lay, int space, char *str);
void print_precision_string(t_layout *lay, int space, char *str);
int return_count_string(t_layout *lay, char *str);
int calcul_space_string (t_layout *lay, char *str);

int print_pointer(t_layout *lay, char *base);
void print_width_pointer(t_layout *lay, int space);
void print_precision_pointer_justif(t_layout *lay, int space, unsigned long int i, char *base);
void print_precision_pointer(t_layout *lay, int space, unsigned long int i, char *base);
int return_count_pointer(t_layout *lay, unsigned long int i, char *base);
int calcul_space_pointer(t_layout *lay, unsigned long int i, char *base);

int print_character(t_layout *lay);
void print_width_character(int space, t_layout *lay);
int return_count_character(t_layout *lay);

void print_zero(int i);
void print_space(int i);
void	ft_putnbr_base_pointer_0x_special(unsigned long int nbr, char *base, t_layout *lay);

#endif