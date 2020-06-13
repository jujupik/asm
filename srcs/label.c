#include "asm.h"

t_label	create_label(t_operation *p_ope, char *p_name)
{
	t_label	result;

	result.ope = p_ope;
	result.name = p_name;
	return (result);
}

t_label	*malloc_label(t_operation *p_ope, char *p_name)
{
	t_label *result;

	result = (t_label*)malloc(sizeof(t_label) * 1);
	if (result != NULL)
		*result = create_label(p_ope, p_name);
	return (result);
}

void	destroy_label(t_label to_destroy)
{
	free(to_destroy.name);
}

void	free_label(t_label *to_free)
{
	destroy_label(*to_free);
	free(to_free);
}

void	print_label(t_label *to_print)
{
	ft_printf("[%s] | [%d] -> [%s]", to_print->name,
			to_print->ope->pos, to_print->ope->action->name);
	print_operation(to_print->ope);
}
