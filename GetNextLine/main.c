/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:53:51 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/06/02 10:19:05 by fmonbeig         ###   ########.fr       */
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
    int t = 1;
    
    //fd = open("gnl-war-machine-v2019/tests/user_output_buff_9999_Mr._Justice_Maxell_by_Edgar_Wallace.txt", O_RDONLY);
    fd = open("test", O_RDWR);


    while(n)
    {
        printf("Boucle %d \n =======\n", t++);
     n = get_next_line(fd, &line);
     if(n == -1)
     {
     printf("GNL FAILED");
     printf("%d \n", n);
    printf("%s\n", line);
        break;
     }
    printf("retour gnl = %d \n", n);
    printf("la ligne == %s\n", line);

    free(line);
    line = NULL;
    }
    close(fd);
    
    return (0);
}
