/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 19:42:12 by user42            #+#    #+#             */
/*   Updated: 2020/06/24 02:32:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	destroy_player(t_player to_destroy)
{
	free_header(to_destroy.header);
	free_list(to_destroy.ope_list, call_free_operation);
	free_list(to_destroy.label_list, call_free_label);
}

void	free_player(t_player *to_free)
{
	destroy_player(*to_free);
	free(to_free);
}

void	print_player(t_player *player)
{
	size_t			i;
	t_operation		*ope;

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

void	print_binary_player(t_player *player)
{
	size_t			i;
	t_operation		*ope;

	print_binary_header(player->header);
	i = 0;
	while (i < player->ope_list->size)
	{
		ope = list_at(player->ope_list, i);
		print_binary_operation(ope);
		i++;
	}
}

void	save_player(int output_fd, t_player *player)
{
	size_t			i;
	t_operation		*ope;

	save_header(output_fd, player->header);
	i = 0;
	while (i < player->ope_list->size)
	{
		ope = list_at(player->ope_list, i);
		save_operation(output_fd, ope);
		i++;
	}
	if (player->ope_list->size == 0)
		error_exit(1, "No operation in file");
}
