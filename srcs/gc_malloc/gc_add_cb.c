/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_add_cb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 23:17:37 by caugier           #+#    #+#             */
/*   Updated: 2020/12/10 20:09:01 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gc_malloc_int.h"

t_list	*g_callbacks = NULL;

void	gc_add_cb(void (*cb)(void *), void *param)
{
	t_list		*lst;
	t_callback	*cb_struct;

	lst = unpark();
	lst->next = NULL;
	cb_struct = malloc(sizeof(t_callback));
	if (cb_struct == NULL)
	{
		ft_put_strerror(ERRCODE_NO_MEM);
		gc_exit(-1);
	}
	cb_struct->func = cb;
	cb_struct->param = param;
	lst->content = cb_struct;
	list_push_front(&g_callbacks, lst);
}
