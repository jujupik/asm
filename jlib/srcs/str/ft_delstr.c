#include "jlib.h"

void	ft_delchar(char **str, char *to_remove)
{
	size_t i;
	size_t j;
	char *result;
	char *tmp;

	if (str == NULL || *str == NULL)
		return ;
	tmp = *str;
	i = 0;
	j = 0;
	result = ft_strnew(ft_strlen(tmp));
	while (tmp[i] != '\0')
	{
		if (ft_strcchr(to_remove, tmp[i]) == FALSE)
		{
			result[j] = tmp[i];
			j++;
		}
		i++;
	}
	result[j] = '\0';
	free(*str);
	*str = result;
}
