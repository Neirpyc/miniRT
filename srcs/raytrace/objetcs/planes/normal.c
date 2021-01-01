/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 14:43:33 by caugier           #+#    #+#             */
/*   Updated: 2020/12/20 17:13:24 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "planes.h"
#include "../../disruptions/disruptions.h"

t_intersection	*get_plane_normal(t_ray *ray,
	t_intersection *intersection, t_any_obj *obj)
{
	(void)ray;
	(void)obj;
	scale_vec3(&intersection->normal, -1);
	apply_normal_disruption(&intersection->normal, &intersection->intersection,
		obj->plane->material->disruption);
	return (intersection);
}
