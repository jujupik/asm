/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jlib_chain.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 18:17:38 by jrouchon          #+#    #+#             */
/*   Updated: 2020/02/29 20:05:43 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jlib.h"

t_chain	create_chain(void *p_content)
{
	t_chain result;

	result.content = p_content;
	result.next = NULL;
	result.previous = NULL;
	return (result);
}

t_chain	*malloc_chain(void *p_content)
{
	t_chain	*result;

	result = (t_chain *)malloc(sizeof(t_chain));
	if (result == NULL)
		error_exit(111, "Can't malloc a t_chain");
	*result = create_chain(p_content);
	return (result);
}

void	destroy_chain(t_chain to_destroy, t_destroy_funct funct)
{
	(void)to_destroy;
	(void)funct;
	ft_printf("TO DO - destroy chain\n");
}

void	free_chain(t_chain *to_free, t_destroy_funct funct)
{
	destroy_chain(*to_free, funct);
	free(to_free);
}
