/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_materials0.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 20:33:02 by caugier           #+#    #+#             */
/*   Updated: 2020/12/09 17:16:21 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_int.h"

void	link_spheres(t_list *lines, t_scene_parse *scene)
{
	t_material			*mat;
	signed long long	id;
	t_sphere_list		list;
	t_id_line_list		id_list;
	t_location			loc;

	list = scene->scene->spheres;
	id_list = scene->spheres_lines;
	while (list.list != NULL)
	{
		id = (signed long long)list.spheres->content->material;
		mat = seek_material(scene, id);
		loc.line = id_list.id_line_list->nbr;
		if (mat == NULL)
			unk_material_id(lines, id, gen_loc(&loc, -1, 3, 3));
		list.spheres->content->material = mat;
		list.list = list.list->next;
		id_list.list = id_list.list->next;
	}
}

void	link_planes(t_list *lines, t_scene_parse *scene)
{
	t_material			*mat;
	signed long long	id;
	t_plane_list		list;
	t_id_line_list		id_list;
	t_location			loc;

	list = scene->scene->planes;
	id_list = scene->planes_lines;
	while (list.list != NULL)
	{
		id = (signed long long)list.planes->content->material;
		mat = seek_material(scene, id);
		loc.line = id_list.id_line_list->nbr;
		if (mat == NULL)
			unk_material_id(lines, id, gen_loc(&loc, -1, 3, 3));
		list.planes->content->material = mat;
		list.list = list.list->next;
		id_list.list = id_list.list->next;
	}
}

void	link_squares(t_list *lines, t_scene_parse *scene)
{
	t_material			*mat;
	signed long long	id;
	t_square_list		list;
	t_id_line_list		id_list;
	t_location			loc;

	list = scene->scene->squares;
	id_list = scene->squares_lines;
	while (list.list != NULL)
	{
		id = (signed long long)list.squares->content->material;
		mat = seek_material(scene, id);
		loc.line = id_list.id_line_list->nbr;
		if (mat == NULL)
			unk_material_id(lines, id, gen_loc(&loc, -1, 4, 4));
		list.squares->content->material = mat;
		list.list = list.list->next;
		id_list.list = id_list.list->next;
	}
}

void	link_cylinders(t_list *lines, t_scene_parse *scene)
{
	t_material			*mat;
	signed long long	id;
	t_cylinder_list		list;
	t_id_line_list		id_list;
	t_location			loc;

	list = scene->scene->cylinders;
	id_list = scene->cylinders_lines;
	while (list.list != NULL)
	{
		id = (signed long long)list.cylinders->content->material;
		mat = seek_material(scene, id);
		loc.line = id_list.id_line_list->nbr;
		if (mat == NULL)
			unk_material_id(lines, id, gen_loc(&loc, -1, 5, 5));
		list.cylinders->content->material = mat;
		list.list = list.list->next;
		id_list.list = id_list.list->next;
	}
}

void	link_triangles(t_list *lines, t_scene_parse *scene)
{
	t_material			*mat;
	signed long long	id;
	t_triangle_list		list;
	t_id_line_list		id_list;
	t_location			loc;

	list = scene->scene->triangles;
	id_list = scene->triangles_lines;
	while (list.list != NULL)
	{
		id = (signed long long)list.triangles->content->material;
		mat = seek_material(scene, id);
		loc.line = id_list.id_line_list->nbr;
		if (mat == NULL)
			unk_material_id(lines, id, gen_loc(&loc, -1, 4, 4));
		list.triangles->content->material = mat;
		list.list = list.list->next;
		id_list.list = id_list.list->next;
	}
}
