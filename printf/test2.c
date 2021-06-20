/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 12:49:17 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/06/11 15:13:57 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


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

    va_list parametersInfos;
    /* Initialize the va_list structure */
    va_start( parametersInfos, format );

    size_t writtenCharacters = 0;
    char currentChar;

    while( (currentChar = *format) != '\0' ) {
        format ++;
        if ( currentChar != '%' ) {
            putchar( currentChar );
            writtenCharacters ++;
            continue;
        }

        switch( *format ++ ) {
            case 'd':
                {
                    int integerValue = (int) va_arg( parametersInfos, int );
                    writtenCharacters += displayInteger( integerValue );
                }
                break;
            case 'f':
                {
                    double doubleValue = (double) va_arg( parametersInfos, double );
                     int leftPart = (int) doubleValue;
                    writtenCharacters += displayInteger( leftPart );
                    doubleValue -= leftPart;

                    putchar( '.' );
                    writtenCharacters ++;

                    while( ( doubleValue - (int) doubleValue ) > 10e-6 ) {
                        doubleValue *= 10;
                    }
                    writtenCharacters += displayInteger( (int) doubleValue );
                }
                break;
            case 's':
                {
                    const char * string = (const char *) va_arg( parametersInfos, const char * );
                    while( *string != '\0' ) {
                        putchar( *string ++ );
                        writtenCharacters ++;
                    }
                }
                break;
            default:
            fprintf( stderr, "Specified format is not supported!" );
                abort();
        }
    }

    /* Release va_list resources */
    va_end( parametersInfos );

    return writtenCharacters;
}


int main( int argc, char * argv[] ) {

    size_t size = myPrintf( "Begin %s End\n", "Middle" );
   

    size = myPrintf( "Begin %d End\n", 123 );
    

    size = myPrintf( "Begin %f End\n", 123.456 );
   

    size = myPrintf( "Begin %s %d %f End\n", "toto", 421, 123.456 );
    

    return EXIT_SUCCESS;

}