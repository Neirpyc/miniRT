/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 13:09:49 by caugier           #+#    #+#             */
/*   Updated: 2020/12/31 14:49:01 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_int.h"
#include "../gc_malloc/gc_malloc.h"

void	stop_threads(void *param)
{
	int	i;

	(void)param;
	pthread_mutex_lock(&g_start_render_mutex);
	g_camera = NULL;
	pthread_cond_broadcast(&g_start_render_cond);
	pthread_mutex_unlock(&g_start_render_mutex);
	i = 0;
	while (i < g_thread_count)
	{
		pthread_join(g_threads[i], NULL);
		i++;
	}
	gc_free(g_threads);
}
