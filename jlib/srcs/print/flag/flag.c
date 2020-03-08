/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 17:03:47 by jrouchon          #+#    #+#             */
/*   Updated: 2020/03/08 20:01:00 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jlib.h"

size_t	flag_sharp(t_flag_data *data, char *cmd, int i)
{
	(void)cmd;
	(void)i;
	data->sharp = TRUE;
	return (1);
}

size_t	flag_zero(t_flag_data *data, char *cmd, int i)
{
	(void)cmd;
	(void)i;
	if (data->point == FALSE)
		data->zero = TRUE;
	else
		data->precision = 0;
	return (1);
}

size_t	flag_minus(t_flag_data *data, char *cmd, int i)
{
	(void)cmd;
	(void)i;
	data->minus = TRUE;
	data->zero = FALSE;
	return (1);
}

size_t	flag_plus(t_flag_data *data, char *cmd, int i)
{
	(void)cmd;
	(void)i;
	data->plus = TRUE;
	return (1);
}

size_t	flag_space(t_flag_data *data, char *cmd, int i)
{
	(void)cmd;
	(void)i;
	data->space = TRUE;
	return (1);
}
