/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specular_lighting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 18:26:40 by caugier           #+#    #+#             */
/*   Updated: 2021/01/03 23:00:01 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytrace_int.h"
#include <limits.h>

t_frgba	*get_specular_color(t_frgba *color, t_ray *incident,
	t_intersection *intersection, t_scene *scene)
{
	t_ray	reflect;
	t_vec3	aux0;

	reflect.origin = intersection->intersection;
	reflect.direction = intersection->normal;
	scale_vec3(&reflect.direction, -2 * vec3_scalar(incident->direction,
		intersection->normal));
	add_vec3(&reflect.direction, incident->direction);
	normalize_vec3(&reflect.direction);
	ray_set_dir(&reflect, &reflect.direction);
	aux0 = reflect.direction;
	add_vec3(&reflect.origin, *scale_vec3(&aux0, 1e-5));
	reflect.color.red = incident->color.red;
	reflect.color.green = incident->color.green;
	reflect.color.blue = incident->color.blue;
	reflect.bounces = incident->bounces;
	simulate_ray(&reflect, scene, INT_MAX);
	color->red = reflect.color.red;
	color->green = reflect.color.green;
	color->blue = reflect.color.blue;
	return (color);
}
