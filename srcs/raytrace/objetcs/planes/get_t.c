/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_t.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 15:20:49 by caugier           #+#    #+#             */
/*   Updated: 2021/01/02 13:06:39 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "planes.h"
#include <math.h>

static double	get_plane_normal_int(t_intersection *intersection,
	t_plane *obj, double denom)
{
	intersection->normal = obj->normal;
	if (denom < 0)
	{
		scale_vec3(&intersection->normal, -1);
		denom *= -1;
	}
	return (denom);
}

double	plane_get_t(t_ray *ray,
	t_intersection *intersection, t_any_obj *obj)
{
	double	denom;
	double	t;
	t_vec3	aux;

	denom = vec3_scalar(obj->plane->normal, ray->direction);
	denom = get_plane_normal_int(intersection, obj->plane, denom);
	if (denom < 0)
		return (NAN);
	aux = obj->plane->position;
	vec3_sub_noret(&aux, ray->origin);
	t = vec3_scalar(aux, intersection->normal) / denom;
	if (t < 0)
		return (NAN);
	intersection->intersection.x = t;
	intersection->intersection.y = denom;
	return (t);
}
