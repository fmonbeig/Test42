/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 14:13:41 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/06/23 17:54:33 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"
//#include "printf.c"
//#include "printf_utils.c"
//#include "libft.h"

int main ()
{
int ret;
int rot;

/*
ret = ft_printf("bonjour %d test", 50 );
printf("\n valeur de retour %d\n",ret);

ret = printf("bonjour %d test", 50 );
printf("\n valeur de retour %d\n",ret);
*/


/*
printf("\n==========CHARACTER TEST================\n\n");

ret = ft_printf("\nFT_PRINTF = bonjour %c Florian\n",'Z');
rot = printf("   PRINTF = bonjour %c Florian \n",'Z');
printf("valeur de retour %d\n",ret);
printf("valeur de retour %d\n",rot);

ret = ft_printf("\nFT_PRINTF = bonjour %5c Florian\n",'Z');
rot = printf("   PRINTF = bonjour %5c Florian \n",'Z');
printf("valeur de retour %d\n",ret);
printf("valeur de retour %d\n",rot);

ret = ft_printf("\nFT_PRINTF = bonjour %-24c Florian\n",'Z');
rot = printf("   PRINTF = bonjour %-24c Florian \n",'Z');
printf("valeur de retour %d\n",ret);
printf("valeur de retour %d\n",rot);

ret = ft_printf("\nFT_PRINTF = bonjour %-*c Florian\n",15,'Z');
rot = printf("   PRINTF = bonjour %-*c Florian \n",15,'Z');
printf("valeur de retour %d\n",ret);
printf("valeur de retour %d\n",rot);
*/
/*
printf("\n==========INTEGER TEST================\n\n");

ret = ft_printf("\nFT_PRINTF = bonjour %d Florian\n",50);
printf("valeur de retour %d\n",ret);
ret = printf("   PRINTF = bonjour %d Florian \n",50);
printf("valeur de retour %d\n",ret);

ret = ft_printf("\nFT_PRINTF = bonjour %5d Florian\n",50);
printf("valeur de retour %d\n",ret);
ret = printf("   PRINTF = bonjour %5d Florian \n",50);
printf("valeur de retour %d\n",ret);

ret = ft_printf("\nFT_PRINTF = bonjour %05d Florian\n",50);
printf("valeur de retour %d\n",ret);
ret = printf("   PRINTF = bonjour %05d Florian \n",50);
printf("valeur de retour %d\n",ret);

ret = ft_printf("\nFT_PRINTF = bonjour %010d Florian\n",-50);
printf("valeur de retour %d\n",ret);
ret = printf("   PRINTF = bonjour %010d Florian \n",-50);
printf("valeur de retour %d\n",ret);

ret = ft_printf("\nFT_PRINTF = bonjour %-5d Florian\n",50);
printf("valeur de retour %d\n",ret);
ret = printf("   PRINTF = bonjour %-5d Florian \n",50);
printf("valeur de retour %d\n",ret);

ret = ft_printf("\nFT_PRINTF = bonjour %-*.*d Florian\n",7,9,50);
printf("valeur de retour %d\n",ret);
ret = printf("   PRINTF = bonjour %-*.*d Florian \n",7,9,50);
printf("valeur de retour %d\n",ret);

ret = ft_printf("\nFT_PRINTF = bonjour %*d Florian\n",7,50);
printf("valeur de retour %d\n",ret);
ret = printf("   PRINTF = bonjour %*d Florian \n",7,50);
printf("valeur de retour %d\n",ret);

ret = ft_printf("\nFT_PRINTF = bonjour %10.5d Florian\n",-50);
printf("valeur de retour %d\n",ret);
ret = printf("   PRINTF = bonjour %10.5d Florian \n",-50);
printf("valeur de retour %d\n",ret);

ret = ft_printf("\nFT_PRINTF = bonjour %.8d Florian\n",50);
printf("valeur de retour %d\n",ret);
ret = printf("   PRINTF = bonjour %.8d Florian \n",50);
printf("valeur de retour %d\n",ret);

ret = ft_printf("\nFT_PRINTF = bonjour %.8d Florian\n",-50);
printf("valeur de retour %d\n",ret);
ret = printf("   PRINTF = bonjour %.8d Florian \n",-50);
printf("valeur de retour %d\n",ret);

ret = ft_printf("\nFT_PRINTF = bonjour %10.5d Florian\n",-5);
printf("valeur de retour %d\n",ret);
ret = printf("   PRINTF = bonjour %10.5d Florian \n",-5);
printf("valeur de retour %d\n",ret);

ret = ft_printf("\nFT_PRINTF = bonjour %-12.32d Florian\n",-5);
printf("valeur de retour %d\n",ret);
ret = printf("   PRINTF = bonjour %-12.32d Florian \n",-5);
printf("valeur de retour %d\n",ret);
*/
return (0);
}

// penser aux chiffres negatif avec la width et le zero  --> le zero se met toujours en premier