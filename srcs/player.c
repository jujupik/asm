#include "asm.h"

t_player create_player()
{
	t_player result;

	result.header = NULL;
	result.ope_list = malloc_list(100);
	result.label_list = malloc_list(100);

	return (result);
}

t_player* malloc_player()
{
	t_player* result;

	result = (t_player*)malloc(sizeof(t_player) * 1);
	if (result != NULL)
		*result = create_player();

	return (result);
}

void destroy_player(t_player to_destroy)
{
	free_header(to_destroy.header);
	free_list(to_destroy.ope_list, free_operation);
	free_list(to_destroy.label_list, free_label);
}

void free_player(t_player* to_free)
{
	destroy_player(*to_free);
	free(to_free);
}

void print_player(t_player* player)
{
	size_t i;
	t_operation* ope;

	print_header(player->header);
	i = 0;
	while (i < player->ope_list->size)
	{
		ope = list_at(player->ope_list, i);
		print_operation(ope);
		ft_printf("\n");
		i++;
	}
}

void print_binary_player(t_player* player)
{
	size_t i;
	t_operation* ope;

	print_binary_header(player->header);
	i = 0;
	while (i < player->ope_list->size)
	{
		ope = list_at(player->ope_list, i);
		print_binary_operation(ope);
		i++;
	}
}

void save_player(t_player* player)
{

}