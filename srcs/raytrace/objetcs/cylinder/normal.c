/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 13:56:37 by caugier           #+#    #+#             */
/*   Updated: 2020/12/26 22:29:25 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"
#include <math.h>
#include "../../disruptions/disruptions.h"

t_intersection	*get_cylinder_normal(t_ray *ray,
	t_intersection *intersection, t_any_obj *obj)
{
	t_vec3	aux;

	aux = ray->direction;
	vec3_cross(&aux, obj->cylinder->axis);
	vec3_cross(&aux, obj->cylinder->axis);
	if (vec3_scalar(ray->direction, aux) > 0)
		scale_vec3(&aux, -1);
	apply_normal_disruption(&aux, &intersection->intersection,
		obj->cylinder->material->disruption);
	intersection->normal = aux;
	return (intersection);
}
