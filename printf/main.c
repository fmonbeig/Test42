/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 14:13:41 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/06/23 14:09:38 by fmonbeig         ###   ########.fr       */
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

ret = ft_printf("bonjour %d", 50 );
printf("\n valeur de retour %d\n",ret);
/*
printf("\n==========INTEGER TEST================\n\n");
ft_printf("\nFT_PRINTF = bonjour %d Florian\n",50);
printf("   PRINTF = bonjour %d Florian\n",50);

ft_printf("\nFT_PRINTF = bonjour %5d Florian\n",50);
printf("   PRINTF = bonjour %5d Florian\n",50);

ft_printf("\nFT_PRINTF = bonjour %05d Florian\n",50);
printf("   PRINTF = bonjour %05d Florian\n",50);

ft_printf("\nFT_PRINTF = bonjour %010d Florian\n",-50);
printf("   PRINTF = bonjour %010d Florian\n",-50);

ft_printf("\nFT_PRINTF = bonjour %-5d Florian\n",50);
printf("   PRINTF = bonjour %-5d Florian\n",50);

ft_printf("\nFT_PRINTF = bonjour %-*.*d Florian\n",7,9,50);
printf("   PRINTF = bonjour %-*.*d Florian\n",7,9,50);

ft_printf("\nFT_PRINTF = bonjour %*d Florian\n",7,50);
printf("   PRINTF = bonjour %*d Florian\n",7,50);

ft_printf("\nFT_PRINTF = bonjour %10.5d Florian\n",-50);
printf("   PRINTF = bonjour %10.5d Florian\n",-50);

ft_printf("\nFT_PRINTF = bonjour %.8d Florian\n",50);
printf("   PRINTF = bonjour %.8d Florian\n",50);

ft_printf("\nFT_PRINTF = bonjour %.8d Florian\n",-50);
printf("   PRINTF = bonjour %.8d Florian\n",-50);
*/


return (0);
}

// penser aux chiffres negatif avec la width et le zero  --> le zero se met toujours en premier