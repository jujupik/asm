/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jlib_list.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 17:40:15 by jrouchon          #+#    #+#             */
/*   Updated: 2020/06/16 01:02:52 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JLIB_LIST_H
# define JLIB_LIST_H

typedef void		(*t_destroy_funct)(void *to_destroy);

typedef struct		s_list
{
	void			***content;
	size_t			size;
	size_t			max_size;
	size_t			nb_line;
	size_t			push_size;
}					t_list;

t_list				create_list(size_t p_push_size);
t_list				*malloc_list(size_t p_push_size);
void				destroy_list(t_list to_destroy, t_destroy_funct funct);
void				free_list(t_list *to_free, t_destroy_funct funct);
t_vector2			list_calc_index_coord(t_list *list, size_t index);
void				list_push_back(t_list *list, void *to_add);
void				*list_at(t_list *list, size_t index);
void				**list_get(t_list *list, size_t index);

typedef struct		s_chain
{
	void			*content;
	struct s_chain	*next;
	struct s_chain	*previous;
}					t_chain;

t_chain				create_chain(void *p_content);
t_chain				*malloc_chain(void *p_content);
void				destroy_chain(t_chain to_destroy, t_destroy_funct funct);
void				free_chain(t_chain *to_free, t_destroy_funct funct);
void				chain_push_back(t_chain *chain, void *to_add);
void				chain_push_front(t_chain **chain, void *to_add);
void				chain_remove(t_chain *to_remove);
void				chain_pop_back(t_chain *chain, size_t index);
void				chain_erase(t_chain **chain, void *elem);
t_chain				*chain_search(t_chain *chain, void *elem);
void				*chain_at(t_chain *chain, size_t index);
void				**chain_get(t_chain *chain, size_t index);
size_t				chain_len(t_chain *chain);

#endif
