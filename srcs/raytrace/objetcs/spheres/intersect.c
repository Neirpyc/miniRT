/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 13:36:12 by caugier           #+#    #+#             */
/*   Updated: 2020/12/31 19:59:41 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "spheres.h"
#include <math.h>
#include <float.h>

t_intersection	*sphere_intersect(t_ray *ray,
	t_intersection *intersection, t_any_obj *obj)
{
	t_vec3	aux;
	double	t0;

	(void)obj;
	t0 = intersection->intersection.x;
	intersection->intersection = ray->origin;
	aux = ray->direction;
	add_vec3(&intersection->intersection, *scale_vec3(&aux, t0));
	return (intersection);
}
