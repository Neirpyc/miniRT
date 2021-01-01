/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 14:43:33 by caugier           #+#    #+#             */
/*   Updated: 2020/12/20 18:41:05 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "squares.h"
#include "../../disruptions/disruptions.h"

t_intersection	*get_square_normal(t_ray *ray,
	t_intersection *intersection, t_any_obj *obj)
{
	(void)ray;
	(void)obj;
	scale_vec3(&intersection->normal, -1);
	apply_normal_disruption(&intersection->normal, &intersection->intersection,
		obj->square->material->disruption);
	return (intersection);
}
