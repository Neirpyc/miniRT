/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_t.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 13:47:51 by caugier           #+#    #+#             */
/*   Updated: 2020/12/31 21:19:54 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"
#include <math.h>

static inline void	get_cylinder_t_int(t_ray *ray, t_cylinder *cylinder,
	double *t0, double *t1)
{
	t_vec3	x1;
	t_vec3	x2;
	t_vec3	op;
	t_vec3	aux0;
	t_vec3	aux1;

	op = ray->origin;
	vec3_sub_noret(&op, cylinder->position);
	x1 = cylinder->axis;
	scale_vec3(&x1, vec3_scalar(cylinder->axis, op));
	x2 = cylinder->axis;
	scale_vec3(&x2, vec3_scalar(cylinder->axis, ray->direction));
	aux0 = op;
	vec3_sub_noret(&aux0, x1);
	aux1 = ray->direction;
	vec3_sub(&aux1, x2);
	*t0 = solve_quadratic(
		vec3_scalar(aux1, aux1),
		2 * vec3_scalar(aux0, aux1),
		vec3_scalar(aux0, aux0) - cylinder->rad_sq,
		t1);
}

static inline int	cylinder_intersection_int(t_ray *ray, double t,
	t_cylinder *cylinder, t_intersection *intersection)
{
	t_vec3	aux;

	intersection->intersection = ray->direction;
	scale_vec3(&intersection->intersection, t);
	add_vec3(&intersection->intersection, ray->origin);
	aux = intersection->intersection;
	if (norm_vec3(*vec3_sub(&aux, cylinder->position)) <= cylinder->max_offset)
		return (1);
	return (0);
}

double	get_cylinder_t(t_ray *ray, t_intersection *intersection, t_any_obj *obj)
{
	double	t0;
	double	t1;

	get_cylinder_t_int(ray, obj->cylinder, &t0, &t1);
	if (isnan(t0) && isnan(t1))
		return (NAN);
	if (!isnan(t1) && t1 > 0)
		if (cylinder_intersection_int(ray, t1, obj->cylinder, intersection)
			== 1)
			return (t1);
	if (t0 > 0)
		if (cylinder_intersection_int(ray, t0, obj->cylinder, intersection)
			== 1)
			return (t0);
	return (NAN);
}
