/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jlib_leaks.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 17:39:11 by jrouchon          #+#    #+#             */
/*   Updated: 2020/02/29 19:51:46 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JLIB_LEAKS_H
# define JLIB_LEAKS_H

extern BOOL g_debug;

typedef struct		s_address
{
	size_t			index;
	void			*ptr;
	size_t			size;
	char			**strings;
}					t_address;

t_address			create_address(size_t p_index, void *p_ptr);
t_address			*malloc_address(size_t p_index, void *p_ptr);
void				destroy_address(t_address to_destroy);
void				free_address(t_address *to_free);
void				print_address(t_address *address);
void				address_get_trace(t_address *address);

void				*malloc(size_t size);
void				free(void *to_free);
void				ft_get_leaks(char *msg);

#endif
