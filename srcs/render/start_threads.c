/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 11:16:28 by caugier           #+#    #+#             */
/*   Updated: 2020/12/31 17:43:26 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdatomic.h>
#include "render_int.h"
#include "../raytrace/raytrace_int.h"
#include "../gc_malloc/gc_malloc.h"
#include "../errors/errors.h"

pthread_t			*g_threads = NULL;
pthread_cond_t		g_start_render_cond = PTHREAD_COND_INITIALIZER;
pthread_cond_t		g_render_done_cond = PTHREAD_COND_INITIALIZER;
pthread_mutex_t		g_start_render_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t		g_render_done_mutex = PTHREAD_MUTEX_INITIALIZER;
atomic_int			g_asleep_threads = 0;
atomic_long			g_current_point = -1;
int					g_thread_count;

static inline int	thread_wait(t_scene *scene)
{
	pthread_mutex_lock(&g_start_render_mutex);
	while (1)
	{
		if (g_camera == NULL)
		{
			pthread_mutex_unlock(&g_start_render_mutex);
			return (-1);
		}
		if (g_current_point < 0 || g_current_point
			>= scene->resolution.width * scene->resolution.height)
			pthread_cond_wait(&g_start_render_cond, &g_start_render_mutex);
		else
			break ;
	}
	pthread_mutex_unlock(&g_start_render_mutex);
	return (1);
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
			c = atomic_fetch_add_explicit(&g_current_point, 1,
					__ATOMIC_SEQ_CST);
			if (c >= scene->resolution.width * scene->resolution.height)
				break ;
			raytrace_pixel((int)(c % (ssize_t)scene->resolution.width),
				(int)(c / (ssize_t)scene->resolution.width), scene, g_camera);
		}
		pthread_mutex_lock(&g_render_done_mutex);
		g_asleep_threads++;
		pthread_cond_signal(&g_render_done_cond);
		pthread_mutex_unlock(&g_render_done_mutex);
	}
}

void	start_rendering_threads(int count, t_scene *scene)
{
	int	i;
	int	ret;

	if (g_threads == NULL)
	{
		g_thread_count = count;
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
