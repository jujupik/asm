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
	else if (ft_strisdigit(param) == TRUE)
		return (T_IND);
	else
		return (T_ERROR);
}

void			parse_parameter_error(char *content)
{
	ft_printf("Line [%s]\n", content);
	error_exit(1, "Bad token type");
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
	*label_name = &(content[2]);
	return (value);
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
		parse_parameter_error(content);
	if (type == T_ERROR)
		error_exit(1, "Syntax error");
	else if (type == T_REG)
		value = parse_parameter_reg(content);
	else if (type == T_IND)
		value = ft_atoi(content);
	else if (type == T_DIR)
		value = ft_atoi(&(content[1]));
	else if (type == T_LAB)
		value = parse_parameter_lab(content, &label_name);
	else
		error_exit(1, "Syntax error");
	return (create_action_param(type, value, label_name));
}
