/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 15:25:45 by caugier           #+#    #+#             */
/*   Updated: 2020/12/31 16:36:05 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gc_malloc_int.h"

static void	*ft_free_int(void *ptr, t_list *lst)
{
	void	*ret;

	if (lst == NULL)
		return (NULL);
	if (lst->content == ptr)
	{
		free(ptr);
		ret = lst->next;
		park(lst);
		if (ret == NULL)
			return ((void *) 1);
		return (ret);
	}
	ret = ft_free_int(ptr, lst->next);
	if (ret == NULL)
		return (NULL);
	if (ret == (void *) 1)
		ret = NULL;
	lst->next = ret;
	return (lst);
}

void	gc_free(void *ptr)
{
	void	*ret;

	if (ptr == NULL)
		return ;
	ret = ft_free_int(ptr, g_pointers);
	if (ret == NULL)
	{
		ft_put_strerror(ERRCODE_ILLEGAL_FREE);
		gc_exit(-1);
	}
	if (ret == (void *) 1)
		ret = NULL;
	g_pointers = ret;
}
