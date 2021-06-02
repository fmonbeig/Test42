/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:56:09 by fmonbeig          #+#    #+#             */
/*   Updated: 2021/06/02 14:29:13 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	if (!str)
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

static int	result(int ret, char **line, char **save)
{
	*line = save_line(*save);
	*save = save_rest(*save);
	if (*save == NULL)
	{
		free (*save);
		*save = NULL;
	}
	if (ret == 0 && *save == NULL)
		return (0);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	char		buff[BUFFER_SIZE + 1];
	static char	*save;
	int			ret;

	ret = 1;
	if (!line || fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	while (!nextline(save) && ret != 0)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret < 0)
			return (-1);
		buff[ret] = '\0';
		if (!save)
			save = ft_strdup(buff);
		else
			save = ft_strjoin(save, buff);
	}
	return (result(ret, line, &save));
}
