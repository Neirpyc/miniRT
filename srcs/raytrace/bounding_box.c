/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bounding_box.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 23:53:22 by caugier           #+#    #+#             */
/*   Updated: 2021/01/01 00:17:53 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytrace_int.h"
#include <math.h>

void	points_to_bb(t_bounding_box *bb, t_vec3 pts[4])
{
	bb->x.min = fmin(fmin(fmin(pts[3].x, pts[2].x), pts[1].x), pts[0].x);
	bb->x.max = fmax(fmax(fmax(pts[3].x, pts[2].x), pts[1].x), pts[0].x);
	bb->y.min = fmin(fmin(fmin(pts[3].y, pts[2].y), pts[1].y), pts[0].y);
	bb->y.max = fmax(fmax(fmax(pts[3].y, pts[2].y), pts[1].y), pts[0].y);
	bb->z.min = fmin(fmin(fmin(pts[3].z, pts[2].z), pts[1].z), pts[0].z);
	bb->z.max = fmax(fmax(fmax(pts[3].z, pts[2].z), pts[1].z), pts[0].z);
}

inline int	bounding_box_intersect(t_bounding_box *bb, t_ray *ray, double 
best_t)
{
	t_min_max	tx;
	t_min_max	t;
	t_min_max	ty;
	t_min_max	tz;

	if (isnan(bb->x.min))
		return (1);
	tx.min = (bb->x.min - ray->origin.x) * ray->invdir.x;
	tx.max = (bb->x.max - ray->origin.x) * ray->invdir.x;
	t.min = fmin(tx.min, tx.max);
	t.max = fmax(tx.min, tx.max);
	ty.min = (bb->y.min - ray->origin.y) * ray->invdir.y;
	ty.max = (bb->y.max - ray->origin.y) * ray->invdir.y;
	t.min = fmax(t.min, fmin(ty.min, ty.max));
	t.max = fmin(t.max, fmax(ty.min, ty.max));
	tz.min = (bb->z.min - ray->origin.z) * ray->invdir.z;
	tz.max = (bb->z.max - ray->origin.z) * ray->invdir.z;
	t.min = fmax(t.min, fmin(tz.min, tz.max));
	t.max = fmin(t.max, fmax(tz.min, tz.max));
	return (t.max >= fmax(0, t.min) && t.min < best_t);
}
