/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apasos-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 19:11:41 by apasos-g          #+#    #+#             */
/*   Updated: 2019/04/01 21:53:30 by apasos-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gettheline(char **rem, char **buffers)
{
	char	*line;
	char	*ptr;
	char	*str;

	str = ft_strdup(*rem);
	ptr = ft_strchr(str, '\n');
	*ptr = '\0';
	line = ft_strdup(str);
	ptr++;
	if (*ptr != '\0')
		*buffers = ft_strdup(ptr);
	free(str);
	return (line);
}

void	reading(char **rem, int fd)
{
	char	bf[BUFF_SIZE + 1];
	char	*temp;
	int		readn;

	ft_bzero(bf, BUFF_SIZE);
	readn = BUFF_SIZE;
	while ((!(ft_strchr(*rem, '\n'))) && readn > 0)
	{
		readn = read(fd, bf, BUFF_SIZE);
		bf[readn] = '\0';
		temp = *rem;
		*rem = ft_strjoin(*rem, bf);
		free(temp);
	}
	if (readn == 0 && (*rem)[0] == '\0')
	{
		free(*rem);
		*rem = NULL;
	}
}

int		readfile(char **rem, char **line, char **buffers, int fd)
{
	reading(rem, fd);
	if (*rem == NULL)
		return (0);
	if (ft_strchr(*rem, '\n'))
		*line = gettheline(rem, buffers);
	else
		*line = ft_strdup(*rem);
	free(*rem);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char		*buffers[FILES_LIM];
	char			test[1];
	char			*rem;

	if (read(fd, test, 0) < 0 || line == NULL || BUFF_SIZE < 1)
		return (-1);
	if ((buffers[fd] != NULL) && (ft_strchr(buffers[fd], '\n')))
	{
		rem = ft_strdup(buffers[fd]);
		free(buffers[fd]);
		buffers[fd] = NULL;
		*line = gettheline(&rem, &buffers[fd]);
		free(rem);
		return (1);
	}
	if (buffers[fd] == NULL)
		rem = ft_strdup("");
	else
	{
		rem = ft_strdup(buffers[fd]);
		free(buffers[fd]);
		buffers[fd] = NULL;
	}
	return (readfile(&rem, line, &buffers[fd], fd));
}
