/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 14:31:51 by jrouchon          #+#    #+#             */
/*   Updated: 2020/06/15 19:45:51 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jlib.h"

int			ft_strncchr(char *str, char c)
{
	int		i;
	int		result;

	result = 0;
	if (str == NULL)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			result++;
		i++;
	}
	return (result);
}

BOOL		ft_strcchr(char *str, char c)
{
	return (ft_strncchr(str, c) >= 1 ? TRUE : FALSE);
}
