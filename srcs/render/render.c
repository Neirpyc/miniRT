/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 12:04:22 by caugier           #+#    #+#             */
/*   Updated: 2020/12/31 17:42:28 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_int.h"
#include "../window/window.h"
#include "../gc_malloc/gc_malloc.h"

t_camera	*g_camera = (t_camera *) 0x01;

void	render(t_camera *cam)
{
	pthread_mutex_lock(&g_start_render_mutex);
	g_camera = cam;
	g_asleep_threads = 0;
	g_current_point = 0;
	pthread_cond_broadcast(&g_start_render_cond);
	pthread_mutex_unlock(&g_start_render_mutex);
	pthread_mutex_lock(&g_render_done_mutex);
	while (g_asleep_threads != g_thread_count)
		pthread_cond_wait(&g_render_done_cond, &g_render_done_mutex);
	pthread_mutex_unlock(&g_render_done_mutex);
	flush_window_buffer();
}

t_render	*new_render(t_scene *scene)
{
	t_render	*ret;

	ret = gc_malloc(sizeof(t_render));
	ret->scene = scene;
	ret->obj_id = 0;
	ret->cam_id = 0;
	ret->mode = MODE_CAM;
	return (ret);
}

void	force_render(t_render *rd)
{
	render(&rd->scene->cameras.cameras.array[rd->cam_id]);
}
