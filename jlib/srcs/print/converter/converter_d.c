/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 17:01:55 by jrouchon          #+#    #+#             */
/*   Updated: 2020/03/08 21:30:58 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jlib.h"

static long long		converter_d_annexe(t_flag_data *flag_data, long long i,
							char **str, BOOL *neg)
{
	if (i < 0)
	{
		flag_data->plus = FALSE;
		(*neg) = TRUE;
		i = -i;
	}
	if (i == 0 && flag_data->point == TRUE && flag_data->precision == 0)
		(*str) = ft_strnew(1);
	else
		(*str) = ft_itoa(i);
	return (i);
}

static void				converter_d_simple(t_data *data, t_flag_data *flag_data)
{
	long long	i;
	BOOL		neg;
	char		*str;

	neg = FALSE;
	handle_wildcard(data, flag_data);
	i = handle_lh(data, flag_data);
	i = converter_d_annexe(flag_data, i, &str, &neg);
	handle_precision(flag_data, &str);
	if (flag_data->zero == TRUE)
	{
		if (flag_data->plus == TRUE || flag_data->space == TRUE || neg == TRUE)
			flag_data->padding--;
		handle_padding_num(flag_data, &str);
	}
	if (flag_data->space == TRUE && flag_data->plus == FALSE && neg == FALSE)
		ft_str_replace_front(" ", &str);
	if (neg == TRUE && i != LLONG_MIN)
		ft_str_replace_front("-", &str);
	if (flag_data->plus == TRUE)
		ft_str_replace_front("+", &str);
	if (flag_data->zero == FALSE)
		handle_padding_num(flag_data, &str);
	add_str_to_buffer(data, str);
	free(str);
}

static void				converter_d_hat(t_data *data, t_flag_data *flag_data)
{
	char	*tmp;
	size_t	len;
	size_t	i;

	i = handle_lh(data, flag_data);
	if (flag_data->h_value == 2)
		len = 1;
	else if (flag_data->h_value == 1)
		len = 2;
	else if (flag_data->l_value == 2)
		len = 16;
	else if (flag_data->l_value == 1)
		len = 8;
	else
		len = 4;
	tmp = convert_int_str(i, len);
	i = 0;
	while (i < len)
	{
		add_char_to_buffer(data, tmp[i]);
		i++;
	}
	free(tmp);
}

void					converter_d(t_data *data, t_flag_data *flag_data)
{
	if (flag_data->hat == FALSE)
		converter_d_simple(data, flag_data);
	else
		converter_d_hat(data, flag_data);
}
