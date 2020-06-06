/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_address.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 13:38:27 by jrouchon          #+#    #+#             */
/*   Updated: 2020/02/29 20:04:14 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jlib.h"

t_address	create_address(size_t p_index, void *p_ptr)
{
	t_address	result;

	result.index = p_index;
	result.ptr = p_ptr;
	result.size = 0;
	result.strings = NULL;
	return (result);
}

t_address	*malloc_address(size_t p_index, void *p_ptr)
{
	t_address	*result;

	result = (t_address *)malloc(sizeof(t_address));
	if (result == NULL)
		error_exit(111, "Can't malloc a t_address");
	*result = create_address(p_index, p_ptr);
	return (result);
}

void		destroy_address(t_address to_destroy)
{
	if (to_destroy.strings != NULL)
		free(to_destroy.strings);
}

void		free_address(t_address *to_free)
{
	if (to_free != NULL)
		destroy_address(*to_free);
	free(to_free);
}

void		address_get_trace(t_address *address)
{
	void	*array[10];

	address->size = backtrace(array, 10);
	address->strings = backtrace_symbols(array, address->size);
}
