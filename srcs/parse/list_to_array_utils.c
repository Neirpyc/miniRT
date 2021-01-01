/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_array_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 19:09:52 by caugier           #+#    #+#             */
/*   Updated: 2020/12/31 19:12:22 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_int.h"
#include "../gc_malloc/gc_malloc.h"
#include "../raytrace/objetcs/objects.h"

size_t	object_count(t_list_scene *scene)
{
	return (
		list_size(scene->spheres.list)
		+ list_size(scene->planes.list)
		+ list_size(scene->squares.list)
		+ list_size(scene->cylinders.list)
		+ list_size(scene->triangles.list)
		+ list_size(scene->cones.list)
		+ list_size(scene->discs.list));
}

size_t	copy_refs(t_array *arr, t_list *lst)
{
	t_list	*old;
	size_t	i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		((t_objects *)arr)->objects.objects[arr->size++].object.plane
			= lst->content;
		old = lst;
		lst = lst->next;
		gc_free(old);
	}
	return (i);
}

void	fill_funcs(t_objects *objs, void (*gf)(t_funcs *), size_t i)
{
	size_t	c;

	c = 0;
	while (c < i)
	{
		gf(&objs->objects.objects[objs->objects.size - c - 1].functions);
		objs->objects.objects[objs->objects.size - c - 1].material
			= objs->objects.objects[objs->objects.size - c - 1].functions
				.get_material(&objs->objects.objects[objs->objects.size - c - 1]
				.object);
		objs->objects.objects[objs->objects.size - c - 1].functions.
			bounding_box(&objs->objects.objects[objs->objects.size - c - 1]
			.bounding_box, &objs->objects.objects[objs->objects.size - c - 1]
			.object);
		c++;
	}
}

void	fill_all_funcs(t_list_scene *old, t_scene *new)
{
	fill_funcs(&new->objects, get_sphere_funcs,
		copy_refs(&new->objects.array, old->spheres.list));
	fill_funcs(&new->objects, get_plane_funcs,
		copy_refs(&new->objects.array, old->planes.list));
	fill_funcs(&new->objects, get_square_funcs,
		copy_refs(&new->objects.array, old->squares.list));
	fill_funcs(&new->objects, get_triangle_funcs,
		copy_refs(&new->objects.array, old->triangles.list));
	fill_funcs(&new->objects, get_cylinder_funcs,
		copy_refs(&new->objects.array, old->cylinders.list));
	fill_funcs(&new->objects, get_cone_funcs,
		copy_refs(&new->objects.array, old->cones.list));
	fill_funcs(&new->objects, get_disc_funcs,
		copy_refs(&new->objects.array, old->discs.list));
}
