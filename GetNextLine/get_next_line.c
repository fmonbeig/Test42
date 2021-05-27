/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:56:09 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/05/27 13:47:55 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h"
#define BUFFER_SIZE 100
#include "get_next_line_utils.c"
#include <stdio.h>

char *save_line(char *buff)
{
    int i;
    char *str;

    i = 0;
    while (buff[i] != '\n')
    i++;
    
    str = malloc(sizeof(char) * i);
    if (!str)
    return (NULL);
    i = -1;
    while(buff[++i] != '\n')
        str[i] = buff[i];
        str[i] = 0;
        return (str);
}

int find_line(char *save)
{
    int i;
    
    i = -1
    if (!save)
    return(0);
    
    while(save[i++])
    {
        if (save[i] == '\n')
        return (1);
    }
    return(0);
}

int get_next_line(int fd, char **line)
{
    int ret;
    char *buff;
    static char *save;

    i = 0;
    if (fd < 0 || !line || BUFFER_SIZE < 0)
    return (-1);

    buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buff)
    return (-1);
    
    while(!find_line(save) && ret != 0)
    {
    ret = read(fd, buff, BUFFER_SIZE);
    if (ret == -1)
    {
        free(buff);
        return (-1);    
    }
    save = ft_strjoin(save, buff);
    }
    *line = save_line(buff); 
    save = ft_strdup(ft_strchr(buff, '\n') + 1);
    if (save == NULL)
    return (0);
    else
    {
    printf("%s", save);
    return(1);
    }
}