/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_operation_size.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 19:41:59 by user42            #+#    #+#             */
/*   Updated: 2020/06/15 19:54:10 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

size_t		parse_octal_encoding(t_operation *ope)
{
	if (ope->action->need_octal == TRUE)
		return (1);
	else
		return (0);
}

static void	other_funct(t_operation *ope, t_action_param *param, \
						char *encode, size_t *result)
{
	size_t			delta;

	delta = parse_octal_encoding(ope);
	if (param->type == T_REG)
		tmp_funct_reg(encode, delta, result);
	else if (param->type == T_DIR || param->type == T_LAB)
		tmp_funct_dir(encode, delta, result, ope->action->octal_size_modifier);
	else if (param->type == T_IND || param->type == T_LAB_IND)
		tmp_funct_ind(encode, delta, result);
	else
		tmp_funct_other(encode, delta, result);
}

void		parse_operation_size(t_operation *ope)
{
	size_t			i;
	size_t			result;
	char			encode;
	t_action_param	*param;

	result = 1;
	i = 0;
	encode = 0;
	while (i < 3)
	{
		param = &(ope->params[i]);
		other_funct(ope, param, &encode, &result);
		i++;
	}
	ope->size = result + parse_octal_encoding(ope);
	ope->encodage = encode;
}
