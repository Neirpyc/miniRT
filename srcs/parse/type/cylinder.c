/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 15:59:59 by caugier           #+#    #+#             */
/*   Updated: 2020/12/31 18:38:39 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include "../../raytrace/raytrace_int.h"
#include <math.h>

static t_location	parse_first_part(size_t *pos, t_location *loc,
	char *line, t_cylinder *cylinder)
{
	int	ret;

	ret = parse_position(line, pos, &cylinder->position);
	err_line(line, gen_loc(loc, *pos, 1, 1), ret);
	ret = parse_rotation(line, pos, &cylinder->axis);
	err_line(line, gen_loc(loc, *pos, 2, 2), ret);
	ret = parse_float_0inf(line, pos, &cylinder->radius);
	cylinder->radius /= 2;
	err_line(line, gen_loc(loc, *pos, 3, 3), ret);
	cylinder->rad_sq = cylinder->radius * cylinder->radius;
	ret = parse_float_0inf(line, pos, &cylinder->height);
	err_line(line, gen_loc(loc, *pos, 4, 4), ret);
	cylinder->max_offset = sqrt(cylinder->height * cylinder->height / 4
			+ cylinder->rad_sq);
	return (*loc);
}

void	parse_cylinder(t_list *lines, size_t line_nb,
	size_t *pos, t_scene_parse *scene)
{
	int			ret;
	t_location	loc;
	char		*line;
	t_cylinder	*cylinder;

	cylinder = gc_malloc(sizeof(t_cylinder));
	line = ((char *)lines->content);
	loc.line = line_nb;
	loc = parse_first_part(pos, &loc, line, cylinder);
	if (scene->version == FORMAT_DEFAULT)
	{
		cylinder->material = new_material();
		ret = parse_rgb(line, pos, &cylinder->material->color);
		err_line(line, gen_loc(&loc, *pos, 5, 5), ret);
	}
	else
	{
		ret = parse_p_long(line, pos,
				(signed long long *) & cylinder->material);
		err_line(line, gen_loc(&loc, *pos, 5, 5), ret);
	}
	ret = parse_endl(line, pos);
	err_line(line, gen_loc(&loc, *pos, 6, 6), ret);
	list_push_front(&(scene->scene->cylinders.list), list_new(cylinder));
	list_push_front(&(scene->cylinders_lines.list), list_new((void *)line_nb));
}
