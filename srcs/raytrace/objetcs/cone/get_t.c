/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_t.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 12:40:36 by caugier           #+#    #+#             */
/*   Updated: 2021/01/03 23:54:48 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cone.h"
#include <math.h>
#include <float.h>

static inline void	get_cone_t_int(t_ray *ray, t_cone *cone,
	double *t0, double *t1)
{
	t_vec3	op;
	double	x1;
	double	x2;

	op = ray->origin;
	vec3_sub_noret(&op, cone->position);
	x1 = vec3_scalar(ray->direction, cone->direction);
	x2 = vec3_scalar(op, cone->direction);
	*t0 = solve_quadratic(x1 * x1 - cone->cos_sq,
		2 * (x1 * x2 - vec3_scalar(ray->direction, op) * cone->cos_sq),
		x2 * x2 - vec3_scalar(op, op) * cone->cos_sq, t1);
}

static inline int	cone_intersection_int(t_ray *ray, double t,
	t_cone *cone, t_intersection *intersection)
{
	t_vec3	aux;
	double	dst;

	intersection->intersection = ray->direction;
	scale_vec3(&intersection->intersection, t);
	add_vec3(&intersection->intersection, ray->origin);
	aux = intersection->intersection;
	vec3_sub_noret(&aux, cone->position);
	dst = norm_vec3(aux);
	scale_vec3(&aux, 1 / dst);
	if (fabs(vec3_scalar(aux, cone->direction) - cone->cos)
		< 1e-5 && dst < cone->max_dst)
		return (1);
	return (0);
}

double	get_cone_t(t_ray *ray, t_intersection *intersection, t_any_obj *obj)
{
	double	t0;
	double	t1;

	get_cone_t_int(ray, obj->cone, &t0, &t1);
	if (isnan(t0) && isnan(t1))
		return (NAN);
	intersection->intersection.x = t1;
	if (!isnan(t1) && t1 > 0)
		if (cone_intersection_int(ray, t1, obj->cone, intersection) == 1)
			return (t1);
	intersection->intersection.x = t0;
	if (t0 > 0)
		if (cone_intersection_int(ray, t0, obj->cone, intersection) == 1)
			return (t0);
	return (NAN);
}
