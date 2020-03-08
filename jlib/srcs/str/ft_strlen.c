/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 18:07:27 by jrouchon          #+#    #+#             */
/*   Updated: 2020/02/29 16:35:24 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jlib.h"

size_t	ft_strlen(char *str)
{
	size_t result;

	if (str == NULL)
		return (0);
	result = 0;
	while (str[result] != '\0')
		result++;
	return (result);
}
