/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_header.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 19:42:42 by user42            #+#    #+#             */
/*   Updated: 2020/06/15 19:42:44 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_HEADER_H
# define ASM_HEADER_H

# include "asm_op.h"

typedef struct		s_header
{
	size_t			magic_num;
	char			name[PROG_NAME_LENGTH];
	char			comment[COMMENT_LENGTH];
	int				size;
}					t_header;

t_header			create_header(char *p_name, char *p_comment, size_t p_size);
t_header			*malloc_header(char *p_name, char *p_comment,
						size_t p_size);
void				destroy_header(t_header to_destroy);
void				free_header(t_header *to_free);
void				print_header(t_header *header);
void				print_binary_header(t_header *header);
void				save_header(int fd, t_header *header);

typedef struct		s_action_param
{
	char			type;
	int				value;
	char			*label_name;
}					t_action_param;

t_action_param		create_action_param(PARAM_TYPE p_type, int p_value,
						char *p_label_name);
t_action_param		*malloc_action_param(PARAM_TYPE p_type, int p_value,
						char *p_label_name);
void				destroy_action_param(t_action_param to_destroy);
void				free_action_param(t_action_param *to_free);

typedef struct		s_operation
{
	t_base_op		*action;
	char			encodage;
	t_action_param	params[3];
	int				pos;
	int				size;
}					t_operation;

t_operation			create_operation(t_base_op *p_action,
						t_action_param *p_param);
t_operation			*malloc_operation(t_base_op *p_action,
						t_action_param *p_param);
void				destroy_operation(t_operation to_destroy);
void				free_operation(t_operation *to_free);
void				print_operation(t_operation *to_print);
void				print_binary_operation(t_operation *to_print);
void				save_operation(int fd, t_operation *ope);

typedef struct		s_label
{
	t_operation		*ope;
	char			*name;
}					t_label;

t_label				create_label(t_operation *p_ope, char *p_name);
t_label				*malloc_label(t_operation *p_ope, char *p_name);
void				destroy_label(t_label to_destroy);
void				free_label(t_label *to_free);
void				print_label(t_label *to_print);

typedef struct		s_player
{
	t_header		*header;
	t_list			*ope_list;
	t_list			*label_list;
}					t_player;

t_player			create_player();
t_player			*malloc_player();
void				destroy_player(t_player to_destroy);
void				free_player(t_player *to_free);
void				print_player(t_player *player);
void				print_binary_player(t_player *player);
void				save_player(int output_fd, t_player *player);

#endif
