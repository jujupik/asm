/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 14:31:51 by jrouchon          #+#    #+#             */
/*   Updated: 2019/06/21 15:51:12 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jlib.h"

char	*ft_strcut(char **s1, char delim)
{
	char	*tmp;
	char	*result;
	size_t	len;

	tmp = *s1;
	len = 0;
	while (tmp[len] != '\0' && tmp[len] != delim)
		len++;
	result = ft_strnew(len);
	ft_strncat(result, tmp, len);
	*s1 = ft_strnew(ft_strlen(tmp) - len + 2);
	if (tmp[len] == delim)
		ft_strcat(*s1, &(tmp[len + 1]));
	free(tmp);
	return (result);
}
