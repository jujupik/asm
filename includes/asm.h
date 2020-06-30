/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 19:42:58 by user42            #+#    #+#             */
/*   Updated: 2020/06/30 22:01:07 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "jlib.h"
# include "asm_op.h"
# include "asm_header.h"

BOOL			free_variable(char **tab, char *tmp, char *tmp_cmd, BOOL state);
BOOL			read_variable(char **variable, int fd);
t_header		*parse_header(int fd);
BOOL			parse_content(t_player *player, int input_fd);
void			call_free_operation(void *ptr);
void			call_free_label(void *ptr);
void			print_header(t_header *header);
void			print_binary_header(t_header *header);
void			save_header(int fd, t_header *header);
t_label			*parse_label(char *content, t_operation *ope);
t_label			*find_label(char *name, t_list *label_list);
BOOL			parse_label_name(t_header *header, t_list *ope_list, \
					t_list *label_list);
PARAM_TYPE		check_type_param(char *param);
t_action_param	parse_parameter(t_base_op *action, char *content,
					int tok_index);
char			**parse_tab_param(char **tab);
t_base_op		*find_action_in_tab(char *name);
t_operation		*parse_action(char *operation_line);
size_t			parse_octal_encoding(t_operation *ope);
void			parse_operation_size(t_operation *ope);
void			set_encode_info(char *encode, size_t delta, char encode_info);
void			tmp_funct_reg(char *encode, size_t delta, size_t *result);
void			tmp_funct_dir(char *encode, size_t delta, size_t *result,
					BOOL octal);
void			tmp_funct_ind(char *encode, size_t delta, size_t *result);
void			tmp_funct_other(char *encode, size_t delta, size_t *result);
char			*param_type_str(t_arg_type type);
size_t			count_char_before(char *str, char c);
void			parse_champion_size(t_header *header, t_list *ope_list);
void			compute_line_percent(char **line);
void			parse_content_norm(t_player *player, char **tab_label, \
					char *line);
void			do_thing_ope(t_player *player, char *string_ope,
					char *string_label);
#endif
