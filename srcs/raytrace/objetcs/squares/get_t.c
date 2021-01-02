/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_t.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 15:20:49 by caugier           #+#    #+#             */
/*   Updated: 2021/01/02 16:19:42 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "squares.h"

static double	get_square_normal_int(t_intersection *intersection,
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

static inline int	is_in_square(t_intersection *in, t_square *sq)
{
	t_vec3	v;
	double	p;

	v = in->intersection;
	vec3_sub_noret(&v, sq->corner);
	p = vec3_scalar(v, sq->edge_1);
	if (p < 1e-5 || p > sq->side_squared)
		return (0);
	p = vec3_scalar(v, sq->edge_2);
	if (p < 1e-5 || p > sq->side_squared)
		return (0);
	return (1);
}

double	square_get_t(t_ray *ray,
	t_intersection *intersection, t_any_obj *obj)
{
	double	denom;
	double	t;
	t_vec3	aux;

	denom = vec3_scalar(obj->square->normal, ray->direction);
	denom = get_square_normal_int(intersection, obj->plane, denom);
	if (denom < 0)
		return (NAN);
	aux = obj->plane->position;
	vec3_sub_noret(&aux, ray->origin);
	t = vec3_scalar(aux, intersection->normal) / denom;
	if (t < 1e-2)
		return (NAN);
	intersection->intersection = ray->origin;
	aux = ray->direction;
	add_vec3(&intersection->intersection, *scale_vec3(&aux, t));
	if (is_in_square(intersection, obj->square) == 1)
		return (t);
	return (NAN);
}
