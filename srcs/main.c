#include "asm.h"

BOOL check_validity(char *path)
{
	size_t len;

	len = ft_strlen(path);
	if (path[len - 1] != 's' || path[len - 2] != '.')
		return (FALSE);
	return (TRUE);
}

int		open_src_file(char *path)
{
	int fd;

	if (check_validity(path) == FALSE)
		error_exit(1, "Bad file given");
	fd = open(path, O_RDONLY);
	if (fd == -1)
		error_exit(1, "Can't open this file");
	return (fd);
}

int		open_output_file(char *path)
{
	char *output_path;

	path[ft_strlen(path) - 2] = '\0';
	output_path = ft_strnew(ft_strlen(path) + 4);
	ft_strcat(output_path, path);
	ft_strcat(output_path, ".cor");
	ft_printf("Output : %s\n", output_path);
	return (open(output_path, O_WRONLY | O_CREAT | O_TRUNC, 777));
}

int main(int argc, char **argv)
{
	int fd;
	int output_fd;
	char *path;
	t_header header;

	if (argc == 1)
		error_exit(1, "No file to parse");
	if (argc > 2)
		error_exit(1, "Too many files to parse");
	path = ft_strdup(argv[1]);
	fd = open_src_file(path);
	header = parse_header(fd);
	print_header(&header);
	output_fd = open_output_file(path);
	header.size = 5;
	saved_header(output_fd, &header);
	close(output_fd);
	return (0);
}
