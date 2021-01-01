/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_read_until.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 16:29:39 by caugier           #+#    #+#             */
/*   Updated: 2020/12/31 19:34:48 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fd_until_int.h"

static ssize_t	state_seek_int(t_state *state, int sep, t_list *list,
	ssize_t pos)
{
	while (list != NULL && pos < 0)
	{
		if (pos == -2 && state->eof_reached == 1)
			pos = ((t_slice *)list->content)->len;
		if (pos >= 0)
			break ;
		list = list->next;
		if (list == NULL)
			break ;
		state->previous.place++;
		state->previous.position = ((t_slice *)list->content)->len;
		pos = slice_index((t_slice *)list->content, 0, sep);
	}
	return (pos);
}

static int	state_seek(t_state *state, int sep)
{
	t_list	*list;
	ssize_t	pos;

	if ((unsigned char)state->previous.chr != (unsigned char)sep)
	{
		state->previous.position = 0;
		state->previous.place = 0;
		state->previous.chr = sep;
	}
	list = list_get_n(state->list, state->previous.place);
	if (list == NULL)
		return (-2);
	pos = slice_index((t_slice *)list->content, state->previous.position, sep);
	pos = state_seek_int(state, sep, list, pos);
	if (pos >= 0)
	{
		state->previous.position = pos;
		return (1);
	}
	return (-2);
}

ssize_t	fd_read_until(int fd, char **bin, int sep)
{
	t_state	*state;
	ssize_t	ret;

	state = get_state(fd);
	if (state == NULL)
		return (-2);
	if (state->eof_reached == 2)
	{
		fd_close_until(fd);
		return (-1);
	}
	while (state_seek(state, sep) < 0)
	{
		ret = slice_list_grow(state, fd);
		if (ret < -1)
			return (ret);
	}
	ret = state_pop(state, bin);
	if (*bin == NULL)
		fd_close_until(fd);
	if (*bin == NULL)
		return (-2);
	if (state->eof_reached == 1 && state->list == NULL)
		state->eof_reached = 2;
	return (ret);
}
