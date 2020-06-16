/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_action_param.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 19:41:37 by user42            #+#    #+#             */
/*   Updated: 2020/06/16 02:12:08 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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
	else if (param[0] == LABEL_CHAR)
		return (param[1] != '\0' ? T_LAB_IND : T_ERROR);
	else if (ft_strisdigit(param) == TRUE)
		return (T_IND);
	else
		return (T_ERROR);
}

int				parse_parameter_reg(char *content)
{
	int			value;

	value = ft_atoi(&(content[1]));
	if (value < 1 || value > REG_NUMBER)
		error_exit(1, "Bad register number");
	return (value);
}

int				parse_parameter_lab(char *content, char **label_name)
{
	int			value;

	value = -1;
	if (content[0] == DIRECT_CHAR)
		*label_name = ft_strdup(&(content[2]));
	else if (content[0] == LABEL_CHAR)
		*label_name = ft_strdup(&(content[1]));
	return (value);
}

static int		parse_param_value(PARAM_TYPE type, char *tmp, \
			char **label_name)
{
	int		value;

	value = 0;
	if (type == T_ERROR)
		error_exit(1, "Syntax error");
	else if (type == T_REG)
		value = parse_parameter_reg(tmp);
	else if (type == T_IND)
		value = ft_atoi(tmp);
	else if (type == T_DIR)
		value = ft_atoi(&(tmp[1]));
	else if (type == T_LAB || type == T_LAB_IND)
		value = parse_parameter_lab(tmp, label_name);
	else
		error_exit(1, "Syntax error");
	return (value);
}

t_action_param	parse_parameter(t_base_op *action, char *content, int tok_index)
{
	t_action_param	result;
	int				value;
	PARAM_TYPE		type;
	char			*label_name;
	char			*tmp;

	tmp = ft_strdup(content);
	ft_delchar(&(tmp), " \t\v\n\r");
	label_name = NULL;
	type = check_type_param(tmp);
	if ((type & action->availible_token[tok_index]) != type)
	{
		ft_printf("Line [%s]\n", content);
		error_exit(1, "Bad token type");
	}
	value = parse_param_value(type, tmp, &label_name);
	result = create_action_param(type, value, label_name);
	free(tmp);
	free(label_name);
	return (result);
}
