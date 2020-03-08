/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 17:01:55 by jrouchon          #+#    #+#             */
/*   Updated: 2020/03/08 20:29:44 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jlib.h"

void					converter_s(t_data *data, t_flag_data *flag_data)
{
	char	*str;
	char	*str2;

	handle_wildcard(data, flag_data);
	str = va_arg(data->arg, char *);
	if (str == NULL)
		str2 = ft_strdup("(null)");
	else
		str2 = ft_strdup(str);
	if ((ft_strlen(str2) > (size_t)(flag_data->precision))
			&& flag_data->point == TRUE)
		str2[(size_t)(flag_data->precision)] = '\0';
	handle_padding(flag_data, &str2);
	add_str_to_buffer(data, str2);
	free(str2);
}

void					converter_c(t_data *data, t_flag_data *flag_data)
{
	char	c;
	char	*str;

	str = NULL;
	flag_data->space = FALSE;
	handle_wildcard(data, flag_data);
	c = va_arg(data->arg, int);
	if (c == '\0')
	{
		if (flag_data->padding > 1)
			str = ft_strnew_c(flag_data->padding - 1, ' ');
		if (flag_data->minus == FALSE)
			add_str_to_buffer(data, str);
		add_char_to_buffer(data, '\0');
		if (flag_data->minus == TRUE)
			add_str_to_buffer(data, str);
	}
	else
	{
		str = ft_strnew_c(1, c);
		handle_padding_c(flag_data, &str);
		add_str_to_buffer(data, str);
		free(str);
	}
}

void					converter_i(t_data *data, t_flag_data *flag_data)
{
	converter_d(data, flag_data);
}
