/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 11:16:28 by caugier           #+#    #+#             */
/*   Updated: 2021/01/02 15:57:50 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdatomic.h>
#include "render_int.h"
#include "../raytrace/raytrace_int.h"
#include "../gc_malloc/gc_malloc.h"
#include "../errors/errors.h"

pthread_t			*g_threads = NULL;
atomic_long			g_current_point = -1;

static inline int	thread_wait(t_scene *scene)
{
	(void)scene;
	pthread_barrier_wait(&g_render_start_barrier);
	if (g_camera == NULL)
		return (-1);
	return (1);
}

static inline int	do_render_from_c(t_scene *scene, long c)
{
	long	j;

	j = 0;
	while (j < CHUNK_PX)
	{
		if (c >= scene->resolution.width * scene->resolution.height)
			return (1);
		raytrace_pixel((int)(c % (ssize_t)scene->resolution.width),
			(int)(c / (ssize_t)scene->resolution.width), scene, g_camera);
		j++;
		c++;
	}
	return (0);
}

void	*render_thread(t_scene *scene)
{
	ssize_t	c;

	while (1)
	{
		if (thread_wait(scene) < 0)
			return (NULL);
		while (1)
		{
			c = atomic_fetch_add_explicit(&g_current_point, CHUNK_PX,
					__ATOMIC_SEQ_CST);
			if (do_render_from_c(scene, c) == 1)
				break ;
		}
		pthread_barrier_wait(&g_render_stop_barrier);
	}
}

void	start_rendering_threads(int count, t_scene *scene)
{
	int	i;
	int	ret;

	if (g_threads == NULL)
	{
		pthread_barrier_init(&g_render_start_barrier, NULL, count + 1);
		pthread_barrier_init(&g_render_stop_barrier, NULL, count + 1);
		g_threads = gc_malloc(sizeof(pthread_t) * count);
		i = 0;
		while (i < count)
		{
			ret = pthread_create(&g_threads[i], NULL,
					(void *(*)(void *))render_thread, (void *)scene);
			if (ret != 0)
				gc_exit_strerror(ERRCODE_CRT_THRD, -1);
			i++;
		}
	}
}
