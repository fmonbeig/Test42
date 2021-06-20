/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 22:12:41 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/06/15 13:16:41 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
//#include "libft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	long int	num;

	num = n;
	if (num < 0)
	{
		write(1, "-", 1);
		num *= -1;
	}
	if (num > 9)
	{
		ft_putnbr(num / 10);
		num = num % 10;
	}
	ft_putchar(num + '0');
}

void backslash_rule(char c)
{
    if ( c == '\\')
    ft_putchar('\\');
    
    if ( c == '"')
    ft_putchar('"');
    
    if ( c == '\'')
    ft_putchar('\'');
    
    if ( c == '%')
    ft_putchar('%');
    
    if ( c == '\a')
    ft_putchar('a');
    
    if ( c == 'b')
    ft_putchar('\b');
    
    if ( c == 'f')
    ft_putchar('\f');
    
    if ( c == 'n')
    ft_putchar('\n');
    
    if ( c == 'r')
    ft_putchar('\r');
    
    if ( c == 't')
    ft_putchar('\t');
    
    if ( c == 'v')
    ft_putchar('\v');
}

int ft_countnbr(int n)
{
	long int	num;
    static int  count;
	
    if (!count)
    count = 1;
    num = n;
	if (num < 0)
	{
		num *= -1;
        count++;
	}
	if (num > 9)
	{
        count++;
		ft_countnbr(num / 10);
		num = num % 10; 
	}
    return (count);
}
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}


int	ft_atoi(const char *str)
{
	unsigned long long int	num;
	int						neg;

	num = 0;
	neg = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		num = num * 10 + *str++ - '0';
	if (num > 9223372036854775807 && neg == -1)
		return (0);
	if (num > 9223372036854775807 && neg == 1)
		return (-1);
	return (num * neg);
}


char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	i;
	size_t	size;

	i = -1;
	size = ft_strlen(s1);
	ptr = malloc(sizeof(char) * (size + 1));
	if (!ptr)
		return (NULL);
	while (++i < size)
		ptr[i] = s1[i];
	ptr[i] = 0;
	return (ptr);
}

int print_format(const char *format, va_list info)
{
    int i;
    if(*format == 'd')
    {
    i = (int)va_arg(info, int);
       ft_putnbr(i);
       return(ft_countnbr(i));
    }   
	return 0;
}

int layout(const char *format, va_list info)
{
	int i;
	if(ft_isdigit(*format) || *format == '-' || *format == '*')
	{
		i = ft_atoi(format);
		while(i--)
		{
			ft_putchar(' ');
		}
	}
	
}
