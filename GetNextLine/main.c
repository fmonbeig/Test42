/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:53:51 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/05/27 18:16:29 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/uio.h>
#include <unistd.h>
#include "get_next_line.c"
//#define BUFFER_SIZE 10

int main (int argv, char **argc)
{
    (void)argv;
    (void)argc;
    char *line;
    int fd;
    int i;
    
    fd = open("test.txt", O_RDONLY);
  
    i = get_next_line(fd, &line);
    printf("\n\n%s", line);
    free(line);

    
    
    /*
    while (i)
    {
        i = get_next_line(fd, &line);
        printf("\n\n%s", line);
        free(line);
    }
    */
    close(fd);
    
    return (0);
}
