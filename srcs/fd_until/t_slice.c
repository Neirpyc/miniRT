/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_slice.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 16:47:37 by caugier           #+#    #+#             */
/*   Updated: 2020/12/05 19:26:33 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fd_until_int.h"

ssize_t	slice_index(t_slice *slice, size_t start, int chr)
{
	unsigned char	*pos;
	ssize_t			ret;

	ret = start;
	pos = (unsigned char *)slice->begin_ptr + slice->begin_pos + start;
	while (++ret <= (ssize_t)slice->len)
	{
		if (*pos == (unsigned char)chr)
			break ;
		pos++;
	}
	if (ret > (ssize_t)slice->len)
		return (-2);
	return (ret - 1);
}

t_slice	*new_slice(size_t cap)
{
	t_slice	*ptr;

	ptr = gc_malloc(sizeof(t_slice));
	if (ptr == NULL)
		return (NULL);
	ptr->begin_ptr = gc_malloc(cap);
	if (ptr->begin_ptr == NULL)
	{
		gc_free(ptr);
		return (NULL);
	}
	ptr->begin_pos = 0;
	ptr->len = 0;
	ptr->cap = cap;
	return (ptr);
}
