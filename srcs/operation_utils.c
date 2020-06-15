/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 19:41:30 by user42            #+#    #+#             */
/*   Updated: 2020/06/15 19:41:31 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char		*param_type_str(t_arg_type type)
{
	if (type == T_REG)
		return ("T_REG");
	else if (type == T_LAB)
		return ("T_LAB");
	else if (type == T_DIR)
		return ("T_DIR");
	else if (type == T_IND)
		return ("T_IND");
	else if (type == T_ERROR)
		return ("T_ERROR");
	else
		return ("Other");
}

void		print_operation(t_operation *to_print)
{
	size_t	i;

	ft_printf("%*s(%*d) [%*u bytes] | ", 5, to_print->action->name, \
				3, to_print->action->id, 2, to_print->size);
	if (to_print->encodage == 0)
		ft_printf("[--] | ");
	else
		ft_printf("[%*X] | ", 2, to_print->encodage);
	i = 0;
	while (i < 3 && to_print->params[i].type != T_ERROR &&
			i < to_print->action->nb_token)
	{
		if (i != 0)
			ft_printf(" - ");
		if (to_print->params[i].type == T_LAB)
			ft_printf("Label [%s](%d)", to_print->params[i].label_name, \
				to_print->params[i].value);
		else if (to_print->params[i].type == T_REG)
			ft_printf("r%d", to_print->params[i].value);
		else if (to_print->params[i].type == T_DIR)
			ft_printf("%%%d", to_print->params[i].value);
		else
			ft_printf("%d", to_print->params[i].value);
		i++;
	}
}

void		print_binary_operation(t_operation *to_print)
{
	size_t	i;

	ft_printf("%02hhx", to_print->action->id);
	if (to_print->encodage != 0)
		ft_printf("%hhx", to_print->encodage);
	i = 0;
	while (i < 3 && to_print->params[i].type != T_ERROR &&
			i < to_print->action->nb_token)
	{
		ft_printf("%04x", to_print->params[i].value);
		i++;
	}
}

void		save_operation(int fd, t_operation *ope)
{
	size_t	i;

	ft_fprintf(fd, "%1^d", ope->action->id);
	if (ope->encodage != 0)
		ft_fprintf(fd, "%1^d", ope->encodage);
	i = 0;
	while (i < 3 && i < ope->action->nb_token)
	{
		if (ope->params[i].type == T_IND || ope->params[i].type == T_LAB_IND ||
			((ope->params[i].type == T_DIR || ope->params[i].type == T_LAB) &&
			ope->action->octal_size_modifier == TRUE))
			ft_fprintf(fd, "%-*^d", IND_SIZE, ope->params[i].value);
		else if (ope->params[i].type == T_REG)
			ft_fprintf(fd, "%-*^d", REG_SIZE, ope->params[i].value);
		else
			ft_fprintf(fd, "%-*^d", DIR_SIZE, ope->params[i].value);
		i++;
	}
}
