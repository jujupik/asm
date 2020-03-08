/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 15:12:29 by jrouchon          #+#    #+#             */
/*   Updated: 2019/01/31 21:55:05 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jlib.h"

char	*ft_strdup(char *str)
{
	char	*result;
	size_t	len;
	size_t	i;

	if (str == NULL)
		return (NULL);
	len = ft_strlen(str);
	result = ft_strnew(len);
	i = 0;
	while (i < len)
	{
		result[i] = str[i];
		i++;
	}
	return (result);
}
