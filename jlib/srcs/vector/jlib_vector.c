/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jlib_vector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:49:10 by jrouchon          #+#    #+#             */
/*   Updated: 2020/01/24 16:49:24 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jlib.h"

t_vector2	create_vector2(int p_x, int p_y)
{
	t_vector2 result;

	result.x = p_x;
	result.y = p_y;
	return (result);
}

t_vector2	*malloc_vector2(int p_x, int p_y)
{
	t_vector2	*result;

	result = (t_vector2 *)malloc(sizeof(t_vector2));
	if (result == NULL)
		error_exit(111, "Can't malloc a t_vector2");
	*result = create_vector2(p_x, p_y);
	return (result);
}

void		swap_t_vector2(t_vector2 *a, t_vector2 *b)
{
	ft_swap_int(&(a->x), &(b->x));
	ft_swap_int(&(a->y), &(b->y));
}

BOOL		is_t_vector2_equal(t_vector2 a, t_vector2 b)
{
	if (a.x == b.x && a.y == b.y)
		return (TRUE);
	else
		return (FALSE);
}

float		distance_vector2(t_vector2 a, t_vector2 b)
{
	return (sqrt(pow((double)(b.x - a.x), 2) + pow((double)(b.y - a.y), 2)));
}
