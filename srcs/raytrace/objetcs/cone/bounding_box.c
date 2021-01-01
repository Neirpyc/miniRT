/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bounding_box.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 00:01:44 by caugier           #+#    #+#             */
/*   Updated: 2020/12/31 21:20:56 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cone.h"
#include <math.h>

static void	get_co_bb_int(t_bounding_box *bounding_box, t_cone *cone,
	t_position position)
{
	t_vec3	e1;
	t_vec3	e2;
	t_vec3	pts[4];

	init_vec(&e1, 0, 0, 1);
	vec3_cross(&e1, cone->direction);
	if (norm_vec3(e1) == 0)
		init_vec(&e1, 1, 0, 0);
	e2 = e1;
	vec3_cross(&e2, cone->direction);
	normalize_vec3_d(&e1, tan(cone->angle) * cone->height * 2);
	normalize_vec3_d(&e2, tan(cone->angle) * cone->height * 2);
	pts[0] = position;
	pts[1] = e1;
	pts[2] = e2;
	scale_vec3(&pts[1], -0.5);
	scale_vec3(&pts[2], -0.5);
	add_vec3(&pts[0], *add_vec3(&pts[1], pts[2]));
	pts[1] = pts[0];
	add_vec3(&pts[1], e1);
	pts[2] = pts[0];
	add_vec3(&pts[2], e2);
	pts[3] = pts[2];
	add_vec3(&pts[3], e1);
	points_to_bb(bounding_box, pts);
}

void	cone_bounding_box(t_bounding_box *bounding_box, t_any_obj *obj)
{
	t_vec3			pos;
	t_bounding_box	bbs[2];

	get_co_bb_int(&bbs[0], obj->cone, obj->cone->position);
	pos = obj->cone->direction;
	add_vec3(scale_vec3(&pos, obj->cone->height), obj->cone->position);
	get_co_bb_int(&bbs[1], obj->cone, pos);
	bounding_box->x.min = fmin(bbs[0].x.min, bbs[1].x.min);
	bounding_box->x.max = fmax(bbs[0].x.max, bbs[1].x.max);
	bounding_box->y.min = fmin(bbs[0].y.min, bbs[1].y.min);
	bounding_box->y.max = fmax(bbs[0].y.max, bbs[1].y.max);
	bounding_box->z.min = fmin(bbs[0].z.min, bbs[1].z.min);
	bounding_box->z.max = fmax(bbs[0].z.max, bbs[1].z.max);
}
