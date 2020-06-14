#include "asm.h"

int	g_need_octal_encoding[9] =
{
	2, 3, 6, 7, 8, 10, 11, 13, 14
};

size_t	parse_octal_encoding(t_operation *ope)
{
	size_t	i;
	size_t	delta;

	delta = 0;
	i = 0;
	while (i < 9)
	{
		if (g_need_octal_encoding[i] == ope->action->id)
			delta = 1;
		i++;
	}
	return (delta);
}

void	parse_operation_size(t_operation *ope)
{
	size_t			i;
	size_t			delta;
	size_t			result;
	char			encode;
	t_action_param	*param;

	result = 1;
	delta = parse_octal_encoding(ope);
	i = 0;
	while (i < 3)
	{
		param = &(ope->params[i]);
		if (param->type == T_REG)
			tmp_funct_reg(&encode, delta, &result);
		else if (param->type == T_DIR || param->type == T_LAB)
			tmp_funct_dir(&encode, delta, &result, \
							ope->action->octal_size_modifier);
		else if (param->type == T_IND)
			tmp_funct_ind(&encode, delta, &result);
		else
			tmp_funct_other(&encode, delta, &result);
		i++;
	}
	ope->size = result + delta;
	ope->encodage = encode;
}
