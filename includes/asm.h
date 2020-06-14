#ifndef ASM_H
# define ASM_H

# include "jlib.h"
# include "asm_op.h"
# include "asm_header.h"

t_header		*parse_header(int fd);
BOOL			parse_content(t_player *player, int input_fd);
void			call_free_operation(void *ptr);
void			call_free_label(void *ptr);
void			print_header(t_header *header);
void			print_binary_header(t_header *header);
void			save_header(int fd, t_header *header);
t_label			*parse_label(char *content, t_operation *ope);
t_label			*find_label(char *name, t_list *label_list);
BOOL			parse_label_name(t_list *ope_list, t_list *label_list);
PARAM_TYPE		check_type_param(char *param);
t_action_param	parse_parameter(t_base_op *action, char *content,
						int tok_index);
char			**parse_tab_param(char **tab);
t_base_op		*find_action_in_tab(char *name);
t_action_param	parse_action_else(char **tab_action, char **tab_param,
						t_base_op *action);
t_operation		*parse_action(char **tab_label, int index);
size_t			parse_octal_encoding(t_operation *ope);
void			parse_operation_size(t_operation *ope);
void			set_encode_info(char *encode, size_t delta, char encode_info);
void			tmp_funct_reg(char *encode, size_t delta, size_t *result);
void			tmp_funct_dir(char *encode, size_t delta, size_t *result,
						BOOL octal);
void			tmp_funct_ind(char *encode, size_t delta, size_t *result);
void			tmp_funct_other(char *encode, size_t delta, size_t *result);

#endif
