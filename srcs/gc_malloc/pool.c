/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 15:59:26 by caugier           #+#    #+#             */
/*   Updated: 2020/12/31 16:38:26 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gc_malloc_int.h"

t_list	*g_list_pool = NULL;
t_list	*g_pointers = NULL;
t_list	*g_blocks[BLOCK_COUNT];

static unsigned long long int	get_block_id(unsigned long long int i)
{
	while (g_blocks[i] != NULL)
	{
		i++;
		if (i == BLOCK_COUNT)
		{
			ft_put_strerror(ERRCODE_TOO_MANY_PTRS);
			gc_exit(-1);
		}
	}
	return (i);
}

static void	*new_lst(void)
{
	unsigned long long	i;
	unsigned long long	n;
	t_list				*lst;

	i = 0;
	i = get_block_id(i);
	n = (1u << i);
	g_blocks[i] = malloc(sizeof(t_list) * n);
	if (g_blocks[i] == NULL)
	{
		ft_put_strerror(ERRCODE_NO_MEM);
		gc_exit(-1);
	}
	lst = &g_blocks[i][0];
	if (n == 1)
		return (lst);
	while (--n > 1)
	{
		lst->next = &lst[1];
		lst = lst->next;
	}
	lst->next = NULL;
	g_list_pool = &g_blocks[i][0];
	return (&lst[1]);
}

void	park(t_list *ptr)
{
	list_push_front(&g_list_pool, ptr);
}

t_list	*unpark(void)
{
	t_list	*ret;

	ret = list_pop(&g_list_pool);
	if (ret == NULL)
		ret = new_lst();
	return (ret);
}
