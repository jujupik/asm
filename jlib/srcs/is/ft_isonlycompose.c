/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isonlycompose.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 18:01:12 by jrouchon          #+#    #+#             */
/*   Updated: 2020/03/08 18:12:44 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jlib.h"

BOOL			is_only_compose(char *src, char c)
{
	size_t		i;

	i = 0;
	while (src[i])
	{
		if (src[i] != c)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

BOOL			is_str_only_compose(char *src, char *delim)
{
	size_t		i;

	i = 0;
	while (src[i])
	{
		if (ft_strcchr(delim, src[i]) == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
