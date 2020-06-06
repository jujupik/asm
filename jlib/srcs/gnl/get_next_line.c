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
	int fd;
	int error = _sopen_s(&fd, path, mode, _SH_DENYNO, _S_IREAD | _S_IWRITE); // A remplacer par fd = open(path, mode);
	if (error == EACCES)
		error_exit(error, "Le chemin d'acces donne est un repertoire, ou le fichier est en lecture seule, mais une operation de type \" ouvert en ecriture \" a ete tentee.");
	if (error == EEXIST)
		error_exit(error, "Les indicateurs _O_CREAT et _O_EXCL ont ete specifies, mais le nom de fichier existe deja.");
	if (error == EINVAL)
		error_exit(error, "Argument Oflag, shflagou PMODE non valide, ou PFH ou filename etait un pointeur null.");
	if (error == EMFILE)
		error_exit(error, "Plus aucun descripteur de fichier disponible.");
	if (error == ENOENT)
		error_exit(error, "Fichier ou chemin d’acces introuvable.");
	if (g_saved[fd] != NULL)
		free(g_saved[fd]);
	g_saved[fd] = ft_strnew(0);
	return (fd);
}

void			close_fd(int fd)
{
	if (fd < 0 || fd >= MAX_FD)
		error_exit(fd, "Invalid fd to close");
	if (g_saved[fd] != NULL)
		free(g_saved[fd]);
	g_saved[fd] = NULL;
	_close(fd);
}

static int		get_next_line_result(char **line, char **saved)
{
	int size;
	if (*line != NULL)
		free(*line);
	if (ft_strlen(*saved) == 0)
	{
		*line = NULL;
		return (0);
	}
	size = ft_strlen(*saved);
	*line = ft_strcut(saved, '\n');
	return (ft_strlen(*line) + size);
}

int				get_next_line(int fd, char **line)
{
	int			result;
	char		*tmp;
	char		buff[BUFF_SIZE + 1];

	if (fd == 1 || fd == 2 || fd >= MAX_FD)
		return (-1);
	result = 1;
	while (ft_strcchr(g_saved[fd], '\n') == FALSE && result > 0)
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
