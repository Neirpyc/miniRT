/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_malloc_int.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 15:27:10 by caugier           #+#    #+#             */
/*   Updated: 2020/12/31 16:37:28 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GC_MALLOC_INT_H
# define GC_MALLOC_INT_H

# include "gc_malloc.h"
# include "../lists/lists.h"
# include "../errors/errors.h"

# define BLOCK_COUNT 64

typedef struct s_callback {
	void	(*func)(void *param);
	void	*param;
}				t_callback;

extern t_list	*g_list_pool;
extern t_list	*g_pointers;
extern t_list	*g_files;
extern t_list	*g_callbacks;
extern t_list	*g_blocks[BLOCK_COUNT];

void			park(t_list *ptr);
t_list			*unpark(void);

#endif
