/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 17:24:12 by caugier           #+#    #+#             */
/*   Updated: 2020/12/31 19:36:08 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fd_until_int.h"

static ssize_t	state_pop_measure(t_state *state)
{
	t_list	*list;
	ssize_t	size;
	size_t	i;

	list = state->list;
	size = 0;
	i = 0;
	while (list != NULL)
	{
		if (i == state->previous.place)
			size += state->previous.position;
		else
			size += ((t_slice *)list->content)->len;
		i++;
		list = list->next;
	}
	return (size);
}

static char	*ft_memcpy(char *dest, char *src, size_t n)
{
	while (n-- > 0)
		*(dest++) = *(src++);
	return (dest);
}

static void	state_pop_int(char *buf, t_list *list, t_state *state, size_t i)
{
	size_t	old;
	t_slice	*slice;

	slice = ((t_slice *)list->content);
	ft_memcpy(buf, slice->begin_ptr + slice->begin_pos,
		state->previous.position);
	slice->begin_pos += state->previous.position + 1;
	old = slice->len;
	slice->len -= state->previous.position + 1;
	state->previous.position = 0;
	state->previous.place = 0;
	state->list = list;
	if (old < slice->len)
	{
		if (list->next != NULL)
			state_pop_cpy(NULL, list->next, state, i + 1);
		gc_free(((t_slice *)state->list->content)->begin_ptr);
		gc_free(state->list->content);
		gc_free(state->list);
		state->list = NULL;
	}
}

void	state_pop_cpy(char *buf, t_list *list, t_state *state, size_t i)
{
	t_slice	*slice;
	t_list	*next;

	slice = ((t_slice *)list->content);
	if (i > state->previous.place)
	{
		gc_free(slice->begin_ptr);
		gc_free(slice);
		gc_free(list);
	}
	else if (i == state->previous.place)
	{
		state_pop_int(buf, list, state, i);
	}
	else
	{
		buf = ft_memcpy(buf, slice->begin_ptr + slice->begin_pos,
				slice->len);
		next = list->next;
		gc_free(slice->begin_ptr);
		gc_free(slice);
		gc_free(list);
		state_pop_cpy(buf, next, state, i + 1);
	}
}

ssize_t	state_pop(t_state *state, char **bin)
{
	ssize_t	size;

	size = state_pop_measure(state);
	*bin = gc_malloc(size + 1);
	if (*bin == NULL)
		return (-1);
	state_pop_cpy(*bin, state->list, state, 0);
	(*bin)[size] = '\0';
	return (size);
}
