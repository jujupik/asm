#include "asm.h"

size_t	parse_octal_encoding(t_operation *ope)
{
	if (ope->action->need_octal == TRUE)
		return (1);
	else
		return (0);
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
	encode = 0;
	while (i < 3)
	{
		param = &(ope->params[i]);
		if (param->type == T_REG)
			tmp_funct_reg(&encode, delta, &result);
		else if (param->type == T_DIR || param->type == T_LAB)
			tmp_funct_dir(&encode, delta, &result, ope->action->octal_size_modifier);
		else if (param->type == T_IND || ope->params[i].type == T_LAB_IND)
			tmp_funct_ind(&encode, delta, &result);
		else
			tmp_funct_other(&encode, delta, &result);
		i++;
	}
	ope->size = result + delta;
	ope->encodage = encode;
}
