#include "jlib.h"


void ft_changechar(char *str, char *target, char c)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_strcchr(target, str[i]) == TRUE)
			str[i] = c;
		i++;
	}
}
