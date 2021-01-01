/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bounding_box.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 00:01:44 by caugier           #+#    #+#             */
/*   Updated: 2020/12/31 13:07:34 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disc.h"

void	disc_bounding_box(t_bounding_box *bounding_box, t_any_obj *obj)
{
	t_vec3	e1;
	t_vec3	e2;
	t_vec3	pts[4];

	init_vec(&e1, 0, 0, 1);
	vec3_cross(&e1, obj->disc->normal);
	if (norm_vec3(e1) == 0)
		init_vec(&e1, 1, 0, 0);
	e2 = e1;
	vec3_cross(&e2, obj->disc->normal);
	normalize_vec3_d(&e1, obj->disc->radius * 2);
	normalize_vec3_d(&e2, obj->disc->radius * 2);
	pts[0] = obj->disc->center;
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
