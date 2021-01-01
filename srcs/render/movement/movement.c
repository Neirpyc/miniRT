/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 17:33:44 by caugier           #+#    #+#             */
/*   Updated: 2020/12/31 17:37:56 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../render_int.h"
#include "../../raytrace/raytrace_int.h"

static void	update_cam(t_camera *cam)
{
	t_vec3	aux;
	double	norm_dx;
	double	norm_dy;

	norm_dx = norm_vec3(cam->d_x);
	norm_dy = norm_vec3(cam->d_y);
	cam->d_x = cam->normal;
	vec3_cross(&cam->d_x, *init_vec(&aux, 0, 0, -1));
	if (norm_vec3(cam->d_x) == 0)
		init_vec(&cam->d_x, 0, -1, 0);
	normalize_vec3_d(&cam->d_x, norm_dx);
	cam->d_y = cam->normal;
	vec3_cross(&cam->d_y, cam->d_x);
	normalize_vec3_d(&cam->d_y, norm_dy);
}

static void	apply_trans(t_render *rd, t_vec3 *rotation, t_vec3 *tr)
{
	if (rd->mode == MODE_CAM)
	{
		add_vec3(&rd->scene->cameras.cameras.array[rd->cam_id].origin, *tr);
		rotate_vec3(&rd->scene->cameras.cameras.array[rd->cam_id].normal,
			*rotation);
		update_cam(&rd->scene->cameras.cameras.array[rd->cam_id]);
	}
	else
	{
		rd->scene->objects.objects.objects[rd->obj_id].functions.move(*tr,
			*rotation, &rd->scene->objects.objects.objects[rd->obj_id].object);
		rd->scene->objects.objects.objects[rd->obj_id].functions.bounding_box(
			&rd->scene->objects.objects.objects[rd->obj_id].bounding_box,
			&rd->scene->objects.objects.objects[rd->obj_id].object);
	}
}

void	move(t_render *rd, t_vec3 translation, t_vec3 rotation)
{
	t_vec3	aux;
	t_vec3	tr;

	scale_vec3(&translation, MOVE_STEP);
	scale_vec3(&rotation, ROTATE_STEP);
	init_vec(&tr, 0, 0, 0);
	aux = rd->scene->cameras.cameras.array[rd->cam_id].normal;
	add_vec3(&tr, *scale_vec3(&aux, translation.x));
	aux = rd->scene->cameras.cameras.array[rd->cam_id].d_x;
	add_vec3(&tr, *scale_vec3(&aux, translation.y));
	aux = rd->scene->cameras.cameras.array[rd->cam_id].d_y;
	add_vec3(&tr, *scale_vec3(&aux, translation.z));
	apply_trans(rd, &rotation, &tr);
}
