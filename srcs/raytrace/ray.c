/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 22:32:04 by caugier           #+#    #+#             */
/*   Updated: 2021/01/02 19:14:57 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytrace_int.h"
#include "../gc_malloc/gc_malloc.h"
#include "disruptions/disruptions.h"
#include <float.h>

void	fill_ray(t_ray *ray, t_camera *cam, t_scene *scene, t_vec2 *pos)
{
	t_vec3	aux;
	double	w_2;

	ray->origin = cam->origin;
	ray->direction = cam->normal;
	aux = cam->d_x;
	w_2 = (double)scene->resolution.width / 2;
	if (pos->x < w_2)
		add_vec3(&ray->direction, *scale_vec3(&aux, 0.5 - pos->x));
	else if (pos->x > w_2)
		add_vec3(&ray->direction, *scale_vec3(&aux, pos->x - 1));
	aux = cam->d_y;
	w_2 = (double)scene->resolution.height / 2;
	if (pos->y < w_2)
		add_vec3(&ray->direction, *scale_vec3(&aux, 0.5 - pos->y));
	else if (pos->y > w_2)
		add_vec3(&ray->direction, *scale_vec3(&aux, pos->y - 1));
	normalize_vec3(&ray->direction);
	init_frgba_new_ray(&ray->color);
	ray->bounces = cam->bounces + 1;
	ray_set_dir(ray, &ray->direction);
}

void	average_components(t_ray *ray, t_intersection *intersection,
	size_t obj_id, t_scene *scene)
{
	t_frgba	spec;
	t_frgba	diff;
	t_vec3	old_intersection;
	double	fresnel;
	double	dst;

	init_frgba(&spec);
	init_frgba(&diff);
	old_intersection = intersection->intersection;
	intersection->intersection = ray->direction;
	fresnel = fresnel_spec_amount(RI_AIR, scene->objects.objects
			.objects[obj_id].material->refraction_indice, scene->objects.objects
			.objects[obj_id].material->spec_k, intersection);
	intersection->intersection = old_intersection;
	if (fresnel > 100 * DBL_EPSILON)
		get_specular_color(&spec, ray, intersection, scene);
	mix_colors(ray, scene->objects.objects.objects[obj_id].material->color, 1);
	get_diffuse_color(&diff, intersection, scene,
		scene->objects.objects.objects[obj_id].material->disruption);
	old_intersection = intersection->intersection;
	dst = norm_vec3(*vec3_sub(&old_intersection, ray->origin)) + 1;
	dst *= dst;
	mix_colors(ray, diff, -vec3_scalar(ray->direction, intersection->normal)
		 / dst);
	add_colors(&ray->color, spec, fresnel / dst);
}

static inline void	get_normal(t_ray *ray, t_scene *scene,
	size_t i, t_intersection *in)
{
	scene->objects.objects.objects[i].functions.normal(ray,
		in, &scene->objects.objects.objects[i].object);
	if (vec3_scalar(ray->direction, in->normal) > 0)
		vec_nan(&in->intersection);
}

static inline int	no_intersection(t_ray *ray, int max_bounces,
	t_intersection *in)
{
	if (vec3_is_nan(in->intersection))
	{
		if (ray->bounces == max_bounces)
			empty_frgba(&ray->color);
		else
			init_frgba(&ray->color);
		return (-1);
	}
	return (0);
}

void	simulate_ray(t_ray *ray, t_scene *scene, int max_bounces)
{
	size_t			i;
	t_intersection	in;

	ray->bounces--;
	if (ray->bounces == 0 || ray->color.red
		+ ray->color.green + ray->color.blue < COLOR_THRESHOLD)
	{
		init_frgba(&ray->color);
		return ;
	}
	get_best_intersection(scene, ray, &in, &i);
	if (no_intersection(ray, max_bounces, &in) < 0)
		return ;
	get_normal(ray, scene, i, &in);
	if (no_intersection(ray, max_bounces, &in) < 0)
		return ;
	average_components(ray, &in, i, scene);
}
