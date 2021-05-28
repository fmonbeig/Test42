/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:53:51 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/05/28 15:23:18 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"
//#include "get_next_line.c"
//#define BUFFER_SIZE 10

int main (int argv, char **argc)
{
    (void)argv;
    (void)argc;
    char *line;
    int fd;
    int n = 1;
    
    fd = open("test.txt", O_RDONLY);
  
    while(n)
    {
    n = get_next_line(fd, &line);
     if(n == -1)
     {
     printf("GNL FAILED");
        break;
     }
    printf("%d \n", n);
    printf("%s\n", line);
    free(line);
    }

    close(fd);
    
    return (0);
}
