/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aizsak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:20:08 by aizsak            #+#    #+#             */
/*   Updated: 2022/12/11 10:01:09 by aizsak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_strjoin(char *reader, char *buff);
char	*get_line(char *buff);
char	*trimmed_buff(char *buff);
char	*get_file(char *buff, int fd);
int		ft_strlen2(char *str);
int		check(char *str);
int		ft_strlen(char *str);
#endif
