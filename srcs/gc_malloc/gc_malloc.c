/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 15:25:47 by caugier           #+#    #+#             */
/*   Updated: 2020/12/06 17:18:38 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gc_malloc_int.h"

void	*gc_malloc(size_t n)
{
	void	*ptr;
	t_list	*lst;

	lst = unpark();
	ptr = malloc(n);
	if (ptr == NULL)
	{
		ft_put_strerror(ERRCODE_NO_MEM);
		gc_exit(-1);
	}
	lst->content = ptr;
	lst->next = NULL;
	list_push_front(&g_pointers, lst);
	return (ptr);
}
