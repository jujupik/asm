#include "asm.h"

BOOL	check_validity(char *path)
{
	size_t	len;

	len = ft_strlen(path);
	if (path[len - 1] != 's' || path[len - 2] != '.')
		return (FALSE);
	return (TRUE);
}

int		open_src_file(char *path)
{
	int	fd;

	if (check_validity(path) == FALSE)
		error_exit(1, "Bad file given");
	fd = open_fd(path, O_RDONLY);
	if (fd == -1)
		error_exit(1, "Can't open this file");
	return (fd);
}

int		open_output_file(char *path)
{
	char	*output_path;

	path[ft_strlen(path) - 2] = '\0';
	output_path = ft_strnew(ft_strlen(path) + 4);
	ft_strcat(output_path, path);
	ft_strcat(output_path, ".cor");
	if (check_file_exist(output_path) == FILE_EXIST)
		remove_file(output_path);
	return (open_fd(output_path, O_WRONLY | O_CREAT | O_TRUNC));
}

int		main(int argc, char **argv)
{
	int			input_fd;
	int			output_fd;
	char		*path;
	t_player	*player;

	input_fd = 0;
	output_fd = 0;
	if (argc == 1)
		error_exit(1, "No file to parse");
	if (argc > 2)
		error_exit(1, "Too many files to parse");
	path = ft_strdup(argv[1]);
	input_fd = open_src_file(path);
	player = malloc_player();
	player->header = parse_header(input_fd);
	if (parse_content(player, input_fd) == FALSE)
		error_exit(1, "Error in file : Label inexistant");
	output_fd = open_output_file(path);
	save_player(output_fd, player);
	close_fd(output_fd);
	close_fd(input_fd);
	return (0);
}
