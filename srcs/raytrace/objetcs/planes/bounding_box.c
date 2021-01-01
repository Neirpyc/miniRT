/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bounding_box.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 00:01:44 by caugier           #+#    #+#             */
/*   Updated: 2020/12/31 20:03:51 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "planes.h"
#include <math.h>
#include <float.h>

int	plane_bb_side(t_min_max *bb, double pos, double c1, double c2)
{
	if (c1 == 0 && c2 == 0)
	{
		bb->min = pos - DBL_EPSILON;
		bb->max = pos + DBL_EPSILON;
		return (0);
	}
	bb->min = -INFINITY;
	bb->max = INFINITY;
	return (1);
}

void	plane_bounding_box(t_bounding_box *bounding_box, t_any_obj *obj)
{
	t_vec3	e1;
	t_vec3	e2;
	int		c;

	init_vec(&e1, 0, 0, 1);
	vec3_cross(&e1, obj->plane->normal);
	if (norm_vec3(e1) == 0)
		init_vec(&e1, 1, 0, 0);
	e2 = e1;
	vec3_cross(&e2, obj->plane->normal);
	c = plane_bb_side(&bounding_box->x, obj->plane->position.x, e1.x, e2.x);
	c += plane_bb_side(&bounding_box->y, obj->plane->position.y, e1.y, e2.y);
	c += plane_bb_side(&bounding_box->z, obj->plane->position.z, e1.z, e2.z);
	if (c == 3)
		bounding_box->x.min = NAN;
}
