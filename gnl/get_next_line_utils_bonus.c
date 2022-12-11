/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aizsak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:26:49 by aizsak            #+#    #+#             */
/*   Updated: 2022/12/11 10:09:10 by aizsak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_strlen2(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*ft_strjoin(char *reader, char *buff)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = -1;
	if (!reader && !buff)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(reader) + ft_strlen(buff)) + 1);
	if (!str)
		return (NULL);
	if (buff)
	{
		while (buff[i] != '\0')
		{
			str[i] = buff[i];
			i++;
		}
	}
	while (reader[++j] != '\0')
		str[i + j] = reader[j];
	if (buff)
		free(buff);
	str[i + j] = '\0';
	return (str);
}

int	check(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (1);
	return (0);
}
