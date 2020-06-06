/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_leaks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 13:38:27 by jrouchon          #+#    #+#             */
/*   Updated: 2020/02/29 20:06:41 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jlib.h"

BOOL g_debug = FALSE;
size_t	g_ptr_index = 0;
t_chain *g_ptr_chain = NULL;

void	*malloc(size_t size)
{
	static void		*(*ptr)(int) = NULL;
	static BOOL		grown = FALSE;
	t_address		*address;
	void			*result;

	if (ptr == NULL)
		ptr = (void *)dlsym((void *)-1, "malloc");
	if (size == 0)
		return (NULL);
	result = ptr(size);
	if (grown == TRUE || g_debug == FALSE)
		return (result);
	grown = TRUE;
	address = malloc_address(g_ptr_index, result);
	if (g_debug == TRUE)
		address_get_trace(address);
	g_ptr_index++;
	if (g_ptr_chain == NULL)
		g_ptr_chain = malloc_chain(address);
	else
		chain_push_back(g_ptr_chain, address);
	grown = FALSE;
	return (result);
}

void	free(void *to_free)
{
	static void	*(*ptr)(void *) = NULL;

	if (ptr == NULL)
		ptr = (void *)dlsym((void *)-1, "free");
	if (g_ptr_chain != NULL)
		chain_erase(&g_ptr_chain, to_free);
	ptr(to_free);
}

void	ft_get_leaks(char *msg)
{
	t_address	*tmp;
	size_t		len;
	size_t		i;

	if (g_debug == FALSE)
	{
		ft_printf("Can't check leaks\n");
		return ;
	}
	len = chain_len(g_ptr_chain);
	i = 0;
	while (i < len)
	{
		tmp = chain_at(g_ptr_chain, i);
		print_address(tmp);
		i++;
	}
	if (i == 0)
		ft_printf("No leaks\n");
	ft_printf("Over %u malloc done : %u leaked\n", g_ptr_index, len);
	ft_printf("%s\n", msg);
}
