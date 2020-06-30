/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 19:41:46 by user42            #+#    #+#             */
/*   Updated: 2020/06/30 22:02:19 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

BOOL		free_variable(char **tab, char *tmp, char *tmp_cmd, BOOL state)
{
	if (tab != NULL)
		ft_tab_free(tab);
	if (tmp != NULL)
		free(tmp);
	if (tmp_cmd != NULL)
		free(tmp_cmd);
	return (state);
}

void		switch_descriptor(char **tmp_cmd, char **tmp, char **variable_cmd,
				char **variable)
{
	*variable = *tmp_cmd;
	*variable_cmd = *tmp;
	*tmp_cmd = NULL;
	*tmp = NULL;
}

BOOL		analyse_variable(int fd, char **tmp_cmd, char **tmp)
{
	char	**tab;

	tab = NULL;
	if (read_variable(tmp_cmd, fd) == FALSE)
		return (free_variable(tab, *tmp_cmd, *tmp, FALSE));
	tab = ft_strsplit_emptyspace(*tmp_cmd, '\"');
	free(*tmp_cmd);
	if (ft_tab_len(tab) == 1 || ft_tab_len(tab) > 3 || (ft_tab_len(tab) == 3 &&
	is_str_only_compose(tab[2], " \t\v\n\r") == FALSE))
	{
		ft_tab_free(tab);
		error_exit(1, "Trouble around comment or name descriptor");
	}
	*tmp = ft_strdup(tab[1]);
	*tmp_cmd = ft_strdup(tab[0]);
	ft_tab_free(tab);
	ft_delchar(tmp_cmd, " \t\v\n\r");
	return (TRUE);
}

BOOL		parse_norme(int fd, char **var_cmd, char **var)
{
	if (analyse_variable(fd, &(var_cmd[0]), &(var[0])) == FALSE)
		return (FALSE);
	if (ft_strcmp(var_cmd[0], NAME_CMD_STRING) == TRUE)
	{
		switch_descriptor(&var_cmd[0], &var[0], &var_cmd[1], &var[1]);
		if (analyse_variable(fd, &(var_cmd[0]), &(var[0])) == FALSE)
			return (free_variable(NULL, var_cmd[1], var[1], FALSE));
		switch_descriptor(&var_cmd[0], &var[0], &var_cmd[2], &var[2]);
		return (TRUE);
	}
	else if (ft_strcmp(var_cmd[0], COMMENT_CMD_STRING) == TRUE)
	{
		switch_descriptor(&var_cmd[0], &var[0], &var_cmd[2], &var[2]);
		if (analyse_variable(fd, &(var_cmd[0]), &(var[0])) == FALSE)
			return (free_variable(NULL, var_cmd[2], var[2], FALSE));
		switch_descriptor(&var_cmd[0], &var[0], &var_cmd[1], &var[1]);
		return (TRUE);
	}
	else
		return (free_variable(NULL, var_cmd[0], var[0], FALSE));
}

t_header	*parse_header(int fd)
{
	t_header	*header;
	char		*var[3];
	char		*var_cmd[3];

	var[0] = NULL;
	var_cmd[0] = NULL;
	if (parse_norme(fd, var, var_cmd) == FALSE)
		error_exit(1, "error around header descriptor");
	free(var_cmd[1]);
	free(var_cmd[2]);
	header = malloc_header(var[1], var[2], 0);
	free(var[1]);
	free(var[2]);
	return (header);
}
