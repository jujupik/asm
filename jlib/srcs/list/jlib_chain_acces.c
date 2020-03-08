/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jlib_chain_acces.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 18:17:38 by jrouchon          #+#    #+#             */
/*   Updated: 2020/02/29 19:11:29 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jlib.h"

t_chain			*chain_search(t_chain *chain, void *elem)
{
	t_chain	*tmp;

	tmp = chain;
	while (tmp != NULL && tmp->content != elem)
		tmp = tmp->next;
	return (tmp);
}

void			*chain_at(t_chain *chain, size_t index)
{
	t_chain	*tmp;
	size_t	i;

	i = 0;
	tmp = chain;
	while (tmp->next != NULL && i < index)
	{
		tmp = tmp->next;
		i++;
	}
	if (i > index)
		return (NULL);
	return (tmp->content);
}

void			**chain_get(t_chain *chain, size_t index)
{
	t_chain	*tmp;
	size_t	i;

	i = 0;
	tmp = chain;
	while (tmp->next != NULL && i < index)
	{
		tmp = tmp->next;
		i++;
	}
	if (i != index)
		return (NULL);
	return (&(tmp->content));
}

size_t			chain_len(t_chain *chain)
{
	t_chain	*tmp;
	size_t	i;

	i = 0;
	tmp = chain;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
