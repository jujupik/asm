/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_header.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 19:42:22 by user42            #+#    #+#             */
/*   Updated: 2020/06/16 00:56:19 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_header	create_header(char *p_name, char *p_comment, size_t p_size)
{
	t_header	result;

	result.magic_num = COREWAR_EXEC_MAGIC;
	ft_str_fill(result.name, '\0', PROG_NAME_LENGTH);
	ft_str_fill(result.comment, '\0', COMMENT_LENGTH);
	if (ft_strlen(p_name) >= PROG_NAME_LENGTH)
		error_exit(1, "Name too long");
	if (ft_strlen(p_comment) >= COMMENT_LENGTH)
		error_exit(1, "Comment too long");
	ft_strcpy(result.name, p_name);
	ft_strcpy(result.comment, p_comment);
	result.size = p_size;
	return (result);
}

t_header	*malloc_header(char *p_name, char *p_comment, size_t p_size)
{
	t_header	*result;

	result = (t_header	*)malloc(sizeof(t_header));
	if (result == NULL)
		return (NULL);
	*result = create_header(p_name, p_comment, p_size);
	return (result);
}

void		destroy_header(t_header to_destroy)
{
	(void)to_destroy;
}

void		free_header(t_header *to_free)
{
	destroy_header(*to_free);
	free(to_free);
}
