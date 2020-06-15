/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 19:42:15 by user42            #+#    #+#             */
/*   Updated: 2020/06/15 19:42:16 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
