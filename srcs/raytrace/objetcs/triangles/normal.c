/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 21:30:44 by caugier           #+#    #+#             */
/*   Updated: 2020/12/20 22:05:23 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "triangles.h"
#include "../../disruptions/disruptions.h"

t_intersection	*get_triangle_normal(t_ray *ray,
	t_intersection *intersection, t_any_obj *obj)
{
	(void)ray;
	(void)obj;
	intersection->normal = obj->triangle->normal;
	if (vec3_scalar(ray->direction, intersection->normal) > 0)
		scale_vec3(&intersection->normal, -1);
	apply_normal_disruption(&intersection->normal, &intersection->intersection,
		obj->triangle->material->disruption);
	return (intersection);
}
