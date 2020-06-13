#include "asm.h"

t_player	create_player(void)
{
	t_player result;

	result.header = NULL;
	result.ope_list = malloc_list(100);
	result.label_list = malloc_list(100);
	return (result);
}

t_player	*malloc_player(void)
{
	t_player	*result;

	result = (t_player*)malloc(sizeof(t_player) * 1);
	if (result != NULL)
		*result = create_player();
	return (result);
}

void		call_free_operation(void *ptr)
{
	free_operation(ptr);
}

void		call_free_label(void *ptr)
{
	free_label(ptr);
}
