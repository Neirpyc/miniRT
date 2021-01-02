/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse_lighting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 18:14:16 by caugier           #+#    #+#             */
/*   Updated: 2021/01/02 16:35:16 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "raytrace_int.h"
#include "disruptions/disruptions.h"

inline static int	loop_objects(t_scene *scene, t_ray *ray, double distance)
{
	size_t			j;
	t_intersection	in;
	double			dst;

	j = scene->objects.objects.size;
	while (j != 0)
	{
		j--;
		if (!bounding_box_intersect(
			&scene->objects.objects.objects[j].bounding_box, ray, distance))
			continue ;
		if (isnan(scene->objects.objects.objects[j].functions.get_t(ray, &in,
					&scene->objects.objects.objects[j].object)))
			continue ;
		scene->objects.objects.objects[j].functions.intersect(ray, &in,
			&scene->objects.objects.objects[j].object);
		dst = norm_vec3(*vec3_sub(&in.intersection, ray->origin));
		if (dst < 1e-10)
			continue ;
		if (dst <= distance)
			return (0);
	}
	return (1);
}

static inline void	loop_lights(t_frgba *color,	t_intersection *intersection,
	t_scene *scene,	t_ray *ray)
{
	size_t	i;
	double	distance;

	i = scene->lights.lights.size;
	while (i != 0)
	{
		i--;
		ray->direction = scene->lights.lights.array[i].position;
		vec3_sub_noret(&ray->direction, ray->origin);
		if (vec3_scalar(ray->direction, intersection->normal) < 0)
			continue ;
		distance = norm_vec3(ray->direction);
		scale_vec3(&ray->direction, 1. / distance);
		ray_set_dir(ray, &ray->direction);
		if (loop_objects(scene, ray, distance) == 1)
		{
			add_colors(color, scene->lights.lights.array[i].color,
				scene->lights.lights.array[i].strength
				* vec3_scalar(ray->direction, intersection->normal) / distance
				/ distance);
		}
	}
}

static inline void	loop_p_lights(t_frgba *color, t_intersection *intersection,
	t_scene *scene,	t_ray *ray)
{
	size_t	i;
	t_vec3	aux;
	double	dst;

	i = scene->p_lights.p_lights.size;
	while (i != 0)
	{
		i--;
		aux = ray->origin;
		vec3_sub_noret(&aux, scene->p_lights.p_lights.array[i].position);
		ray->direction = scene->p_lights.p_lights.array[i].normal;
		dst = -vec3_scalar(ray->direction, aux);
		if (dst > 0 || vec3_scalar(ray->direction, intersection->normal) > 0)
			continue ;
		scale_vec3(&ray->direction, dst);
		dst = norm_vec3(ray->direction);
		scale_vec3(&ray->direction, 1. / dst);
		ray_set_dir(ray, &ray->direction);
		if (loop_objects(scene, ray, dst) == 1)
		{
			add_colors(color, scene->p_lights.p_lights.array[i].color,
				scene->p_lights.p_lights.array[i].strength * vec3_scalar(
					ray->direction, intersection->normal) / dst / dst);
		}
	}
}

t_frgba	*get_diffuse_color(t_frgba *color, t_intersection *intersection,
	t_scene *scene, t_disruption disruption)
{
	t_ray	ray;
	t_vec3	aux;

	add_colors(color, scene->ambient.color, scene->ambient.strength);
	ray.origin = intersection->intersection;
	aux = intersection->normal;
	add_vec3(&ray.origin, *scale_vec3(&aux, 0.1));
	loop_lights(color, intersection, scene, &ray);
	loop_p_lights(color, intersection, scene, &ray);
	apply_color_disruptions(color, &intersection->normal,
		&intersection->intersection, disruption);
	return (color);
}
