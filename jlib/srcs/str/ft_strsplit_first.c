#include "jlib.h"

char** ft_strsplit_first(char* s, char c)
{
	char** tab;
	size_t i;

	if (ft_strcchr(s, c) == FALSE)
	{
		tab = ft_tab_new(2);
		tab[0] = ft_strdup(s);
		tab[1] = NULL;
	}
	else
	{
		tab = ft_tab_new(3);
		i = 0;
		while (s[i] != c)
			i++;
		tab[0] = ft_strsub(s, 0, i);
		tab[1] = ft_strsub(s, i + 1, ft_strlen(s) - i);
		tab[2] = NULL;
	}
	return (tab);
}