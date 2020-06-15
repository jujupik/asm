/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 19:41:50 by user42            #+#    #+#             */
/*   Updated: 2020/06/15 19:53:04 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_label		*parse_label(char *content, t_operation *ope)
{
	t_label	*result;

	if (is_str_only_compose(content, LABEL_CHARS) == FALSE)
		error_exit(1, "Bad label name");
	result = malloc_label(ope, content);
	return (result);
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

static BOOL	handle_label_value(t_header *header, t_operation *ope, \
		t_list *label_list)
{
	t_label			*label;
	size_t			j;

	j = 0;
	while (j < 3 && j < ope->action->nb_token)
	{
		if (ope->params[j].type == T_LAB ||
			ope->params[j].type == T_LAB_IND)
		{
			label = find_label(ope->params[j].label_name, label_list);
			if (label == NULL)
			{
				print_operation(ope);
				return (FALSE);
			}
			if (label->ope == NULL)
				ope->params[j].value = header->size - ope->pos;
			else
				ope->params[j].value = label->ope->pos - ope->pos;
		}
		j++;
	}
	return (TRUE);
}

BOOL		parse_label_name(t_header *header, t_list *ope_list, \
				t_list *label_list)
{
	t_operation		*ope;
	size_t			i;

	i = 0;
	while (i < ope_list->size)
	{
		ope = list_at(ope_list, i);
		if (handle_label_value(header, ope, label_list) == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
