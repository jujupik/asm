/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 19:41:46 by user42            #+#    #+#             */
/*   Updated: 2020/06/30 22:01:30 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

BOOL		read_variable(char **variable, int fd)
{
	char *tmp;
	char *tmp2;

	tmp = *variable;
	while ((tmp == NULL || is_only_compose(tmp, '\n') == TRUE ||
		tmp[0] == COMMENT_CHAR || tmp[0] == COMMENT_CHAR2 ||
		ft_strncchr(tmp, '\"') < 2) && !(tmp2 = NULL))
	{
		if (tmp != NULL && (tmp[0] == COMMENT_CHAR || tmp[0] == COMMENT_CHAR2))
		{
			free(tmp);
			tmp = NULL;
		}
		if (get_next_line(fd, &tmp2) <= 0)
			return (free_variable(NULL, tmp2, tmp, FALSE));
		ft_str_replace_back(&tmp2, "\n");
		ft_str_replace_back(&tmp, tmp2);
		free(tmp2);
	}
	*variable = tmp;
	if (ft_strncchr(*variable, '\"') != 2)
		return (FALSE);
	return (TRUE);
}
