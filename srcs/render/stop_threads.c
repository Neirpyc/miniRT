/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 13:09:49 by caugier           #+#    #+#             */
/*   Updated: 2021/01/02 15:46:02 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_int.h"
#include "../gc_malloc/gc_malloc.h"

void	stop_threads(void *param)
{
	int	i;

	g_camera = NULL;
	pthread_barrier_wait(&g_render_start_barrier);
	i = 0;
	while (i < (int)param)
	{
		pthread_join(g_threads[i], NULL);
		i++;
	}
	gc_free(g_threads);
}
