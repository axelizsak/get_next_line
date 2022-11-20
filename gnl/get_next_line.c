/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aizsak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:25:34 by aizsak            #+#    #+#             */
/*   Updated: 2022/11/20 18:33:24 by aizsak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_reader(int fd, char *buff, char *temp)
{
	char	*temp1;
	int		reader;

	reader = 1;
	while (reader != -1)
	{
		reader = read(fd, buff, BUFFER_SIZE);
		if (reader == -1)
			return (0);
		else if (reader == 0)
			break;
		buff[reader] = '\0';
		if (!temp)
			temp = ft_strdup("");
		temp1 = temp;
		temp = ft_strjoin(temp1, buff);
		free(temp1);
		temp1 = NULL;
		if (ft_strchr(buff, '\n'))
			break;
	}
	return (temp);
}

static char	*ft_get_line(char *line)
{
	size_t	i;
	char	*temp;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0') 
		i++;
	if (line[i] == '\n' || line[i] == '\0') 
		return (0);
	temp = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*temp == '\0')
	{
		free(temp);
		temp = NULL;
	}
	line[i + 1] = '\0';
	return (temp);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buff;
	static char	*temp;

	if (fd < 0)
		return (0);
	buff = ((char *)malloc(sizeof(char) * (BUFFER_SIZE + 1)));
		if (!buff)
			return (NULL);
	line = ft_reader(fd, buff, temp);
	free(buff);
	buff = NULL;
	if (!line)
		return (NULL);
	temp = ft_get_line(line);
	return (line);
}
