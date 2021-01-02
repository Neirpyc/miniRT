/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 13:56:37 by caugier           #+#    #+#             */
/*   Updated: 2021/01/02 00:35:00 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"
#include <math.h>
#include "../../disruptions/disruptions.h"

t_intersection	*get_cylinder_normal(t_ray *ray,
	t_intersection *intersection, t_any_obj *obj)
{
	double	k;
	t_vec3	aux;
	t_vec3	tmp;

	aux = intersection->intersection;
	vec3_sub_noret(&aux, obj->cylinder->position);
	k = norm_vec3(aux) * norm_vec3(aux) - obj->cylinder->rad_sq;
	if (k > 0)
	{
		k = sqrt(k);
		tmp = obj->cylinder->axis;
		if (vec3_scalar(obj->cylinder->axis, aux) > 0)
			scale_vec3(&tmp, k);
		else
			scale_vec3(&tmp, -k);
		vec3_sub_noret(&aux, tmp);
	}
	normalize_vec3(&aux);
	if (vec3_scalar(ray->direction, aux) > 0)
		scale_vec3(&aux, -1);
	apply_normal_disruption(&aux, &intersection->intersection,
		obj->cylinder->material->disruption);
	intersection->normal = aux;
	return (intersection);
}
