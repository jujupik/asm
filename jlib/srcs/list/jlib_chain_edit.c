/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jlib_chain_edit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 18:17:38 by jrouchon          #+#    #+#             */
/*   Updated: 2020/02/29 19:29:03 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jlib.h"

void		chain_push_back(t_chain *chain, void *to_add)
{
	t_chain	*new_part;
	t_chain	*tmp;

	new_part = malloc_chain(to_add);
	tmp = chain;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new_part;
	new_part->previous = tmp;
}

void		chain_push_front(t_chain **chain, void *to_add)
{
	t_chain	*new_part;
	t_chain	*tmp;

	new_part = malloc_chain(to_add);
	tmp = *chain;
	while (tmp->previous != NULL)
		tmp = tmp->previous;
	tmp->previous = new_part;
	new_part->next = tmp;
	*chain = new_part;
}

void		chain_remove(t_chain *to_remove)
{
	t_chain	**next;
	t_chain	**previous;

	next = &(to_remove->next);
	previous = &(to_remove->previous);
	if ((*next) != NULL)
		(*next)->previous = *previous;
	if ((*previous) != NULL)
		(*previous)->next = *next;
	free_address(to_remove->content);
	free(to_remove);
}

void		chain_pop_back(t_chain *chain, size_t index)
{
	t_chain	*tmp;
	size_t	i;

	i = 0;
	tmp = chain;
	while (tmp->next != NULL && index > i)
		tmp = tmp->next;
	if (i != index)
		return ;
	chain_remove(tmp);
}

void		chain_erase(t_chain **chain, void *elem)
{
	t_chain		*tmp;
	t_address	*tmp_address;

	if (chain == NULL || *chain == NULL)
		return ;
	tmp = *chain;
	tmp_address = tmp->content;
	if (tmp_address->ptr == elem)
	{
		*chain = tmp->next;
		chain_remove(tmp);
		return ;
	}
	while (tmp != NULL)
	{
		tmp_address = tmp->content;
		if (tmp_address->ptr == elem)
		{
			chain_remove(tmp);
			tmp = NULL;
		}
		else
			tmp = tmp->next;
	}
}
