#ifndef ASM_HEADER_H
# define ASM_HEADER_H

typedef struct		s_header
{
 	size_t magic_num;
	char name[PROG_NAME_LENGTH];
	char comment[COMMENT_LENGTH];
	size_t size;
}					t_header;

t_header create_header(char *p_name, char *p_comment, size_t p_size);
t_header *malloc_header(char *p_name, char *p_comment, size_t p_size);
void destroy_header(t_header to_destroy);
void free_header(t_header *to_free);
void print_header(t_header *header);
void saved_header(int fd, t_header *header);

#endif
