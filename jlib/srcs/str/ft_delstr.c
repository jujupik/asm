/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 19:45:59 by user42            #+#    #+#             */
/*   Updated: 2020/06/15 19:45:59 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jlib.h"

void	ft_delchar(char **str, char *to_remove)
{
	size_t	i;
	size_t	j;
	char	*result;
	char	*tmp;

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

void	ft_delchar_begin(char **str, char *to_remove)
{
	BOOL	find;
	size_t	i;
	size_t	j;
	char	*result;

	if (str == NULL || *str == NULL)
		return ;
	find = FALSE;
	i = 0;
	j = 0;
	result = ft_strnew(ft_strlen(*str));
	while ((*str)[i] != '\0')
	{
		if (ft_strcchr(to_remove, (*str)[i]) == FALSE || find == TRUE)
		{
			result[j] = (*str)[i];
			find = TRUE;
			j++;
		}
		i++;
	}
	result[j] = '\0';
	free(*str);
	*str = result;
}
