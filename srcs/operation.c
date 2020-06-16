/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 19:41:33 by user42            #+#    #+#             */
/*   Updated: 2020/06/16 01:01:37 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_operation	create_operation(t_base_op *p_action, t_action_param *p_param)
{
	t_operation	result;
	size_t		i;

	result.action = p_action;
	result.size = 0;
	result.encodage = 0;
	result.pos = 0;
	i = 0;
	while (i < 3)
	{
		result.params[i] = p_param[i];
		i++;
	}
	return (result);
}

t_operation	*malloc_operation(t_base_op *p_action, t_action_param *p_param)
{
	t_operation	*result;

	result = (t_operation*)malloc(sizeof(t_operation) * 1);
	if (result != NULL)
		*result = create_operation(p_action, p_param);
	return (result);
}

void		destroy_operation(t_operation to_destroy)
{
	size_t	i;

	i = 0;
	while (i < 3)
	{
		destroy_action_param(to_destroy.params[i]);
		i++;
	}
}

void		free_operation(t_operation *to_free)
{
	destroy_operation(*to_free);
	free(to_free);
}
