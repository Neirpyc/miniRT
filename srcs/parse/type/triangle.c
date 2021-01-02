/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 16:02:27 by caugier           #+#    #+#             */
/*   Updated: 2020/12/21 15:38:58 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include "../../raytrace/raytrace_int.h"

static t_location	parse_first_part(size_t *pos, t_location *loc,
	char *line, t_triangle *triangle)
{
	int		ret;
	t_vec3	aux;

	ret = parse_position(line, pos, &triangle->corner);
	err_line(line, gen_loc(loc, *pos, 1, 1), ret);
	ret = parse_position(line, pos, &aux);
	err_line(line, gen_loc(loc, *pos, 2, 2), ret);
	triangle->edge1 = aux;
	vec3_sub_noret(&triangle->edge1, triangle->corner);
	ret = parse_position(line, pos, &aux);
	err_line(line, gen_loc(loc, *pos, 3, 3), ret);
	triangle->edge2 = aux;
	vec3_sub_noret(&triangle->edge2, triangle->corner);
	triangle->normal = triangle->edge1;
	vec3_cross(&triangle->normal, triangle->edge2);
	if (norm_vec3(triangle->normal) == 0)
		err_line(line, gen_loc(loc, --(*pos), 1, 3), ERRCODE_COL_PTS_TRGL);
	normalize_vec3(&triangle->normal);
	return (*loc);
}

void	parse_triangle(t_list *lines, size_t line_nb,
	size_t *pos, t_scene_parse *scene)
{
	int			ret;
	t_location	loc;
	char		*line;
	t_triangle	*triangle;

	triangle = gc_malloc(sizeof(t_triangle));
	line = ((char *)lines->content);
	loc.line = line_nb;
	loc = parse_first_part(pos, &loc, line, triangle);
	if (scene->version == FORMAT_DEFAULT)
	{
		triangle->material = new_material();
		ret = parse_rgb(line, pos, &triangle->material->color);
		err_line(line, gen_loc(&loc, *pos, 4, 4), ret);
	}
	else
	{
		ret = parse_p_long(line, pos,
				(signed long long *) & triangle->material);
		err_line(line, gen_loc(&loc, *pos, 4, 4), ret);
	}
	ret = parse_endl(line, pos);
	err_line(line, gen_loc(&loc, *pos, 5, 5), ret);
	list_push_front(&(scene->scene->triangles.list), list_new(triangle));
	list_push_front(&(scene->triangles_lines.list), list_new((void *)line_nb));
}
