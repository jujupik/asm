/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 15:24:48 by jrouchon          #+#    #+#             */
/*   Updated: 2020/03/08 16:56:25 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jlib.h"

BOOL	ft_strncmp(char *s1, char *s2, size_t n)
{
	unsigned int i;

	i = 0;
	if (n == 0)
		return (TRUE);
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i] && i < n)
		i++;
	if (i == n)
		i--;
	return (((unsigned char)s1[i] - (unsigned char)s2[i]) == 0 ? TRUE : FALSE);
}
