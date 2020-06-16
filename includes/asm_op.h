/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_op.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 19:42:50 by user42            #+#    #+#             */
/*   Updated: 2020/06/16 01:57:17 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_OP_H
# define ASM_OP_H
# define IND_SIZE				2
# define REG_SIZE				1
# define DIR_SIZE				4
# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3
# define MAX_ARGS_NUMBER		4
# define MAX_PLAYERS			4
# define MEM_SIZE				4096
# define IDX_MOD				512
# define CHAMP_MAX_SIZE			682
# define COMMENT_CHAR			'#'
# define COMMENT_CHAR2			';'
# define LABEL_CHAR				':'
# define DIRECT_CHAR			'%'
# define SEPARATOR_CHAR			','
# define LABEL_CHARS			"abcdefghijklmnopqrstuvwxyz_0123456789"
# define NAME_CMD_STRING		".name"
# define COMMENT_CMD_STRING		".comment"
# define REG_NUMBER				16
# define CYCLE_TO_DIE			1536
# define CYCLE_DELTA			50
# define NBR_LIVE				21
# define MAX_CHECKS				10
# define PARAM_TYPE char
# define T_REG					1
# define T_DIR					10
# define T_IND					12
# define T_LAB_IND				4
# define T_LAB					2
# define T_ERROR				-1
# define PROG_NAME_LENGTH		128
# define COMMENT_LENGTH			2048
# define COREWAR_EXEC_MAGIC		0xea83f3

typedef char		t_arg_type;

typedef struct		s_base_op
{
	char			*name;
	unsigned char	nb_token;
	char			availible_token[3];
	char			id;
	size_t			delay;
	char			*msg;
	BOOL			need_octal;
	BOOL			octal_size_modifier;
}					t_base_op;

#endif
