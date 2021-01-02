/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 21:16:35 by caugier           #+#    #+#             */
/*   Updated: 2020/12/31 18:35:10 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"

static t_location	parse_first_part(size_t *pos, t_location *loc,
	char *line, t_cube *cube)
{
	int	ret;

	ret = parse_position(line, pos, &cube->center);
	err_line(line, gen_loc(loc, *pos, 1, 1), ret);
	ret = parse_rotation(line, pos, &cube->normal);
	err_line(line, gen_loc(loc, *pos, 2, 2), ret);
	ret = parse_float_0inf(line, pos, &cube->side);
	err_line(line, gen_loc(loc, *pos, 3, 3), ret);
	return (*loc);
}

void	parse_cube(t_list *lines, size_t line_nb, size_t *pos,
	t_scene_parse *scene)
{
	int			ret;
	t_location	loc;
	char		*line;
	t_cube		*cube;

	cube = gc_malloc(sizeof(t_cube));
	line = ((char *)lines->content);
	loc.line = line_nb;
	loc = parse_first_part(pos, &loc, line, cube);
	if (scene->version == FORMAT_DEFAULT)
	{
		cube->material = new_material();
		ret = parse_rgb(line, pos, &cube->material->color);
		err_line(line, gen_loc(&loc, *pos, 4, 4), ret);
	}
	else
	{
		ret = parse_p_long(line, pos, (signed long long *) & cube->material);
		err_line(line, gen_loc(&loc, *pos, 4, 4), ret);
	}
	ret = parse_endl(line, pos);
	err_line(line, gen_loc(&loc, *pos, 5, 5), ret);
	list_push_front(&(scene->scene->cubes.list), list_new(cube));
	list_push_front(&(scene->cubes_lines.list), list_new((void *)line_nb));
}
