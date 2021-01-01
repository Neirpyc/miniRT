/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 14:47:48 by caugier           #+#    #+#             */
/*   Updated: 2020/12/20 15:24:01 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "planes.h"

t_intersection	*plane_intersect(t_ray *ray,
	t_intersection *intersection, t_any_obj *obj)
{
	t_vec3	aux;
	double	t;

	(void)obj;
	t = intersection->intersection.x;
	intersection->intersection = ray->origin;
	aux = ray->direction;
	add_vec3(&intersection->intersection, *scale_vec3(&aux, t));
	return (intersection);
}
