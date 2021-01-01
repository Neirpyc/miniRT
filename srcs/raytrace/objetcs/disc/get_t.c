/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_t.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 15:20:49 by caugier           #+#    #+#             */
/*   Updated: 2020/12/31 20:05:38 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disc.h"
#include <math.h>

static inline double	get_disc_normal_int(t_intersection *intersection,
	t_disc *obj, double denom)
{
	intersection->normal = obj->normal;
	if (denom < 0)
	{
		scale_vec3(&intersection->normal, -1);
		denom *= -1;
	}
	return (denom);
}

static inline void	get_disc_intersection_int(t_ray *ray,
	t_intersection *intersection, double t)
{
	t_vec3	aux;

	intersection->intersection = ray->origin;
	aux = ray->direction;
	add_vec3(&intersection->intersection, *scale_vec3(&aux, t));
}

double	disc_get_t(t_ray *ray, t_intersection *intersection, t_any_obj *obj)
{
	double	denom;
	double	t;
	t_vec3	aux;

	denom = vec3_scalar(obj->plane->normal, ray->direction);
	denom = get_disc_normal_int(intersection, obj->disc, denom);
	if (denom <= 0)
		return (NAN);
	aux = obj->plane->position;
	vec3_sub_noret(&aux, ray->origin);
	t = vec3_scalar(aux, intersection->normal) / denom;
	if (t <= 0)
		return (NAN);
	get_disc_intersection_int(ray, intersection, t);
	aux = intersection->intersection;
	vec3_sub_noret(&aux, obj->disc->center);
	if (norm_vec3(aux) <= obj->disc->radius)
		return (t);
	return (NAN);
}
