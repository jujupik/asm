/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_changechar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 19:46:10 by user42            #+#    #+#             */
/*   Updated: 2020/06/15 19:46:11 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jlib.h"

void	ft_changechar(char *str, char *target, char c)
{
	size_t	i;

	if (str == NULL)
		return ;
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_strcchr(target, str[i]) == TRUE)
			str[i] = c;
		i++;
	}
}
