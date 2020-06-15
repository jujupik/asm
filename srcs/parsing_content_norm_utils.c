/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_content_norm_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 19:42:03 by user42            #+#    #+#             */
/*   Updated: 2020/06/15 19:57:24 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		parse_label_alone(t_player *player, char **tab_label)
{
	do_thing_ope(player, NULL, tab_label[0]);
}

static void		parse_action_alone(t_player *player, char *line)
{
	do_thing_ope(player, line, NULL);
}

static void		parse_label_and_action(char **tab_label, t_player *player,
		char *line)
{
	if (ft_strcchr(tab_label[0], ' ') == TRUE)
	{
		parse_action_alone(player, line);
	}
	else
	{
		do_thing_ope(player, tab_label[1], tab_label[0]);
	}
}

void			parse_content_norm(t_player *player, char **tab_label, \
					char *line)
{
	if (ft_tab_len(tab_label) == 2 && \
		tab_label[0][ft_strlen(tab_label[0]) - 1] != DIRECT_CHAR &&
		is_only_compose(tab_label[1], ' ') == FALSE)
		parse_label_and_action(tab_label, player, line);
	else if (ft_tab_len(tab_label) == 2 &&
				ft_strncchr(tab_label[0], ' ') == 0 &&
				is_only_compose(tab_label[1], ' ') == TRUE)
		parse_label_alone(player, tab_label);
	else if (ft_tab_len(tab_label) == 1 || ft_tab_len(tab_label) == 2)
		parse_action_alone(player, line);
	else
		error_exit(1, "Syntax error");
}
