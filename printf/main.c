/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 14:13:41 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/06/03 15:27:31 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int addition( int counter, ... ) {

    int sum = 0;
    va_list parametersInfos;
    /* Initialize the va_list structure */
    va_start( parametersInfos, counter );

    /* for all unnamed integer, do an addition */
    while( counter > 0 ) {

        /* Extraction of the next integer */
        sum += (int) va_arg( parametersInfos, int );

        counter --;
    }

    /* Release va_list resources */
    va_end( parametersInfos );

    return sum;
}

int main( int argc, char * argv[] ) {

int i;
    int result = addition( 2 /* counter */, 3, 11 );
    printf( "addition( 2, 3, 11 ) == %d\n", result );     /* 14 */


    result = addition( 3 /* counter */, 4, 5, 6 );
i =    printf( "addition( 3, 4, 5, 6 ) == %d\n", result );   /* 15 */
printf("%d", i);
    return EXIT_SUCCESS;

}