/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 22:13:26 by caugier           #+#    #+#             */
/*   Updated: 2020/12/06 22:30:08 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTS_H
# define LISTS_H

# include <stdlib.h>

typedef struct s_list {
	void			*content;
	struct s_list	*next;
}					t_list;

t_list				*list_pop(t_list **list);
void				list_push_front(t_list **list, t_list *elem);
t_list				*list_new(void *content);
void				list_clear(t_list *list);
void				list_free(t_list *list);
size_t				list_size(t_list *list);

#endif
