/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 14:31:51 by jrouchon          #+#    #+#             */
/*   Updated: 2020/03/08 18:02:06 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jlib.h"

char	*g_saved[MAX_FD];

int			open_fd(char* path, int mode)
{
	int fd = _open(path, mode);
	if (g_saved[fd] != NULL)
		free(g_saved[fd]);
	g_saved[fd] = ft_strnew(0);
	return (fd);
}

void			close_fd(int fd)
{
	if (g_saved[fd] != NULL)
		free(g_saved[fd]);
	g_saved[fd] = NULL;
	_close(fd);
}

static int		get_next_line_result(char **line, char **saved)
{
	if (*line != NULL)
		free(*line);
	if (ft_strlen(*saved) == 0)
	{
		*line = NULL;
		return (0);
	}
	*line = ft_strcut(saved, '\n');
	return (ft_strlen(*line) + ft_strlen(*saved));
}

int				get_next_line(int fd, char **line)
{
	int			result;
	char		*tmp;
	char		buff[BUFF_SIZE + 1];

	if (fd == 1 || fd == 2 || fd >= MAX_FD)
		return (-1);
	result = 1;
	while (ft_strcchr(g_saved[fd], '\n') == 0 && result > 0)
	{
		result = _read(fd, buff, BUFF_SIZE);
		buff[result] = '\0';
		if (result > 0)
		{
			tmp = g_saved[fd];
			g_saved[fd] = ft_strjoin(tmp, buff);
			free(tmp);
		}
	}
	return (get_next_line_result(line, &(g_saved[fd])));
}
