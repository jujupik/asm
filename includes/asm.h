#ifndef ASM_H
#define ASM_H

#include "jlib.h"
#include "asm_op.h"
#include "asm_header.h"

t_header* parse_header(int fd);

BOOL parse_content(t_player* player, int input_fd);

#endif
