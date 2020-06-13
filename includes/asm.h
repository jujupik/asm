#ifndef ASM_H
#define ASM_H

#include "jlib.h"
#include "asm_op.h"
#include "asm_header.h"

t_header* parse_header(int fd);
BOOL parse_content(t_player* player, int input_fd);
void		call_free_operation(void *ptr);
void		call_free_label(void *ptr);

size_t	parse_octal_encoding(t_operation *ope);
void			parse_operation_size(t_operation *ope);
void	set_encode_info(char *encode, size_t delta, char encode_info);
void	tmp_funct_reg(char *encode, size_t delta, size_t *result);
void	tmp_funct_dir(char *encode, size_t delta, size_t *result, BOOL octal);
void	tmp_funct_ind(char *encode, size_t delta, size_t *result);
void	tmp_funct_other(char *encode, size_t delta, size_t *result);

#endif
