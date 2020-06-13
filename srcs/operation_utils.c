#include "asm.h"

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
	while (i < 3 && to_print->params[i].type != T_ERROR)
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

	ft_printf("%hhx", to_print->action->id);
	if (to_print->encodage != 0)
		ft_printf("%hhx", to_print->encodage);
	i = 0;
	while (i < 3 && to_print->params[i].type != T_ERROR)
	{
		ft_printf("%x", to_print->params[i].value);
		i++;
	}
}

void		save_operation(int fd, t_operation *ope)
{
	size_t	i;

	ft_fprintf(fd, "%^hhd", ope->action->id);
	if (ope->encodage != 0)
		ft_fprintf(fd, "%^hhd", ope->encodage);
	i = 0;
	while (i < 3)
	{
		if (ope->params[i].type == T_IND ||
			((ope->params[i].type == T_DIR || ope->params[i].type == T_LAB) &&
			ope->action->octal_size_modifier == TRUE))
			ft_fprintf(fd, "%^hd", ope->params[i].value);
		else
			ft_fprintf(fd, "%^d", ope->params[i].value);
		i++;
	}
}
