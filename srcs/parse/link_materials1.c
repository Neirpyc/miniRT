/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_materials1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 21:28:51 by caugier           #+#    #+#             */
/*   Updated: 2020/12/31 19:18:54 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_int.h"

void	link_cubes(t_list *lines, t_scene_parse *scene)
{
	t_material			*mat;
	signed long long	id;
	t_cube_list			list;
	t_id_line_list		id_list;
	t_location			loc;

	list = scene->scene->cubes;
	id_list = scene->cubes_lines;
	while (list.list != NULL)
	{
		id = (signed long long)list.cubes->content->material;
		mat = seek_material(scene, id);
		loc.line = id_list.id_line_list->nbr;
		if (mat == NULL)
			unk_material_id(lines, id, gen_loc(&loc, -1, 5, 5));
		list.cubes->content->material = mat;
		list.list = list.list->next;
		id_list.list = id_list.list->next;
	}
}

void	link_cones(t_list *lines, t_scene_parse *scene)
{
	t_material			*mat;
	signed long long	id;
	t_cone_list			list;
	t_id_line_list		id_list;
	t_location			loc;

	list = scene->scene->cones;
	id_list = scene->cones_lines;
	while (list.list != NULL)
	{
		id = (signed long long)list.cones->content->material;
		mat = seek_material(scene, id);
		loc.line = id_list.id_line_list->nbr;
		if (mat == NULL)
			unk_material_id(lines, id, gen_loc(&loc, -1, 4, 4));
		list.cones->content->material = mat;
		list.list = list.list->next;
		id_list.list = id_list.list->next;
	}
}

void	link_pyramids(t_list *lines, t_scene_parse *scene)
{
	t_material			*mat;
	signed long long	id;
	t_pyramid_list		list;
	t_id_line_list		id_list;
	t_location			loc;

	list = scene->scene->pyramids;
	id_list = scene->pyramids_lines;
	while (list.list != NULL)
	{
		id = (signed long long)list.pyramids->content->material;
		mat = seek_material(scene, id);
		loc.line = id_list.id_line_list->nbr;
		if (mat == NULL)
			unk_material_id(lines, id, gen_loc(&loc, -1, 5, 5));
		list.pyramids->content->material = mat;
		list.list = list.list->next;
		id_list.list = id_list.list->next;
	}
}
