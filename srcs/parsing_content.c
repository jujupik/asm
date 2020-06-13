#include "asm.h"

t_base_op	actions[17] = {
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
	while (actions[i].name != NULL)
	{
		if (ft_strcmp(actions[i].name, &(name[delta])) == TRUE)
			return (&(actions[i]));
		i++;
	}
	return (NULL);
}

PARAM_TYPE		check_type_param(char *param)
{
	if (param == NULL)
		return (T_ERROR);
	if (param[0] == 'r')
		return (T_REG);
	else if (param[0] == DIRECT_CHAR)
	{
		if (param[1] == LABEL_CHAR)
			return (param[2] != '\0' ? T_LAB : T_ERROR);
		else
			return (ft_strisdigit(&(param[1])) == TRUE ? T_DIR : T_ERROR);
	}
	else if (ft_strisdigit(param) == TRUE)
		return (T_IND);
	else
		return (T_ERROR);
}

t_action_param	parse_parameter(t_base_op *action, char *content, int tok_index)
{
	PARAM_TYPE	type;
	int			value;
	char		*label_name;

	ft_delchar(&(content), " \t\v\n\r");
	value = 0;
	label_name = NULL;
	type = check_type_param(content);
	if ((type & action->availible_token[tok_index]) != type)
	{
		ft_printf("Line [%s]\n", content);
		error_exit(1, "Bad token type");
	}
	if (type == T_ERROR)
		error_exit(1, "Syntax error");
	else if (type == T_REG)
	{
		value = ft_atoi(&(content[1]));
		if (value < 1 || value > REG_NUMBER)
			error_exit(1, "Bad register number");
	}
	else if (type == T_IND)
		value = ft_atoi(content);
	else if (type == T_DIR)
		value = ft_atoi(&(content[1]));
	else if (type == T_LAB)
	{
		value = -1;
		label_name = &(content[2]);
	}
	else
		error_exit(1, "Syntax error");
	return (create_action_param(type, value, label_name));
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

t_action_param	parse_action_else(char **tab_action, char **tab_param, t_base_op *action)
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

t_label			*parse_label(char *content, t_operation *ope)
{
	t_label	*result;

	if (is_str_only_compose(content, LABEL_CHARS) == FALSE)
		error_exit(1, "Bad label name");
	result = malloc_label(ope, content);
	return (result);
}

void		parse_champion_size(t_header *header, t_list *ope_list)
{
	size_t		total_size;
	size_t		i;
	t_operation	*ope;

	total_size = 0;
	i = 0;
	while (i < ope_list->size)
	{
		ope = list_at(ope_list, i);
		ope->pos = total_size;
		parse_operation_size(ope);
		total_size += ope->size;
		i++;
	}
	header->size = total_size;
}

t_label		*find_label(char *name, t_list *label_list)
{
	size_t		i;
	t_label		*label;

	i = 0;
	while (i < label_list->size)
	{
		label = list_at(label_list, i);
		if (ft_strcmp(label->name, name) == TRUE)
			return (label);
		i++;
	}
	return (NULL);
}

BOOL		parse_label_name(t_list *ope_list, t_list *label_list)
{
	t_operation		*ope;
	t_label			*label;
	size_t			i;
	size_t			j;

	i = 0;
	while (i < ope_list->size)
	{
		ope = list_at(ope_list, i);
		j = 0;
		while (j < 3)
		{
			if (ope->params[j].type == T_LAB)
			{
				label = find_label(ope->params[j].label_name, label_list);
				if (label == NULL)
					return (FALSE);
				else
					ope->params[j].value = label->ope->pos - ope->pos;
			}
			j++;
		}
		i++;
	}
	return (TRUE);
}

size_t		count_char_before(char *str, char c)
{
	size_t	result;

	result = 0;
	while (str[result] == c)
		result++;
	return (result);
}

void	parse_content_norm(t_player *player, char **tab_label, char *line)
{
	t_label		*label;
	t_operation	*ope;

	tab_label = ft_strsplit_first(line, LABEL_CHAR);
	if (ft_tab_len(tab_label) == 2 && \
		tab_label[0][ft_strlen(tab_label[0]) - 1] != DIRECT_CHAR)
	{
		ope = parse_action(tab_label, 1);
		label = parse_label(tab_label[0], ope);
		list_push_back(player->ope_list, ope);
		list_push_back(player->label_list, label);
	}
	else if (ft_tab_len(tab_label) == 1 || ft_tab_len(tab_label) == 2)
	{
		list_push_back(player->ope_list, parse_action(&line, 0));
	}
	else
		error_exit(1, "Syntax error");
}

BOOL	parse_content(t_player *player, int input_fd)
{
	char		**tab_label;
	char		*line;
	int			nb_line;

	tab_label = NULL;
	line = NULL;
	nb_line = 0;
	while (get_next_line(input_fd, &line) > 0)
	{
		ft_changechar(line, "\t\v\n\r\f", ' ');
		if (ft_strlen(line) > 0 && line[count_char_before(line, ' ')] != '#' \
				&& is_only_compose(line, ' ') == FALSE)
		{
			tab_label = ft_strsplit_first(line, LABEL_CHAR);
			parse_content_norm(player, tab_label, line);
			nb_line++;
		}
	}
	parse_champion_size(player->header, player->ope_list);
	return (parse_label_name(player->ope_list, player->label_list));
}
