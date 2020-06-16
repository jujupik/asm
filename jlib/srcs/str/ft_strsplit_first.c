/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_first.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 19:46:17 by user42            #+#    #+#             */
/*   Updated: 2020/06/16 01:18:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jlib.h"

char	**ft_strsplit_first(char *s, char c)
{
	char	**tab;
	size_t	i;
	BOOL	found;

	if (ft_strcchr(s, c) == FALSE)
	{
		tab = ft_tab_new(2);
		tab[0] = ft_strdup(s);
	}
	else
	{
		tab = ft_tab_new(3);
		i = 0;
		found = FALSE;
		while ((s[i] != '\0' && s[i] != c) || found == FALSE)
		{
			if (s[i] != c)
				found = TRUE;
			i++;
		}
		tab[0] = ft_strsub(s, 0, i);
		tab[1] = ft_strsub(s, i + 1, ft_strlen(s) - i);
	}
	return (tab);
}
