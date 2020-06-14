#include "asm.h"

t_label	*parse_label(char *content, t_operation *ope)
{
	t_label	*result;

	if (is_str_only_compose(content, LABEL_CHARS) == FALSE)
		error_exit(1, "Bad label name");
	result = malloc_label(ope, content);
	return (result);
}

t_label	*find_label(char *name, t_list *label_list)
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

BOOL	parse_label_name(t_list *ope_list, t_list *label_list)
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
