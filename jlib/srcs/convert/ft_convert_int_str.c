/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_int_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 19:43:57 by user42            #+#    #+#             */
/*   Updated: 2020/06/15 19:44:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jlib.h"

char	*convert_int_str(long long value, size_t len)
{
	size_t	i;
	char	*result;

	result = ft_strnew(len);
	i = 0;
	while (i < len)
	{
		result[len - i - 1] = ((char *)(&(value)))[len - i - 1];
		i++;
	}
	result[i] = '\0';
	return (result);
}

void	write_int(long long value, size_t len)
{
	size_t	i;
	char	*tmp;

	tmp = convert_int_str(value, len);
	i = 0;
	while (i < len)
	{
		ft_printf("%c", tmp[i]);
		i++;
	}
	free(tmp);
}
