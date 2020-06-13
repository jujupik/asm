/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 13:40:02 by jrouchon          #+#    #+#             */
/*   Updated: 2019/11/01 13:40:04 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jlib.h"

size_t		ft_tab_len(char **tab)
{
	size_t		i;

	if (tab == NULL)
		return (0);
	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}

char		**ft_tab_new(size_t len)
{
	size_t	i;
	char	**result;

	result = (char **)malloc(sizeof(char *) * (len + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		result[i] = NULL;
		i++;
	}
	return (result);
}

char		**ft_tabdup(char **tab)
{
	size_t	i;
	size_t	len;
	char	**result;

	len = ft_tab_len(tab);
	result = ft_tab_new(len);
	i = 0;
	while (tab[i] != NULL)
	{
		result[i] = ft_strdup(tab[i]);
		i++;
	}
	return (result);
}
