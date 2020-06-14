#include "asm.h"

void		parse_champion_size(t_header *header, t_list *ope_list)
{
	size_t		total_size;
	size_t		i;
	t_operation	*ope;

	total_size = 0;
	i = 0;
	while (i < ope_list->size)
	{
		ope = list_at(ope_list, i);
		ope->pos = total_size;
		parse_operation_size(ope);
		total_size += ope->size;
		i++;
	}
	header->size = total_size;
}

size_t		count_char_before(char *str, char c)
{
	size_t	result;

	result = 0;
	while (str[result] == c)
		result++;
	return (result);
}

void		parse_content_norm(t_player *player, char **tab_label, char *line)
{
	t_label		*label;
	t_operation	*ope;

	tab_label = ft_strsplit_first(line, LABEL_CHAR);
	if (ft_tab_len(tab_label) == 2 && \
		tab_label[0][ft_strlen(tab_label[0]) - 1] != DIRECT_CHAR)
	{
		ope = parse_action(tab_label, 1);
		label = parse_label(tab_label[0], ope);
		list_push_back(player->ope_list, ope);
		list_push_back(player->label_list, label);
	}
	else if (ft_tab_len(tab_label) == 1 || ft_tab_len(tab_label) == 2)
	{
		list_push_back(player->ope_list, parse_action(&line, 0));
	}
	else
		error_exit(1, "Syntax error");
}

BOOL		parse_content(t_player *player, int input_fd)
{
	char		**tab_label;
	char		*line;
	int			nb_line;

	tab_label = NULL;
	line = NULL;
	nb_line = 0;
	while (get_next_line(input_fd, &line) > 0)
	{
		ft_changechar(line, "\t\v\n\r\f", ' ');
		if (ft_strlen(line) > 0 && line[count_char_before(line, ' ')] != '#' \
				&& is_only_compose(line, ' ') == FALSE)
		{
			tab_label = ft_strsplit_first(line, LABEL_CHAR);
			parse_content_norm(player, tab_label, line);
			nb_line++;
		}
	}
	parse_champion_size(player->header, player->ope_list);
	return (parse_label_name(player->ope_list, player->label_list));
}
