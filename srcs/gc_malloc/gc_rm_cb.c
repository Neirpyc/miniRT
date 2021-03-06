/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_rm_cb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 23:17:28 by caugier           #+#    #+#             */
/*   Updated: 2020/12/31 16:39:22 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gc_malloc_int.h"

static void	*gc_rm_cb_int(void (*cb)(void *), void *param, t_list *lst)
{
	void	*ret;

	if (lst == NULL)
		return (NULL);
	if (((t_callback *)lst->content)->func == cb
		&& ((t_callback *)lst->content)->param == param)
	{
		ret = lst->next;
		free(lst->content);
		park(lst);
		if (ret == NULL)
			return ((void *) 1);
		return (ret);
	}
	ret = gc_rm_cb_int(cb, param, lst->next);
	if (ret == NULL)
		return (NULL);
	if (ret == (void *) 1)
		ret = NULL;
	lst->next = ret;
	return (lst);
}

void	gc_rm_cb(void (*cb)(void *), void *param)
{
	void	*ret;

	if (cb == NULL)
		return ;
	ret = gc_rm_cb_int(cb, param, g_callbacks);
	if (ret == NULL)
	{
		ft_put_strerror(ERRCODE_ILLEGAL_CBRM);
		gc_exit(-1);
	}
	if (ret == (void *) 1)
		ret = NULL;
	g_callbacks = ret;
}
