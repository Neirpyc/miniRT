/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 23:30:35 by caugier           #+#    #+#             */
/*   Updated: 2020/12/31 23:23:20 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "gc_malloc/gc_malloc.h"
#include "parse/parse.h"
#include "window/window.h"
#include <sys/sysinfo.h>
#include "raytrace/raytrace_int.h"
#include "bmp/bmp.h"

int	main(int argc, char **argv)
{
	t_render	*rd;

	rd = new_render(parse(argc, argv));
	gc_add_cb(gc_free, rd);
	if (rd->scene->save == 0)
		open_window(&rd->scene->resolution.width, &rd->scene->resolution
		.height);
	else
		init_img_buffer(rd->scene->resolution.width,
			rd->scene->resolution.height);
	gc_add_cb(close_window, NULL);
	gc_add_cb((void (*)(void *))free_scene, rd->scene);
	gc_add_cb((void (*)(void *))free_img_buffer, NULL);
	gc_add_cb((void (*)(void *))stop_threads, NULL);
	start_rendering_threads(get_nprocs(), rd->scene);
	render(&rd->scene->cameras.cameras.array[rd->cam_id]);
	if (rd->scene->save == 0)
		loop_window(rd);
	else
		export_buffer_bmp(rd->scene->resolution.width,
			rd->scene->resolution.height);
	gc_exit(0);
}
