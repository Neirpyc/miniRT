/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 21:42:05 by caugier           #+#    #+#             */
/*   Updated: 2020/12/20 21:44:26 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "triangles.h"

t_intersection	*triangle_intersect(t_ray *ray,
	t_intersection *intersection, t_any_obj *obj)
{
	t_vec3	aux;

	(void)obj;
	aux = ray->direction;
	scale_vec3(&aux, intersection->intersection.x);
	intersection->intersection = ray->origin;
	add_vec3(&intersection->intersection, aux);
	return (intersection);
}
