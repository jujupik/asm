#include "asm.h"

t_header	create_header(char *p_name, char *p_comment, size_t p_size)
{
	t_header	result;

	result.magic_num = COREWAR_EXEC_MAGIC;
	ft_str_fill(result.name, '\0', PROG_NAME_LENGTH);
	ft_str_fill(result.comment, '\0', COMMENT_LENGTH);
	if (ft_strlen(p_name) >= PROG_NAME_LENGTH)
		error_exit(1, "Name too long");
	if (ft_strlen(p_comment) >= COMMENT_LENGTH)
		error_exit(1, "Comment too long");
	ft_strcpy(result.name, p_name);
	ft_strcpy(result.comment, p_comment);
	result.size = p_size;
	return (result);
}

t_header	*malloc_header(char *p_name, char *p_comment, size_t p_size)
{
	t_header	*result;

	result = (t_header	*)malloc(sizeof(t_header));
	if (result == NULL)
		return (NULL);
	*result = create_header(p_name, p_comment, p_size);
	return (result);
}

void		destroy_header(t_header to_destroy)
{
	(void)to_destroy;
	ft_printf("To do : destroy_header");
}

void		free_header(t_header *to_free)
{
	destroy_header(*to_free);
	free(to_free);
}

void		print_header(t_header *header)
{
	ft_printf("Magic : 0x%X\nSize : %u\nName : %s\nComment : %s\n",
		header->magic_num, header->size, header->name, header->comment);
}

static void	print_binary_parameter(char *data, size_t len)
{
	size_t	i;
	size_t	size;

	size = ft_strlen(data);
	i = 0;
	while (i < len)
	{
		if (i <= size)
			ft_printf("%hhx", data[i]);
		else
			ft_printf("%hhx", '\0');
		i++;
	}
}

void		print_binary_header(t_header *header)
{
	ft_printf("%x", header->magic_num);
	print_binary_parameter(header->name, PROG_NAME_LENGTH);
	ft_printf("%lx", header->size);
	print_binary_parameter(header->comment, COMMENT_LENGTH);
	ft_printf("%lx", 0);
}

static void	print_parameter(int fd, char *data, size_t len)
{
	size_t	i;

	ft_fprintf(fd, "%s", data);
	i = ft_strlen(data);
	while (i < len)
	{
		ft_fprintf(fd, "%c", '\0');
		i++;
	}
}

void		save_header(int fd, t_header *header)
{
	ft_fprintf(fd, "%^d", header->magic_num);
	print_parameter(fd, header->name, PROG_NAME_LENGTH);
	ft_fprintf(fd, "%^ld", header->size);
	print_parameter(fd, header->comment, COMMENT_LENGTH);
	ft_fprintf(fd, "%^d", 0);
}
