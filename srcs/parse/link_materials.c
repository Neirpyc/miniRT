/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_materials.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 19:27:44 by caugier           #+#    #+#             */
/*   Updated: 2020/12/16 19:00:20 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_int.h"
#include <unistd.h>
#include "../libft/libft.h"
#include "../gc_malloc/gc_malloc.h"

t_material	*seek_material(t_scene_parse *scene, signed long long id)
{
	t_material_list	list;

	list = scene->scene->materials;
	while (list.list != NULL)
	{
		if (list.materials->content->id == id)
			return (list.materials->content);
		list.list = list.list->next;
	}
	return (NULL);
}

void	unk_material_id(t_list *lines, signed long long id, t_location *loc)
{
	size_t	lst_size;

	ft_put_strerror(ERRCODE_UNK_MATID);
	write(STDOUT_FILENO, "Note: material ID ", 18);
	ft_putnbr_fd(id, STDOUT_FILENO);
	write(STDOUT_FILENO, " is used at line ", 17);
	ft_putnbr_fd(loc->line, STDOUT_FILENO);
	write(STDOUT_FILENO, " but was never declared\n", 24);
	lst_size = list_size(lines) - 1;
	while (loc->line != lst_size)
	{
		lst_size--;
		lines = lines->next;
	}
	highlight_words(lines->content, loc->char_beg,
		loc->arg_begin, loc->arg_end);
	gc_exit(-1);
}

void	link_mat(t_list *lines, t_scene_parse *scene)
{
	link_spheres(lines, scene);
	link_planes(lines, scene);
	link_squares(lines, scene);
	link_cylinders(lines, scene);
	link_triangles(lines, scene);
	link_cubes(lines, scene);
	link_cones(lines, scene);
	link_pyramids(lines, scene);
}
