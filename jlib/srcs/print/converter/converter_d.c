/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 17:01:55 by jrouchon          #+#    #+#             */
/*   Updated: 2020/06/15 19:45:20 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jlib.h"

static long long	converter_d_annexe(t_flag_data *flag_data, long long i,
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

static void			converter_d_simple(t_data *data, t_flag_data *flag_data)
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

static void			print_hat_int(t_data *data, char *str, size_t len, \
						BOOL minus)
{
	size_t	i;

	if (minus == TRUE)
	{
		i = len;
		while (i > 0)
		{
			add_char_to_buffer(data, str[i - 1]);
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			add_char_to_buffer(data, str[i]);
			i++;
		}
	}
}

static void			converter_d_hat(t_data *data, t_flag_data *flag_data)
{
	char	*tmp;
	size_t	len;
	size_t	i;

	handle_wildcard(data, flag_data);
	i = (int)(handle_lh(data, flag_data));
	if (flag_data->padding != 0)
		len = flag_data->padding;
	else
		len = 4;
	tmp = convert_int_str(i, len);
	print_hat_int(data, tmp, len, flag_data->minus);
	free(tmp);
}

void				converter_d(t_data *data, t_flag_data *flag_data)
{
	if (flag_data->hat == FALSE)
		converter_d_simple(data, flag_data);
	else
		converter_d_hat(data, flag_data);
}
