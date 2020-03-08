/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strschr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 17:26:27 by jrouchon          #+#    #+#             */
/*   Updated: 2020/02/23 13:35:20 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jlib.h"

BOOL		ft_strschr(char *s, char *model)
{
	char *tmp;

	tmp = ft_strstr(s, model);
	return (tmp == NULL ? FALSE : TRUE);
}
