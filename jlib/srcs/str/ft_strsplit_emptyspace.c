/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 12:44:17 by jrouchon          #+#    #+#             */
/*   Updated: 2019/01/31 00:28:02 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jlib.h"

static int	ft_count_str(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			count++;
		i++;
	}
	if (s[0] != c)
		count++;
	return (count);
}

static int	ft_str_len(char *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i + len] && s[i + len] != c)
	{
		len++;
	}
	return (len);
}

static char	**ft_tab(char *s, char c)
{
	char	**tab;
	int		count;
	int		i;

	if (!s)
		return (NULL);
	count = ft_count_str((char *)s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * (count + 1))))
		return (NULL);
	i = 0;
	while (i <= count)
	{
		tab[i] = NULL;
		i++;
	}
	return (tab);
}

static char	*tmp_funct(int *i, int *j, char c, char *s)
{
	char	*result;
	int		len;

	len = ft_str_len(s, c, *i);
	if (!(result = ft_strnew(len + 1)))
		return (NULL);
	ft_strncpy(result, (char*)(s + *i), len);
	*i = *i + len;
	(*j)++;
	return (result);
}

char		**ft_strsplit_emptyspace(char *s, char c)
{
	char	**tab;
	int		i;
	int		j;

	if (s == NULL)
		return (NULL);
	if (!(tab = ft_tab((char *)s, c)))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
			tab[j] = tmp_funct(&i, &j, c, s);
		else if (s[i] == c && s[i + 1] == c)
		{
			if (!(tab[j] = ft_strnew(0)))
				return (NULL);
			j++;
			i++;
		}
		else
			i++;
	}
	return (tab);
}
