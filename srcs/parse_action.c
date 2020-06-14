#include "asm.h"

t_base_op	g_actions[17] = {
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and)  r1, r2, r3   r1&r2 -> r3", 1, 0},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or)   r1, r2, r3   r1 | r2 -> r3", 1, 0},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor)  r1, r2, r3   r1^r2 -> r3", 1, 0},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0},
	{NULL, 0, {0}, 0, 0, NULL, 0, 0}
};

t_base_op		*find_action_in_tab(char *name)
{
	size_t i;
	size_t delta;

	delta = 0;
	while (name[delta] == ' ')
		delta++;
	i = 0;
	while (g_actions[i].name != NULL)
	{
		if (ft_strcmp(g_actions[i].name, &(name[delta])) == TRUE)
			return (&(g_actions[i]));
		i++;
	}
	return (NULL);
}

char			**parse_tab_param(char **tab)
{
	char	**result;
	size_t	i;
	BOOL	found;

	result = ft_tab_new(ft_tab_len(tab));
	i = 0;
	found = FALSE;
	while (i < ft_tab_len(tab))
	{
		if (tab[i] != NULL)
		{
			if (tab[i][0] == COMMENT_CHAR || found == TRUE)
			{
				found = TRUE;
				result[i] = NULL;
				free(tab[i]);
			}
			else
				result[i] = tab[i];
		}
		i++;
	}
	free(tab);
	return (result);
}

t_action_param	parse_action_else(char **tab_action, char **tab_param, \
										t_base_op *action)
{
	size_t			i;
	t_action_param	action_params[3];

	i = 0;
	ft_changechar(tab_action[1], "#", '\0');
	tab_param = ft_strsplit(tab_action[1], SEPARATOR_CHAR);
	tab_param = parse_tab_param(tab_param);
	if (ft_tab_len(tab_param) != action->nb_token)
		error_exit(1, "Syntax error");
	i = 0;
	while (i < 3)
	{
		if (i < ft_tab_len(tab_param))
			action_params[i] = parse_parameter(action, tab_param[i], i);
		else
			action_params[i] = create_action_param(T_ERROR, 0, NULL);
		i++;
	}
	return (*action_params);
}

t_operation		*parse_action(char **tab_label, int index)
{
	t_base_op		*action;
	char			**tab_action;
	char			**tab_param;
	t_action_param	action_params[3];

	action = NULL;
	tab_action = NULL;
	tab_param = NULL;
	tab_action = ft_strsplit_first(tab_label[index], ' ');
	action = find_action_in_tab(tab_action[0]);
	if (action == NULL)
	{
		ft_printf("Line [%s]\n", tab_action[0]);
		error_exit(1, "Invalid action");
	}
	else
	{
		*action_params = parse_action_else(tab_action, tab_param, action);
	}
	return (malloc_operation(action, action_params));
}
