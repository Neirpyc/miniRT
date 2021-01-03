/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 12:40:57 by caugier           #+#    #+#             */
/*   Updated: 2020/12/27 18:40:37 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cone.h"
#include "../../disruptions/disruptions.h"

t_intersection	*get_cone_normal(t_ray *ray,
	t_intersection *intersection, t_any_obj *obj)
{
	t_vec3	aux;
	double	d;

	(void)ray;
	aux = intersection->intersection;
	vec3_sub_noret(&aux, obj->cone->position);
	d = norm_vec3(aux);
	aux = obj->cone->direction;
	scale_vec3(&aux, d / obj->cone->cos);
	add_vec3(&aux, obj->cone->position);
	intersection->normal = intersection->intersection;
	vec3_sub_noret(&intersection->normal, aux);
	if (vec3_scalar(ray->direction, intersection->normal) > 0)
		scale_vec3(&intersection->normal, -1);
	normalize_vec3(&intersection->normal);
	apply_normal_disruption(&intersection->normal, &intersection->intersection,
		obj->cone->material->disruption);
	return (intersection);
}
