/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_content.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 19:42:09 by user42            #+#    #+#             */
/*   Updated: 2020/06/15 19:42:09 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		compute_line_percent(char **line)
{
	char	*tmp;
	size_t	i;
	size_t	j;

	ft_changechar(*line, "\t\v\n\r\f", ' ');
	j = ft_strncchr(*line, '%');
	i = ft_strlen(*line) + (j > 0 ? j : 0);
	tmp = *line;
	(*line) = ft_strnew(i);
	i = 0;
	j = 0;
	ft_strcpy(*line, tmp);
	while (i < ft_strlen(*line))
	{
		if (tmp[i] == '%' && tmp[i - 1] != ' ')
		{
			(*line)[i + j] = ' ';
			j++;
		}
		(*line)[i + j] = tmp[i];
		i++;
	}
	(*line)[i + j] = '\0';
	if (tmp != NULL)
		free(tmp);
}

BOOL		parse_content(t_player *player, int input_fd)
{
	char	**tab_label;
	char	*line;
	int		nb_line;

	tab_label = NULL;
	line = NULL;
	nb_line = 0;
	while (get_next_line(input_fd, &line) > 0)
	{
		if (ft_strlen(line) != 0)
		{
			compute_line_percent(&line);
			if (ft_strlen(line) > 0 && \
				line[count_char_before(line, ' ')] != '#' && \
				is_only_compose(line, ' ') == FALSE)
			{
				tab_label = ft_strsplit_first(line, LABEL_CHAR);
				parse_content_norm(player, tab_label, line);
				nb_line++;
			}
		}
	}
	parse_champion_size(player->header, player->ope_list);
	return (parse_label_name(player->header, player->ope_list, \
		player->label_list));
}
