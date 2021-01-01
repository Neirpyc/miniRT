/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_t.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 15:12:53 by caugier           #+#    #+#             */
/*   Updated: 2020/12/31 20:00:53 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "spheres.h"
#include <math.h>

double	get_sphere_t(t_ray *ray, t_intersection *intersection, t_any_obj *obj)
{
	t_vec3	aux0;
	t_vec3	aux1;
	double	t0;
	double	t1;

	aux0 = ray->direction;
	scale_vec3(&aux0, 2);
	aux1 = ray->origin;
	vec3_sub_noret(&aux1, obj->sphere->position);
	t0 = vec3_scalar(aux0, aux1);
	aux0 = ray->origin;
	vec3_sub_noret(&aux0, obj->sphere->position);
	t0 = solve_quadratic(1, t0,
		vec3_scalar(aux0, aux0) - (obj->sphere->radius_sq), &t1);
	intersection->normal.x = t0;
	intersection->normal.y = t1;
	if (isnan(t0) && isnan(t1))
		return (NAN);
	if (!isnan(t1) && t1 > 0)
		t0 = t1;
	if (t0 < 0)
		return (NAN);
	intersection->intersection.x = t0;
	return (t0);
}
