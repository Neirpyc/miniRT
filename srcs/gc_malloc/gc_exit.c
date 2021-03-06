/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 15:25:38 by caugier           #+#    #+#             */
/*   Updated: 2020/12/31 15:59:35 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gc_malloc_int.h"
#include <unistd.h>

static void	free_all_ptrs(t_list *lst)
{
	if (lst == NULL)
		return ;
	free(lst->content);
	free_all_ptrs(lst->next);
}

static void	close_all_fds(t_list *lst)
{
	if (lst == NULL)
		return ;
	if (close((int)(unsigned long long)lst->content) < 0)
		ft_put_strerrno();
	close_all_fds(lst->next);
}

static void	run_all_cbs(t_list *lst)
{
	if (lst == NULL)
		return ;
	((t_callback *)lst->content)->func(((t_callback *)lst->content)->param);
	free(lst->content);
	run_all_cbs(lst->next);
}

void	*gc_exit(int n)
{
	int	i;

	run_all_cbs(g_callbacks);
	free_all_ptrs(g_pointers);
	close_all_fds(g_files);
	i = 0;
	while (g_blocks[i] != NULL)
	{
		free(g_blocks[i++]);
		if (i == BLOCK_COUNT)
			break ;
	}
	exit(n);
}
