/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 12:49:17 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/06/11 16:12:22 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "printf_utils.c"


size_t displayInteger( int value ) {
    if ( value < 10 ) {
        putchar( 0x30 + value );
        return 1;
    }
    size_t size = displayInteger( value / 10);
    putchar( 0x30 + value % 10 );
    return 1 + size;
}


/*
 * This function is a very simplified version of printf.
 * The only supported formats are:
 *      %s : inject a string
 *      %d : inject an integer value
 *      %f : inject a double value
 */
int myPrintf( const char * format, ... ) {
    int i;
    int n = 0;
    va_list parametersInfos;
    /* Initialize the va_list structure */
    va_start( parametersInfos, format );

    size_t writtenCharacters = 0;
    char currentChar;

    while(*format) 
    {   
        if ( *format != '%' ) { 
            ft_putchar( *format++ );
            writtenCharacters ++;
            continue;
        }
        format++;
        if(*format == 'd')
    {
    i = (int)va_arg(parametersInfos, int);
       ft_putnbr(i);
       //displayInteger(i);
       //writtenCharacters += ft_countnbr(i);
       format++;
       continue;
    }   
    }

    /* Release va_list resources */
    va_end( parametersInfos );

    return writtenCharacters;
}


int main( int argc, char * argv[] ) {

size_t size;
    size = myPrintf( "Begin %d End\n", 123 );
    


    return EXIT_SUCCESS;

}