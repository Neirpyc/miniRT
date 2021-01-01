/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_until_int.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 15:55:09 by caugier           #+#    #+#             */
/*   Updated: 2020/12/05 19:42:22 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FD_UNTIL_INT_H
# define FD_UNTIL_INT_H

# include "fd_until.h"
# include "../gc_malloc/gc_malloc.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8192
# endif

typedef struct s_list {
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_seek {
	int				chr;
	size_t			position;
	size_t			place;
}					t_seek;

typedef struct s_state {
	t_seek			previous;
	t_list			*list;
	int				eof_reached;
}					t_state;

typedef struct s_map {
	int				fd;
	t_state			*state;
}					t_map;

typedef struct s_slice {
	char			*begin_ptr;
	size_t			begin_pos;
	size_t			len;
	size_t			cap;
}					t_slice;

extern t_list		*g_state_list;

t_state				*get_state(int fd);
ssize_t				state_pop(t_state *state, char **bin);
void				state_pop_cpy(char *buf, t_list *list, t_state *state,
	size_t i);

t_list				*list_get_n(t_list *list, size_t n);

ssize_t				slice_index(t_slice *slice, size_t start, int chr);
t_slice				*new_slice(size_t cap);
int					slice_list_grow(t_state *state, int fd);

#endif
