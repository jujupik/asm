/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 16:55:37 by jrouchon          #+#    #+#             */
/*   Updated: 2020/01/27 16:55:39 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jlib.h"

char	*ft_strnew_c(size_t len, char c)
{
	char	*result;

	result = ft_strnew(len);
	ft_str_fill(result, c, len);
	return (result);
}
