/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:56:09 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/06/03 10:47:51 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*save_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	line = malloc(sizeof(char) * i + 1);
	if (!line)
		return (NULL);
	i = -1;
	while (str[++i] && str[i] != '\n')
		line[i] = str[i];
	line[i] = '\0';
	return (line);
}

static char	*save_rest(char *save)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\0')
	{
		free(save);
		save = NULL;
		return (NULL);
	}
	ret = malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!ret)
		return (NULL);
	while (save[++i])
		ret[j++] = save[i];
	ret[j] = '\0';
	free(save);
	save = NULL;
	return (ret);
}

static int	nextline(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (0);
	while (str[++i])
		if (str[i] == '\n')
			return (1);
	return (0);
}

static int	result(int fd, int ret, char **line, char **save)
{
	*line = save_line(save[fd]);
	save[fd] = save_rest(save[fd]);
	if (save[fd] == NULL)
	{
		free (save[fd]);
		save[fd] = NULL;
	}
	if (ret == 0 && save[fd] == NULL)
		return (0);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	char		buff[BUFFER_SIZE + 1];
	static char	*save[12288];
	int			ret;

	ret = 1;
	if (!line || fd < 0 || fd > 12288 || BUFFER_SIZE <= 0)
		return (-1);
	while (!nextline(save[fd]) && ret != 0)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret < 0)
			return (-1);
		buff[ret] = '\0';
		if (!save[fd])
			save[fd] = ft_strdup(buff);
		else
			save[fd] = ft_strjoin(save[fd], buff);
	}
	return (result(fd, ret, line, save));
}
