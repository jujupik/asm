/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 19:41:46 by user42            #+#    #+#             */
/*   Updated: 2020/06/15 19:41:46 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static BOOL	free_variable(char **tab, char *tmp, char *tmp_cmd)
{
	if (tab != NULL)
		ft_tab_free(tab);
	if (tmp != NULL)
		free(tmp);
	if (tmp_cmd != NULL)
		free(tmp_cmd);
	return (FALSE);
}

BOOL		read_variable(char **variable, int fd)
{
	char *tmp;
	char *tmp2;

	tmp = *variable;
	tmp2 = NULL;
	while (tmp == NULL || is_only_compose(tmp, '\n') == TRUE ||
			tmp[0] == COMMENT_CHAR || ft_strncchr(tmp, '\"') < 2)
	{
		if (tmp != NULL && tmp[0] == COMMENT_CHAR)
		{
			free(tmp);
			tmp = NULL;
		}
		if (get_next_line(fd, &tmp2) <= 0)
			return (FALSE);
		ft_str_replace_back(&tmp2, "\n");
		ft_str_replace_back(&tmp, tmp2);
	}
	*variable = tmp;
	if (ft_strncchr(*variable, '\"') != 2)
		return (FALSE);
	return (TRUE);
}

BOOL		analyse_variable(int fd, char *name, char **variable,
				char **variable_cmd)
{
	char **tab;

	(*variable) = NULL;
	(*variable_cmd) = NULL;
	tab = NULL;
	if (read_variable(variable, fd) == FALSE)
		return (free_variable(tab, (*variable), (*variable_cmd)));
	tab = ft_strsplit_emptyspace((*variable), '\"');
	free((*variable));
	if (ft_tab_len(tab) == 1 || ft_tab_len(tab) > 3 || (ft_tab_len(tab) == 3 &&
		is_str_only_compose(tab[2], " \t\v\n\r") == FALSE))
	{
		ft_tab_free(tab);
		return (FALSE);
	}
	(*variable_cmd) = tab[0];
	(*variable) = tab[1];
	if (ft_strschr((*variable_cmd), name) == FALSE)
		return (free_variable(NULL, (*variable), (*variable_cmd)));
	ft_delchar(&(*variable_cmd), " \t\v\n\r");
	free(tab);
	return (TRUE);
}

t_header	*parse_header(int fd)
{
	char *name;
	char *name_cmd;
	char *comment;
	char *comment_cmd;

	if (analyse_variable(fd, NAME_CMD_STRING, &name, &name_cmd) == FALSE)
		error_exit(1, "Trouble around name descriptor");
	if (analyse_variable(fd, COMMENT_CMD_STRING, &comment,
			&comment_cmd) == FALSE)
		error_exit(1, "Trouble around comment descriptor");
	if (ft_strcmp(name_cmd, ".name") == FALSE)
		error_exit(1, "Bad name command");
	if (ft_strcmp(comment_cmd, ".comment") == FALSE)
		error_exit(1, "Bad comment command");
	free(comment_cmd);
	free(name_cmd);
	return (malloc_header(name, comment, 0));
}
