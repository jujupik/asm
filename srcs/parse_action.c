/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 19:41:41 by user42            #+#    #+#             */
/*   Updated: 2020/06/16 02:09:19 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			}
			else
				result[i] = ft_strdup(tab[i]);
		}
		i++;
	}
	ft_tab_free(tab);
	return (result);
}

static void		parse_action_else(t_action_param *action_params, \
	char *action_line, t_base_op *action)
{
	char			**tab_param;
	size_t			i;

	ft_changechar(action_line, "#;", '\0');
	tab_param = ft_strsplit(action_line, SEPARATOR_CHAR);
	tab_param = parse_tab_param(tab_param);
	if (ft_tab_len(tab_param) != action->nb_token)
		error_exit(1, "Syntax error");
	action_params[0] = create_action_param(T_ERROR, 0, NULL);
	action_params[1] = create_action_param(T_ERROR, 0, NULL);
	action_params[2] = create_action_param(T_ERROR, 0, NULL);
	i = 0;
	while (i < 3 && i < action->nb_token)
	{
		if (i < ft_tab_len(tab_param))
			action_params[i] = parse_parameter(action, tab_param[i], i);
		else
			action_params[i] = create_action_param(T_ERROR, 0, NULL);
		i++;
	}
	ft_tab_free(tab_param);
}

t_operation		*parse_action(char *operation_line)
{
	t_base_op		*action;
	char			**tab_action;
	t_action_param	action_params[3];

	action = NULL;
	tab_action = ft_strsplit_first(operation_line, ' ');
	action = find_action_in_tab(tab_action[0]);
	if (action == NULL)
	{
		ft_printf("Line [%s]\n", operation_line);
		error_exit(1, "Invalid action");
	}
	else
	{
		if (ft_tab_len(tab_action) < 2)
			error_exit(1, "Syntax error");
		parse_action_else(&(action_params[0]), tab_action[1], action);
	}
	ft_tab_free(tab_action);
	return (malloc_operation(action, action_params));
}
