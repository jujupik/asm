/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_thing_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 19:41:19 by user42            #+#    #+#             */
/*   Updated: 2020/06/15 19:55:54 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	place_ope_on_null(t_player *player, t_operation *ope)
{
	t_label		**label;
	size_t		i;

	i = 0;
	while (i < player->label_list->size)
	{
		label = (t_label **)list_get(player->label_list, i);
		if ((*label)->ope == NULL)
			(*label)->ope = ope;
		i++;
	}
}

void		do_thing_ope(t_player *player, char *string_ope,
		char *string_label)
{
	t_label		*label;
	t_operation	*ope;

	ope = NULL;
	label = NULL;
	if (string_ope != NULL)
	{
		ope = parse_action(string_ope);
		list_push_back(player->ope_list, ope);
	}
	if (string_label != NULL)
	{
		label = parse_label(string_label, ope);
		list_push_back(player->label_list, label);
	}
	if (ope != NULL)
		place_ope_on_null(player, ope);
}
