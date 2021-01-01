/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 21:16:03 by caugier           #+#    #+#             */
/*   Updated: 2020/12/27 16:20:34 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include <math.h>

static t_location	parse_first_part(size_t *pos, t_location *loc,
	char *line, t_cone *cone)
{
	int		ret;
	double	base;

	ret = parse_position(line, pos, &cone->position);
	err_line(line, gen_loc(loc, *pos, 1, 1), ret);
	parse_rotation(line, pos, &cone->direction);
	err_line(line, gen_loc(loc, *pos, 2, 2), ret);
	ret = parse_float_0inf(line, pos, &cone->height);
	err_line(line, gen_loc(loc, *pos, 3, 3), ret);
	ret = parse_angle(line, pos, &cone->angle);
	err_line(line, gen_loc(loc, *pos, 4, 4), ret);
	cone->angle = cone->angle / 360 * M_PI;
	cone->cos = cos(cone->angle);
	cone->cos_sq = cone->cos * cone->cos;
	base = tan(cone->angle) * cone->height;
	cone->max_dst = sqrt(cone->height * cone->height + base * base);
	return (*loc);
}

void	parse_cone(t_list *lines, size_t line_nb, size_t *pos,
	t_scene_parse *scene)
{
	int			ret;
	t_location	loc;
	char		*line;
	t_cone		*cone;

	cone = gc_malloc(sizeof(t_cone));
	line = ((char *)lines->content);
	loc.line = line_nb;
	loc = parse_first_part(pos, &loc, line, cone);
	if (scene->version == FORMAT_DEFAULT)
	{
		cone->material = new_material();
		ret = parse_rgb(line, pos, &cone->material->color);
		err_line(line, gen_loc(&loc, *pos, 5, 5), ret);
	}
	else
	{
		ret = parse_p_long(line, pos, (signed long long *) & cone->material);
		err_line(line, gen_loc(&loc, *pos, 5, 5), ret);
	}
	ret = parse_endl(line, pos);
	err_line(line, gen_loc(&loc, *pos, 6, 6), ret);
	list_push_front(&(scene->scene->cones.list), list_new(cone));
	list_push_front(&(scene->cones_lines.list), list_new((void *)line_nb));
}
