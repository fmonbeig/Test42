/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 14:13:41 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/06/13 18:56:56 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "printf.c"
#include "printf_utils.c"
//#include "libft.h"

int main ()
{
int ret;

ret = ft_printf("bonjour %d poil", 78 );
//printf("bon\\\\poil %d", 78 );
//printf("\n bonjour");
//fflush(stdout);
printf("\n%d",ret);

return (0);
}