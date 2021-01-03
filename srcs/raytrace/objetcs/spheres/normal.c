/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 13:37:40 by caugier           #+#    #+#             */
/*   Updated: 2020/12/29 16:09:11 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "spheres.h"
#include "../../disruptions/disruptions.h"

t_intersection	*get_sphere_normal(t_ray *ray,
	t_intersection *intersection, t_any_obj *obj)
{
	t_vec3	aux;

	(void)ray;
	aux = intersection->intersection;
	vec3_sub_noret(&aux, obj->sphere->position);
	if (intersection->normal.x > 0 && intersection->normal.y < 0)
		scale_vec3(&aux, -1);
	normalize_vec3(&aux);
	apply_normal_disruption(&aux, &intersection->intersection,
		obj->sphere->material->disruption);
	intersection->normal = aux;
	return (intersection);
}
