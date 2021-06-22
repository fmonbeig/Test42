/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 17:41:42 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/06/22 14:08:25 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"
//#include "libft.h"
//#include "printf_utils.c"

t_layout	*ft_init_layout(int width)
{
	t_layout    *lay;

	lay = malloc(sizeof(*lay));
	if (!lay)
		return (NULL);
	lay->width = width;
    lay->left_justif = 0;
    lay->zero = 0;
    lay->prec = 0;
    lay->conv = 0;
	return (lay);
}

int ft_printf(const char *format, ...)
{
t_layout *lay;
lay = ft_init_layout(0);
va_start (lay->info, format);
int pos;
int count;

pos = 0;
count = 0;
while (format[pos])
{
    while (format[pos] && format[pos] != '%')
   count += ft_put_and_countchar(format[pos++]); //possibilite de mettre juste un write pour economiser une fonction
    if (format[pos] == '%')
{ 
    count += print_format(format, lay, pos++ +1);
    while(!is_format(format[pos]) && format[pos])
    pos++;
    pos++;
}
}
va_end(lay->info);
free(lay);
return (count);
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
/*
Avec pos a -1
while (format[++pos])
{
    if (format[pos] == '%')
{ 
    count += print_format(format, lay, pos++ +1);
    while(!is_format(format[pos]) && format[pos])
    pos++;
}
    else if (format[pos] != '%')
   count += ft_put_and_countchar(format[pos]); //possibilite de mettre juste un write pour economiser une fonction
}
*/