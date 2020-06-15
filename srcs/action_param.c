/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_param.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 19:41:14 by user42            #+#    #+#             */
/*   Updated: 2020/06/15 19:41:15 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_action_param	create_action_param(PARAM_TYPE p_type, int p_value,
					char *p_label_name)
{
	t_action_param	result;

	result.type = p_type;
	result.value = p_value;
	result.label_name = ft_strdup(p_label_name);
	return (result);
}

t_action_param	*malloc_action_param(PARAM_TYPE p_type, int p_value,
					char *p_label_name)
{
	t_action_param	*result;

	result = (t_action_param*)malloc(sizeof(t_action_param) * 1);
	if (result != NULL)
		*result = create_action_param(p_type, p_value, p_label_name);
	return (result);
}

void			destroy_action_param(t_action_param to_destroy)
{
	if (to_destroy.label_name != NULL)
		free(to_destroy.label_name);
}

void			free_action_param(t_action_param *to_free)
{
	destroy_action_param(*to_free);
	free(to_free);
}
