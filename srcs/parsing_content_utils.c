/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_content_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 19:42:06 by user42            #+#    #+#             */
/*   Updated: 2020/06/15 19:56:39 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		parse_champion_size(t_header *header, t_list *ope_list)
{
	int			total_size;
	size_t		i;
	t_operation	*ope;

	total_size = 0;
	i = 0;
	while (i < ope_list->size)
	{
		ope = list_at(ope_list, i);
		parse_operation_size(ope);
		ope->pos = total_size;
		total_size += ope->size;
		i++;
	}
	header->size = total_size;
}

size_t		count_char_before(char *str, char c)
{
	size_t	result;

	result = 0;
	while (str[result] == c)
		result++;
	return (result);
}
