/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 21:23:06 by caugier           #+#    #+#             */
/*   Updated: 2020/12/31 18:13:23 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytrace_int.h"
#include <math.h>

static inline double	get_best_intersection_int(t_scene *scene, t_ray *ray,
	t_intersection *in, size_t *i)
{
	size_t			c;
	t_intersection	tmp;
	double			best_d;
	double			dst;

	best_d = INFINITY;
	c = scene->objects.array.size;
	while (c != 0)
	{
		c--;
		if (!bounding_box_intersect(
				&scene->objects.objects.objects[c].bounding_box, ray, best_d))
			continue ;
		dst = scene->objects.objects.objects[c].functions.get_t(ray,
				&tmp, &scene->objects.objects.objects[c].object);
		if (isnan(dst))
			continue ;
		if (dst < best_d)
		{
			best_d = dst;
			*i = c;
			*in = tmp;
		}
	}
	return (best_d);
}

inline void	get_best_intersection(t_scene *scene, t_ray *ray,
	t_intersection *in, size_t *i)
{
	if (get_best_intersection_int(scene, ray, in, i) == INFINITY)
	{
		vec_nan(&in->intersection);
		return ;
	}
	scene->objects.objects.objects[*i].functions.intersect(ray, in,
		&scene->objects.objects.objects[*i].object);
}

inline void	ray_set_dir(t_ray *ray, t_vec3 *dir)
{
	ray->direction = *dir;
	ray->invdir.x = 1 / dir->x;
	ray->invdir.y = 1 / dir->y;
	ray->invdir.z = 1 / dir->z;
}
