/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 14:13:41 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/06/25 18:00:22 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"
#include "include/ft_printf.h"


int main ()
{
int ret;
int rot;


printf("\n==========POINTER TEST================\n\n");

int a;

ret = ft_printf("\nFT_PRINTF = j ai un gros pointeur %p ohoh\n", &a);
rot = printf("   PRINTF = j ai un gros pointeur %p ohoh \n", &a);
printf("valeur de retour %d\n",ret);
printf("valeur de retour %d\n",rot);

ret = ft_printf("\nFT_PRINTF = j ai un gros pointeur %p ohoh\n", &a);
rot = printf("   PRINTF = j ai un gros pointeur %p ohoh \n", &a);
printf("valeur de retour %d\n",ret);
printf("valeur de retour %d\n",rot);

ret = ft_printf("\nFT_PRINTF = j ai un gros pointeur %50p ohoh\n", &a);
rot = printf("   PRINTF = j ai un gros pointeur %50p ohoh \n", &a);
printf("valeur de retour %d\n",ret);
printf("valeur de retour %d\n",rot);

ret = ft_printf("\nFT_PRINTF = j ai un gros pointeur %-050p ohoh\n", &a);
rot = printf("   PRINTF = j ai un gros pointeur %-050p ohoh \n", &a);
printf("valeur de retour %d\n",ret);
printf("valeur de retour %d\n",rot);

ret = ft_printf("\nFT_PRINTF = j ai un gros pointeur %-50p ohoh\n", &a);
rot = printf("   PRINTF = j ai un gros pointeur %-50p ohoh \n", &a);
printf("valeur de retour %d\n",ret);
printf("valeur de retour %d\n",rot);

ret = ft_printf("\nFT_PRINTF = j ai un gros pointeur %-050.10p ohoh\n", &a);
rot = printf("   PRINTF = j ai un gros pointeur %-050.10p ohoh \n", &a);
printf("valeur de retour %d\n",ret);
printf("valeur de retour %d\n",rot);


ret = ft_printf("\nFT_PRINTF = j ai un gros pointeur %050p ohoh\n", &a);
rot = printf("   PRINTF = j ai un gros pointeur %050p ohoh \n", &a);
printf("valeur de retour %d\n",ret);
printf("valeur de retour %d\n",rot);

ret = ft_printf("\nFT_PRINTF = j ai un gros pointeur %050.25p ohoh\n", &a);
rot = printf("   PRINTF = j ai un gros pointeur %050.25p ohoh \n", &a);
printf("valeur de retour %d\n",ret);
printf("valeur de retour %d\n",rot);

ret = ft_printf("\nFT_PRINTF = j ai un gros pointeur %50.25p ohoh\n", &a);
rot = printf("   PRINTF = j ai un gros pointeur %50.25p ohoh \n", &a);
printf("valeur de retour %d\n",ret);
printf("valeur de retour %d\n",rot);

ret = ft_printf("\nFT_PRINTF = j ai un gros pointeur %25.50p ohoh\n", &a);
rot = printf("   PRINTF = j ai un gros pointeur %25.50p ohoh \n", &a);
printf("valeur de retour %d\n",ret);
printf("valeur de retour %d\n",rot);

ret = ft_printf("\nFT_PRINTF = j ai un gros pointeur %025.50p ohoh\n", &a);
rot = printf("   PRINTF = j ai un gros pointeur %025.50p ohoh \n", &a);
printf("valeur de retour %d\n",ret);
printf("valeur de retour %d\n",rot);


/*
printf("\n==========STRING TEST================\n\n");

ret = ft_printf("\nFT_PRINTF = bonjour %015s Florian\n","je m'appelle");
rot = printf("   PRINTF = bonjour %015s Florian \n","je m'appelle");
printf("valeur de retour %d\n",ret);
printf("valeur de retour %d\n",rot);

ret = ft_printf("\nFT_PRINTF = bonjour %30s Florian\n","je m'appelle");
rot = printf("   PRINTF = bonjour %30s Florian \n","je m'appelle");
printf("valeur de retour %d\n",ret);
printf("valeur de retour %d\n",rot);

ret = ft_printf("\nFT_PRINTF = bonjour %5s Florian\n","je m'appelle");
rot = printf("   PRINTF = bonjour %5s Florian \n","je m'appelle");
printf("valeur de retour %d\n",ret);
printf("valeur de retour %d\n",rot);

ret = ft_printf("\nFT_PRINTF = bonjour %-2s Florian\n","je m'appelle");
rot = printf("   PRINTF = bonjour %-2s Florian \n","je m'appelle");
printf("valeur de retour %d\n",ret);
printf("valeur de retour %d\n",rot);

ret = ft_printf("\nFT_PRINTF = bonjour %-02s Florian\n","je m'appelle");
rot = printf("   PRINTF = bonjour %-02s Florian \n","je m'appelle");
printf("valeur de retour %d\n",ret);
printf("valeur de retour %d\n",rot);

ret = ft_printf("\nFT_PRINTF = bonjour %-5.6s Florian\n","je m'appelle");
rot = printf("   PRINTF = bonjour %-5.6s Florian \n","je m'appelle");
printf("valeur de retour %d\n",ret);
printf("valeur de retour %d\n",rot);

ret = ft_printf("\nFT_PRINTF = bonjour %-.2s Florian\n","je m'appelle");
rot = printf("   PRINTF = bonjour %-.2s Florian \n","je m'appelle");
printf("valeur de retour %d\n",ret);
printf("valeur de retour %d\n",rot);
*/

/*
printf("\n==========UNSIGNED TEST================\n\n");

ret = ft_printf("\nFT_PRINTF = bonjour %u Florian\n",50);
rot = printf("   PRINTF = bonjour %u Florian \n",50);
printf("valeur de retour %d\n",ret);
printf("valeur de retour %d\n",rot);

ret = ft_printf("\nFT_PRINTF = bonjour %5u Florian\n",50);
rot = printf("   PRINTF = bonjour %5u Florian \n",50);
printf("valeur de retour %d\n",ret);
printf("valeur de retour %d\n",rot);

ret = ft_printf("\nFT_PRINTF = bonjour %05u Florian\n",50);
rot = printf("   PRINTF = bonjour %05u Florian \n",50);
printf("valeur de retour %d\n",ret);
printf("valeur de retour %d\n",rot);

ret = ft_printf("\nFT_PRINTF = bonjour %-010u Florian\n",-50);
rot = printf("   PRINTF = bonjour %-010u Florian \n",-50);
printf("valeur de retour %d\n",ret);
printf("valeur de retour %d\n",rot);

ret = ft_printf("\nFT_PRINTF = bonjour %-5u Florian\n",50);
rot = printf("   PRINTF = bonjour %-5u Florian \n",50);
printf("valeur de retour %d\n",ret);
printf("valeur de retour %d\n",rot);

ret = ft_printf("\nFT_PRINTF = bonjour %-*.*u Florian\n",7,9,50);
rot = printf("   PRINTF = bonjour %-*.*u Florian \n",7,9,50);
printf("valeur de retour %d\n",ret);
printf("valeur de retour %d\n",rot);

ret = ft_printf("\nFT_PRINTF = bonjour %*u Florian\n",-7,50);
rot = printf("   PRINTF = bonjour %*u Florian \n",-7,50);
printf("valeur de retour %d\n",ret);
printf("valeur de retour %d\n",rot);

ret = ft_printf("\nFT_PRINTF = bonjour %.8u Florian\n",50);
rot = printf("   PRINTF = bonjour %.8u Florian \n",50);
printf("valeur de retour %d\n",ret);
printf("valeur de retour %d\n",rot);

ret = ft_printf("\nFT_PRINTF = bonjour %.8u Florian\n",-50);
rot = printf("   PRINTF = bonjour %.8u Florian \n",-50);
printf("valeur de retour %d\n",ret);
printf("valeur de retour %d\n",rot);

ret = ft_printf("\nFT_PRINTF = bonjour %10.5u Florian\n",-5);
rot = printf("   PRINTF = bonjour %10.5u Florian \n",-5);
printf("valeur de retour %d\n",ret);
printf("valeur de retour %d\n",rot);

ret = ft_printf("\nFT_PRINTF = bonjour %-12.32u Florian\n",-89);
rot = printf("   PRINTF = bonjour %-12.32u Florian \n",-89);
printf("valeur de retour %d\n",ret);
printf("valeur de retour %d\n",rot);

ret = ft_printf("\nFT_PRINTF = bonjour %010.20u Florian\n",-50);
rot = printf("   PRINTF = bonjour %010.20u Florian \n",-50);
printf("valeur de retour %d\n",ret);
printf("valeur de retour %d\n",rot);

ret = ft_printf("\nFT_PRINTF = bonjour %037.8u Florian\n",-89);
rot = printf("   PRINTF = bonjour %037.8u Florian \n",-89);
printf("valeur de retour %d\n",ret);
printf("valeur de retour %d\n",rot);
*/
/*
printf("\n==========HEXA TEST================\n\n");

ret = ft_printf("\nFT_PRINTF = bonjour %x Florian\n",50);
rot = printf("   PRINTF = bonjour %x Florian \n",50);
printf("valeur de retour %d\n",ret);
printf("valeur de retour %d\n",rot);

ret = ft_printf("\nFT_PRINTF = bonjour %5x Florian\n",50);
rot = printf("   PRINTF = bonjour %5x Florian \n",50);
printf("valeur de retour %d\n",ret);
printf("valeur de retour %d\n",rot);

ret = ft_printf("\nFT_PRINTF = bonjour %05x Florian\n",50);
rot = printf("   PRINTF = bonjour %05x Florian \n",50);
printf("valeur de retour %d\n",ret);
printf("valeur de retour %d\n",rot);

ret = ft_printf("\nFT_PRINTF = bonjour %010X Florian\n",-50);
rot = printf("   PRINTF = bonjour %010X Florian \n",-50);
printf("valeur de retour %d\n",ret);
printf("valeur de retour %d\n",rot);

ret = ft_printf("\nFT_PRINTF = bonjour %-5x Florian\n",50);
rot = printf("   PRINTF = bonjour %-5x Florian \n",50);
printf("valeur de retour %d\n",ret);
printf("valeur de retour %d\n",rot);

ret = ft_printf("\nFT_PRINTF = bonjour %-*.*x Florian\n",7,9,50);
rot = printf("   PRINTF = bonjour %-*.*x Florian \n",7,9,50);
printf("valeur de retour %d\n",ret);
printf("valeur de retour %d\n",rot);

ret = ft_printf("\nFT_PRINTF = bonjour %*X Florian\n",7,50);
rot = printf("   PRINTF = bonjour %*X Florian \n",7,50);
printf("valeur de retour %d\n",ret);
printf("valeur de retour %d\n",rot);

ret = ft_printf("\nFT_PRINTF = bonjour %10.5X Florian\n",-50);
rot = printf("   PRINTF = bonjour %10.5X Florian \n",-50);
printf("valeur de retour %d\n",ret);
printf("valeur de retour %d\n",rot);

ret = ft_printf("\nFT_PRINTF = bonjour %.8x Florian\n",50);
rot = printf("   PRINTF = bonjour %.8x Florian \n",50);
printf("valeur de retour %d\n",ret);
printf("valeur de retour %d\n",rot);

ret = ft_printf("\nFT_PRINTF = bonjour %-0.8x Florian\n",-50);
rot = printf("   PRINTF = bonjour %-0.8x Florian \n",-50);
printf("valeur de retour %d\n",ret);
printf("valeur de retour %d\n",rot);

ret = ft_printf("\nFT_PRINTF = bonjour %10.5X Florian\n",-5);
rot = printf("   PRINTF = bonjour %10.5X Florian \n",-5);
printf("valeur de retour %d\n",ret);
printf("valeur de retour %d\n",rot);

ret = ft_printf("\nFT_PRINTF = bonjour %-12.32X Florian\n",-5);
rot = printf("   PRINTF = bonjour %-12.32X Florian \n",-5);
printf("valeur de retour %d\n",ret);
printf("valeur de retour %d\n",rot);
*/
/*
printf("\n==========MULTIPLE TEST================\n\n");

int b;

ret = ft_printf("\nFT_PRINTF = bonjour %-12.32X %5d %9c Florian\n",-5, 38, 'Z');
rot = printf("   PRINTF = bonjour %-12.32X %5d %9c Florian \n",-5, 38, 'Z');
printf("valeur de retour %d\n",ret);
printf("valeur de retour %d\n",rot);

ret = ft_printf("\nFT_PRINTF = bonjour %-12.32X %5d %9c Florian\n",-5, 38, 'Z');
rot = printf("   PRINTF = bonjour %-12.32X %5d %9c Florian \n",-5, 38, 'Z');
printf("valeur de retour %d\n",ret);
printf("valeur de retour %d\n",rot);

ret = ft_printf("\nFT_PRINTF = bonjour %-12.32X %05d %09c %037.8u %-7.21p Florian\n",-5, 38, 'Z', -54, &b);
rot = printf("   PRINTF = bonjour %-12.32X %05d %09c %037.8u %-7.21p Florian \n",-5, 38, 'Z');
printf("valeur de retour %d\n",ret);
printf("valeur de retour %d\n",rot);

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

ret = ft_printf("\nFT_PRINTF = bonjour %024c Florian\n",'Z');
rot = printf("   PRINTF = bonjour %024c Florian \n",'Z');
printf("valeur de retour %d\n",ret);
printf("valeur de retour %d\n",rot);

ret = ft_printf("\nFT_PRINTF = bonjour %24.2c Florian\n",'Z');
rot = printf("   PRINTF = bonjour %24.2c Florian \n",'Z');
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
rot = printf("   PRINTF = bonjour %d Florian \n",50);
printf("valeur de retour %d\n",ret);
printf("valeur de retour %d\n",rot);

ret = ft_printf("\nFT_PRINTF = bonjour %5d Florian\n",50);
rot = printf("   PRINTF = bonjour %5d Florian \n",50);
printf("valeur de retour %d\n",ret);
printf("valeur de retour %d\n",rot);

ret = ft_printf("\nFT_PRINTF = bonjour %05d Florian\n",50);
rot = printf("   PRINTF = bonjour %05d Florian \n",50);
printf("valeur de retour %d\n",ret);
printf("valeur de retour %d\n",rot);

ret = ft_printf("\nFT_PRINTF = bonjour %010d Florian\n",-50);
rot = printf("   PRINTF = bonjour %010d Florian \n",-50);
printf("valeur de retour %d\n",ret);
printf("valeur de retour %d\n",rot);

ret = ft_printf("\nFT_PRINTF = bonjour %-5d Florian\n",50);
rot = printf("   PRINTF = bonjour %-5d Florian \n",50);
printf("valeur de retour %d\n",ret);
printf("valeur de retour %d\n",rot);

ret = ft_printf("\nFT_PRINTF = bonjour %-*.*d Florian\n",7,9,50);
rot = printf("   PRINTF = bonjour %-*.*d Florian \n",7,9,50);
printf("valeur de retour %d\n",ret);
printf("valeur de retour %d\n",rot);

ret = ft_printf("\nFT_PRINTF = bonjour %*d Florian\n",-7,50);
rot = printf("   PRINTF = bonjour %*d Florian \n",-7,50);
printf("valeur de retour %d\n",ret);
printf("valeur de retour %d\n",rot);

ret = ft_printf("\nFT_PRINTF = bonjour %10.5d Florian\n",-50);
rot = printf("   PRINTF = bonjour %10.5d Florian \n",-50);
printf("valeur de retour %d\n",ret);
printf("valeur de retour %d\n",rot);

ret = ft_printf("\nFT_PRINTF = bonjour %.8d Florian\n",50);
rot = printf("   PRINTF = bonjour %.8d Florian \n",50);
printf("valeur de retour %d\n",ret);
printf("valeur de retour %d\n",rot);

ret = ft_printf("\nFT_PRINTF = bonjour %.8d Florian\n",-50);
rot = printf("   PRINTF = bonjour %.8d Florian \n",-50);
printf("valeur de retour %d\n",ret);
printf("valeur de retour %d\n",rot);

ret = ft_printf("\nFT_PRINTF = bonjour %10.5d Florian\n",-5);
rot = printf("   PRINTF = bonjour %10.5d Florian \n",-5);
printf("valeur de retour %d\n",ret);
printf("valeur de retour %d\n",rot);

ret = ft_printf("\nFT_PRINTF = bonjour %-12.32d Florian\n",-5);
rot = printf("   PRINTF = bonjour %-12.32d Florian \n",-5);
printf("valeur de retour %d\n",ret);
printf("valeur de retour %d\n",rot);

ret = ft_printf("\nFT_PRINTF = bonjour %-*12d Florian\n",7,50);
rot = printf("   PRINTF = bonjour %-*12d Florian \n",7,50);
printf("valeur de retour %d\n",ret);
printf("valeur de retour %d\n",rot);

ret = ft_printf("\nFT_PRINTF = bonjour %-*20*50d Florian\n",1,3,50);
rot = printf("   PRINTF = bonjour %-*20*50d Florian \n",1,3,50);
printf("valeur de retour %d\n",ret);
printf("valeur de retour %d\n",rot);
*/
return (0);
}

// penser aux chiffres negatif avec la width et le zero  --> le zero se met toujours en premier