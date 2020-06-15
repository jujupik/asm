/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_header_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 19:42:19 by user42            #+#    #+#             */
/*   Updated: 2020/06/15 19:42:19 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		print_header(t_header *header)
{
	ft_printf("Magic : 0x%X\nSize : %u\nName : %s\nComment : %s\n",
		header->magic_num, header->size, header->name, header->comment);
}

static void	print_binary_parameter(char *data, size_t len)
{
	size_t	i;
	size_t	size;

	size = ft_strlen(data);
	i = 0;
	while (i < len)
	{
		if (i <= size)
			ft_printf("%hhx", data[i]);
		else
			ft_printf("%hhx", '\0');
		i++;
	}
}

void		print_binary_header(t_header *header)
{
	ft_printf("%x", header->magic_num);
	print_binary_parameter(header->name, PROG_NAME_LENGTH);
	ft_printf("%lx", header->size);
	print_binary_parameter(header->comment, COMMENT_LENGTH);
	ft_printf("%lx", 0);
}

static void	print_parameter(int fd, char *data, size_t len)
{
	size_t	i;

	ft_fprintf(fd, "%s", data);
	i = ft_strlen(data);
	while (i < len)
	{
		ft_fprintf(fd, "%c", '\0');
		i++;
	}
}

void		save_header(int fd, t_header *header)
{
	ft_fprintf(fd, "%-^d", header->magic_num);
	print_parameter(fd, header->name, PROG_NAME_LENGTH);
	ft_fprintf(fd, "%-8^d", header->size);
	print_parameter(fd, header->comment, COMMENT_LENGTH);
	ft_fprintf(fd, "%^d", 0);
}
