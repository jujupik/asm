#include "asm.h"

void		parse_champion_size(t_header *header, t_list *ope_list)
{
	int		total_size;
	size_t		i;
	t_operation	*ope;

	total_size = 0;
	i = 0;
	while (i < ope_list->size)
	{
		ope = list_at(ope_list, i);
		parse_operation_size(ope);
		ope->pos = total_size;
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

static void do_thing_ope(t_player *player, char *string_ope,
		char *string_label)
{
	t_label		*label;
	t_operation	*ope;

	ope = parse_action(string_ope);
	label = parse_label(string_label, ope);
	list_push_back(player->ope_list, ope);
	list_push_back(player->label_list, label);
}

void compute_line_percent(char **line)
{
	char *tmp;
	size_t i;
	size_t j;

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
	free(tmp);
}

static void		parse_content_norm(int input_fd, t_player *player,
								char **tab_label, char *line)
{
	char *tmp;

	if (ft_tab_len(tab_label) == 2 && \
		tab_label[0][ft_strlen(tab_label[0]) - 1] != DIRECT_CHAR &&
		is_only_compose(tab_label[1], ' ') == FALSE)
	{
		if (ft_strcchr(tab_label[0], ' ') == TRUE)
			list_push_back(player->ope_list, parse_action(line));
		else
			do_thing_ope(player, tab_label[1], tab_label[0]);
	}
	else if (	ft_tab_len(tab_label) == 2 &&
				ft_strncchr(tab_label[0], ' ') == 0 &&
				is_only_compose(tab_label[1], ' ') == TRUE)
	{
		tmp = NULL;
		if (get_next_line(input_fd, &tmp) <= 0)
			error_exit(1, "Not enought param for an operation");
		compute_line_percent(&tmp);
		do_thing_ope(player, tmp, tab_label[0]);
	}
	else if (ft_tab_len(tab_label) == 1 || ft_tab_len(tab_label) == 2)
		list_push_back(player->ope_list, parse_action(line));
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
		compute_line_percent(&line);
		if (ft_strlen(line) > 0 && line[count_char_before(line, ' ')] != '#' \
				&& is_only_compose(line, ' ') == FALSE)
		{
			tab_label = ft_strsplit_first(line, LABEL_CHAR);
			parse_content_norm(input_fd, player, tab_label, line);
			nb_line++;
		}
	}
	parse_champion_size(player->header, player->ope_list);
	return (parse_label_name(player->ope_list, player->label_list));
}
