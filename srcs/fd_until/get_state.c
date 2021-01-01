/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_state.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 16:01:57 by caugier           #+#    #+#             */
/*   Updated: 2020/12/05 19:40:41 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fd_until_int.h"

t_list				*g_state_list = NULL;

static t_state	*find_state(t_list *lst, int fd)
{
	if (lst == NULL)
		return (NULL);
	if (((t_map *)lst->content)->fd == fd)
		return (((t_map *)lst->content)->state);
	return (find_state(lst->next, fd));
}

static t_list	*new_state(void)
{
	t_list	*lst;

	lst = gc_malloc(sizeof(*lst));
	if (lst == NULL)
		return (NULL);
	lst->content = gc_malloc(sizeof(t_map));
	if (lst->content == NULL)
	{
		gc_free(lst);
		return (NULL);
	}
	((t_map *)lst->content)->state = gc_malloc(sizeof(t_state));
	if (((t_map *)lst->content)->state == NULL)
	{
		gc_free(lst->content);
		gc_free(lst);
		return (NULL);
	}
	return (lst);
}

t_state	*get_state(int fd)
{
	t_state	*state;
	t_list	*list;

	state = find_state(g_state_list, fd);
	if (state != NULL)
		return (state);
	list = new_state();
	if (list == NULL)
		return (NULL);
	((t_map *)list->content)->fd = fd;
	((t_map *)list->content)->state->list = NULL;
	((t_map *)list->content)->state->eof_reached = 0;
	((t_map *)list->content)->state->previous.place = 0;
	((t_map *)list->content)->state->previous.position = 0;
	((t_map *)list->content)->state->previous.chr = 0;
	list->next = g_state_list;
	g_state_list = list;
	return (((t_map *)list->content)->state);
}
