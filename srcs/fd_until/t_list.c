/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_list.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 16:44:44 by caugier           #+#    #+#             */
/*   Updated: 2020/12/31 19:36:30 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "fd_until_int.h"

t_list	*list_get_n(t_list *list, size_t n)
{
	if (n == 0 || list == NULL)
		return (list);
	return (list_get_n(list->next, n - 1));
}

static t_list	*new_list_with_slice(size_t buffer_size)
{
	t_list	*list;

	list = gc_malloc(sizeof(t_list));
	if (list == NULL)
		return (NULL);
	list->content = new_slice(buffer_size);
	list->next = NULL;
	if (list->content == NULL)
	{
		gc_free(list);
		return (NULL);
	}
	return (list);
}

static int	slice_list_grow_int(t_list *list, t_slice **slice)
{
	while ((*slice)->cap <= (*slice)->len + (*slice)->begin_pos)
	{
		if (list->next == NULL)
		{
			list->next = new_list_with_slice(BUFFER_SIZE);
			if (list->next == NULL)
				return (-2);
			*slice = (t_slice *)list->next->content;
			break ;
		}
		list = list->next;
		if (list == NULL)
			break ;
		*slice = (t_slice *)list->content;
	}
	return (0);
}

int	slice_list_grow(t_state *state, int fd)
{
	t_slice	*slice;
	t_list	*list;
	ssize_t	ret;

	if (state->list == NULL)
	{
		state->list = new_list_with_slice(BUFFER_SIZE);
		if (state->list == NULL)
			return (-2);
	}
	list = state->list;
	slice = (t_slice *)state->list->content;
	if (slice_list_grow_int(list, &slice) == -2)
		return (-2);
	ret = read(fd, (char *)slice->begin_ptr + slice->len + slice->begin_pos,
			slice->cap - slice->begin_pos - slice->len);
	if (ret == 0)
	{
		state->eof_reached = 1;
		return (-1);
	}
	else if (ret < 0)
		return (-2);
	slice->len += ret;
	return (ret);
}
