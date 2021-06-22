/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 14:13:41 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/06/22 18:43:18 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"
//#include "printf.c"
//#include "printf_utils.c"
//#include "libft.h"

int main ()
{
//int ret;

//ret = ft_printf("bonjour %d Florian", 50 );
//printf("\n valeur de retour %d\n",ret);

ft_printf(
    
    "\nFT_PRINTF = bonjour %d Florian\n"
    "\nFT_PRINTF = bonjour %5d Florian\n"
    "\nFT_PRINTF = bonjour %5d Florian\n"
    "\nFT_PRINTF = bonjour %05d Florian\n"
    "\nFT_PRINTF = bonjour %-5d Florian\n"
    "\nFT_PRINTF = bonjour %-05d Florian\n"
    "\nFT_PRINTF = bonjour %*d Florian\n"
    "\nFT_PRINTF = bonjour %7.5d Florian\n"
    
    ,50,509864,50,-50,50,50,-7,50,50 );

//printf("\n\n%d",ft_countnbr(50));

return (0);
}

// penser aux chiffres negatif avec la width et le zero  --> le zero se met toujours en premier