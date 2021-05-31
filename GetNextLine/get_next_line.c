/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:56:09 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/05/30 23:10:22 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//#include "get_next_line_utils.c"
//#define BUFFER_SIZE 1

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
    while (buff[++i] && buff[i] != '\n')
        str[i] = buff[i];
        str[i] = '\0';
        return (str);
}

static char *save_rest(char *save)
{
    int i;
    int j;
    char *ret;
    
    i = 0;
    j = 0;
    while(save[i] && save[i] != '\n')
        i++;
    
    if (!save[i])
    return (NULL);

    ret = malloc(sizeof(char) * (ft_strlen(save) - i + 1));
    if (!ret)
    return (NULL);
    
    while(save[++i])
        ret[j++] = save[i];
        ret[j] = '\0';
    free(save);
    return (ret);
}

int get_next_line(int fd, char **line)
{
    int ret;
    char buff[BUFFER_SIZE + 1];
    static char *save;

    if (fd < 0 || !line || BUFFER_SIZE <= 0)
    return (-1);
     
    while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
    {
        buff[ret] = '\0';
        if (!save)
        save = ft_strdup(buff);
        else if (save)
            save = ft_strjoin(save, buff);
        //printf(" SAVE : %s 9 \n", save);
        if (ft_strchr(save, '\n'))
        break;
    }
    //printf("save apres join --> %s\n", save);
     if (ret <= 0 && !save)
     return (-1);
    *line = save_line(save);
    //printf("%s", *line);
    save = save_rest(save);
    if (!save)
    return (0);
    //printf("save apres save rest = %s\n", save);
    return(1);
}