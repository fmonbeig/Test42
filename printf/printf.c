/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 17:41:42 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/06/13 19:31:48 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
//#include "libft.h"
//#include "printf_utils.c"

int ft_printf(const char *format, ...)
{
va_list info;
va_start (info, format);
int count;
int i;

count = 0;
while (*format)
{
    while (*format && *format != '\\' && *format != '%')
    {
    ft_putchar(*format);
    format++;
    count++;
    }
    if (*format == '\\')
    {
    format++;
    backslash_rule(*format);
    count++;
    continue;
    }
    if (*format == '%')
{
    format++;
    count += print_format(format, info);
    format++;
    continue;
    }
}
va_end(info);
return (count) ;
}

/*
// Printf renvoie le nombre de caractère à imprimer
// https://www.lix.polytechnique.fr/~liberti/public/computing/prog/c/C/FUNCTIONS/format.html
// les arguments doivent être dans l'ordre pour être invoqué
//1 - Rajouter la règle du backslash \
la width avec d apres un nombre == mais le nombre dans un tableau de x caractere et mais le chiffre a la fin de la chaine tout en remplissant la chaine vide de espace
// si le nombre est trop petit alors ca print quand meme
// - permet de faire commencer le tableau de nombre par la gauche
0 rempli les cases de zero  --> 0 ne fonctionne pas avec -   c est - qui l emporte
* est remplacé par le prochain int
8.4f = total width de 8 et derriere le . 4 decimals si decimal il y a( float) 

check le %
check si c est un element qui change la justif -0 et la taille 123456789 et le . et le *

*/