/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_t.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 21:35:12 by caugier           #+#    #+#             */
/*   Updated: 2020/12/30 16:02:58 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "triangles.h"
#include <math.h>

double	triangle_get_t(t_ray *ray,
	t_intersection *intersection, t_any_obj *obj)
{
	t_vec3	h;
	t_vec3	s;
	double	a;
	double	u;
	double	v;

	h = ray->direction;
	vec3_cross(&h, obj->triangle->edge2);
	a = vec3_scalar(obj->triangle->edge1, h);
	if (a > -1e-10 && a < 1e-10)
		return (NAN);
	a = 1. / a;
	s = ray->origin;
	vec3_sub_noret(&s, obj->triangle->corner);
	u = a * vec3_scalar(s, h);
	if (u < 0 || u > 1)
		return (NAN);
	vec3_cross(&s, obj->triangle->edge1);
	v = a * vec3_scalar(ray->direction, s);
	if (v < 0 || u + v > 1)
		return (NAN);
	intersection->intersection.x = a * vec3_scalar(obj->triangle->edge2, s);
	if (intersection->intersection.x < 1e-1)
		return (NAN);
	return (intersection->intersection.x);
}
