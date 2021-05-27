/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:56:09 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/05/27 18:19:38 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h"
#define BUFFER_SIZE 10
#include "get_next_line_utils.c"
#include <stdio.h>

static char *save_line(char *buff)
{
    int i;
    char *str;

    i = 0;
    while (buff[i] && buff[i] != '\n')
    i++;
    
    str = malloc(sizeof(char) * i);
    if (!str)
    return (NULL);
    i = -1;
    while (buff[++i] != '\n')
        str[i] = buff[i];
        str[i] = '\0';
        return (str);
}

/*
static int find_line(char *save)
{
    int i;
    
    i = -1;
    if (!save)
    return(0);
    
    while(save[i++])
    {
        if (save[i] == '\n')
        return (1);
    }
    return(0);
}
*/
static char *save_rest(char *save)
{
    int i;
    char *ret;
    
    i = 0;
    while(save[i] != '\n')
        i++;
    
    if (!save[i])
    return (NULL);

    ret = malloc(sizeof(char) * (ft_strlen(save) - i + 1));
    if (!ret)
    return (NULL);
    
    while(save[++i])
        *ret++ = save[i];
        *ret = '\0';
    free(save);
    return (ret);
}


int get_next_line(int fd, char **line)
{
    int ret;
    char buff[BUFFER_SIZE + 1];
    static char *save;

    if (fd < 0 || !line || BUFFER_SIZE < 0)
    return (-1);
    
    while (ret == read(fd, buff, BUFFER_SIZE) > 0)
    {
        buff[ret] = '\0';
        if (!save)
        save = ft_strdup(buff);
        else if (save)
        {
            save = ft_strjoin(save, buff);
            free(buff);
        }
        if (ft_strchr(save, '\n'))
        break;
    }
    
    *line = save_line(save);
    printf("%s", *line);
    save = save_rest(save);
    if (!save)
    return (0);
    printf("%s", save);
    return(1);
}




 /*    while (find_line(save) != 1 && ret != 0)
    {
    ret = read(fd, buff, BUFFER_SIZE);
    if (ret == -1)
    {
        free(buff);
        return (-1);    
    }
    buff[ret] = '\0';
    
    save = ft_strjoin(save, buff);
    free(buff);
    }
*/