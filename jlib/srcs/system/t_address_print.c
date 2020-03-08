/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_address_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 13:38:27 by jrouchon          #+#    #+#             */
/*   Updated: 2020/03/08 13:39:12 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jlib.h"

void	print_address(t_address *address)
{
	size_t	i;

	ft_printf("Malloc num %u : %p", address->index, address->ptr);
	if (address->size < 3)
	{
		ft_printf("\n");
		return ;
	}
	ft_printf(" -> \n");
	ft_printf("Leaks data : [%s]\n", address->ptr);
	i = address->size - 2;
	while (i >= 2)
	{
		ft_printf("				%s\n", address->strings[i]);
		i--;
	}
}
