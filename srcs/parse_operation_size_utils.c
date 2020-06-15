/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_operation_size_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 19:41:56 by user42            #+#    #+#             */
/*   Updated: 2020/06/15 19:41:56 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	set_encode_info(char *encode, size_t delta, char encode_info)
{
	if (delta == 1)
	{
		*encode += encode_info;
		*encode = *encode << 2;
	}
}

void	tmp_funct_reg(char *encode, size_t delta, size_t *result)
{
	set_encode_info(encode, delta, 0b01);
	*result += REG_SIZE;
}

void	tmp_funct_dir(char *encode, size_t delta, size_t *result, BOOL octal)
{
	set_encode_info(encode, delta, 0b10);
	if (octal == TRUE)
		*result += 2;
	else
		*result += DIR_SIZE;
}

void	tmp_funct_ind(char *encode, size_t delta, size_t *result)
{
	set_encode_info(encode, delta, 0b11);
	*result += IND_SIZE;
}

void	tmp_funct_other(char *encode, size_t delta, size_t *result)
{
	set_encode_info(encode, delta, 0b00);
	*result += 0;
}
