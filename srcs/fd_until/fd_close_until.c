/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_close_until.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 16:20:59 by caugier           #+#    #+#             */
/*   Updated: 2020/12/31 19:36:52 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fd_until_int.h"

static void	lst_clear(t_list *list)
{
	if (list == NULL)
		return ;
	lst_clear(list->next);
	gc_free(list->content);
	gc_free(list);
}

static t_list	*list_del_state(t_list *lst, int fd)
{
	t_list	*ret;

	if (lst == NULL)
		return (NULL);
	if (((t_map *)lst->content)->fd == fd)
	{
		ret = lst->next;
		lst_clear(((t_map *)lst->content)->state->list);
		gc_free(((t_map *)lst->content)->state);
		gc_free(lst->content);
		gc_free(lst);
		return (ret);
	}
	lst->next = list_del_state(lst->next, fd);
	return (lst);
}

void	fd_close_until(int fd)
{
	g_state_list = list_del_state(g_state_list, fd);
}
