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

BOOL		empty_line(char **variable, int fd)
{
	while ((*variable) == NULL || (*variable)[0] == COMMENT_CHAR ||
			ft_strlen(*variable) == 0)
	{
		if (get_next_line(fd, variable) <= 0)
			return (TRUE);
	}
	return (FALSE);
}

BOOL		analyse_variable(int fd, char *name, char **variable,
				char **variable_cmd)
{
	char **tab;

	(*variable) = NULL;
	(*variable_cmd) = NULL;
	tab = NULL;
	if (empty_line(variable, fd) == TRUE)
		return (free_variable(tab, (*variable), (*variable_cmd)));
	ft_str_replace_back(variable, "\n");
	tab = ft_strsplit((*variable), '\"');
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
