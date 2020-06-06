#include "jlib.h"


FILE_STATE check_file_exist(char* path)
{
	int access_value;

	access_value = _access(path, 0);
	if (access_value == 0)
		return (FILE_EXIST);
	else if (access_value == ENOENT)
		return (FILE_NO_EXIST);
	else
		return (FILE_ERROR);
}

void remove_file(char* path)
{
	int error_type;

	error_type = remove(path);
	if (error_type == EACCES)
		error_exit(1, "Access denied: the file's permission setting does not allow specified access.");
	else if (error_type == ENOENT)
		error_exit(1, "File name or path not found.");
	else if (error_type == EINVAL)
		error_exit(1, "Invalid parameter.");
}