/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 13:02:20 by jrouchon          #+#    #+#             */
/*   Updated: 2019/01/28 19:58:17 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jlib.h"

void	*ft_memccpy(void *dest, void *src, int c, size_t len)
{
	unsigned int	i;
	char			*destp;
	char			*srcp;

	i = 0;
	destp = (char *)dest;
	srcp = (char *)src;
	while (i < len)
	{
		destp[i] = srcp[i];
		if (srcp[i] == (char)c)
			return (destp + i + 1);
		i++;
	}
	return (NULL);
}
