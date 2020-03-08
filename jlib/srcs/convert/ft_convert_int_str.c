#include "jlib.h"

char *convert_int_str(long long value, size_t len)
{
	size_t i;
	char *result;

	result = ft_strnew(len);
	i = 0;
	while (i < len)
	{
		result[i] = ((char *)(&(value)))[len - i - 1];
		i++;
	}
	result[i] = '\0';
	return (result);
}

void write_int(long long value, size_t len)
{
	size_t i;
	char *tmp;

	tmp = convert_int_str(value, len);
	i = 0;
	while (i < len)
	{
		ft_printf("%c", tmp[i]);
		i++;
	}
	free(tmp);
}
