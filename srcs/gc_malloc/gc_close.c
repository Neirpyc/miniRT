/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 22:58:32 by caugier           #+#    #+#             */
/*   Updated: 2020/12/31 16:32:33 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gc_malloc_int.h"
#include <unistd.h>

static void	*gc_close_int(int fd, t_list *lst, int *res)
{
	void	*ret;

	if (lst == NULL)
		return (NULL);
	if ((int)(unsigned long long)lst->content == fd)
	{
		*res = close(fd);
		ret = lst->next;
		park(lst);
		if (ret == NULL)
			return ((void *) 1);
		return (ret);
	}
	ret = gc_close_int(fd, lst->next, res);
	if (ret == NULL)
		return (NULL);
	if (ret == (void *) 1)
		ret = NULL;
	lst->next = ret;
	return (lst);
}

void	gc_close(int fd)
{
	void	*ret;
	int		res;

	ret = gc_close_int(fd, g_files, &res);
	if (ret == NULL)
	{
		ft_put_strerror(ERRCODE_ILLEGAL_CLOSE);
		gc_exit(-1);
	}
	if (res < 0)
	{
		ft_put_strerrno();
		gc_exit(-1);
	}
	if (ret == (void *) 1)
		ret = NULL;
	g_files = ret;
}
