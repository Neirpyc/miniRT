/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 15:46:55 by caugier           #+#    #+#             */
/*   Updated: 2020/12/31 18:40:40 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include "../../raytrace/raytrace_int.h"

static t_location	parse_first_part(size_t *pos, t_location *loc,
	char *line, t_plane *plane)
{
	int	ret;

	ret = parse_position(line, pos, &plane->position);
	err_line(line, gen_loc(loc, *pos, 1, 1), ret);
	ret = parse_rotation(line, pos, &plane->normal);
	err_line(line, gen_loc(loc, *pos, 2, 2), ret);
	return (*loc);
}

void	parse_plane(t_list *lines, size_t line_nb, size_t *pos,
	t_scene_parse *scene)
{
	int			ret;
	t_location	loc;
	char		*line;
	t_plane		*plane;

	plane = gc_malloc(sizeof(t_plane));
	line = ((char *)lines->content);
	loc.line = line_nb;
	loc = parse_first_part(pos, &loc, line, plane);
	if (scene->version == FORMAT_DEFAULT)
	{
		plane->material = new_material();
		ret = parse_rgb(line, pos, &plane->material->color);
		err_line(line, gen_loc(&loc, *pos, 3, 3), ret);
	}
	else
	{
		ret = parse_p_long(line, pos, (signed long long *) & plane->material);
		err_line(line, gen_loc(&loc, *pos, 3, 3), ret);
	}
	ret = parse_endl(line, pos);
	err_line(line, gen_loc(&loc, *pos, 4, 4), ret);
	list_push_front(&(scene->scene->planes.list), list_new(plane));
	list_push_front(&(scene->planes_lines.list), list_new((void *)line_nb));
}
