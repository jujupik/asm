/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_replace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:42:53 by jrouchon          #+#    #+#             */
/*   Updated: 2020/01/24 16:43:11 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jlib.h"

void	ft_str_replace_front(char *s2, char **s1)
{
	char *result;

	result = ft_strjoin(s2, *s1);
	if (*s1 != NULL)
		free(*s1);
	*s1 = result;
}

void	ft_str_replace_back(char **s1, char *s2)
{
	char *result;

	result = ft_strjoin(*s1, s2);
	if (*s1 != NULL)
		free(*s1);
	*s1 = result;
}
