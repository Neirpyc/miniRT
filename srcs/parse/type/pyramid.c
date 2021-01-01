/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pyramid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 21:16:53 by caugier           #+#    #+#             */
/*   Updated: 2020/12/31 18:33:49 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include <math.h>

static t_location	parse_first_part(size_t *pos, t_location *loc,
	char *line, t_pyramid *pyramid)
{
	int	ret;

	ret = parse_position(line, pos, &pyramid->tip);
	err_line(line, gen_loc(loc, *pos, 1, 1), ret);
	parse_rotation(line, pos, &pyramid->normal);
	err_line(line, gen_loc(loc, *pos, 2, 2), ret);
	ret = parse_float_0inf(line, pos, &pyramid->height);
	err_line(line, gen_loc(loc, *pos, 3, 3), ret);
	ret = parse_angle(line, pos, &pyramid->angle);
	err_line(line, gen_loc(loc, *pos, 4, 4), ret);
	pyramid->angle = pyramid->angle / 360 * M_PI;
	return (*loc);
}

void	parse_pyramid(t_list *lines, size_t line_nb, size_t *pos,
	t_scene_parse *scene)
{
	int			ret;
	t_location	loc;
	char		*line;
	t_pyramid	*pyramid;

	pyramid = gc_malloc(sizeof(t_pyramid));
	line = ((char *)lines->content);
	loc.line = line_nb;
	loc = parse_first_part(pos, &loc, line, pyramid);
	if (scene->version == FORMAT_DEFAULT)
	{
		pyramid->material = new_material();
		ret = parse_rgb(line, pos, &pyramid->material->color);
		err_line(line, gen_loc(&loc, *pos, 5, 5), ret);
	}
	else
	{
		ret = parse_p_long(line, pos, (signed long long *) & pyramid->material);
		err_line(line, gen_loc(&loc, *pos, 5, 5), ret);
	}
	ret = parse_endl(line, pos);
	err_line(line, gen_loc(&loc, *pos, 6, 6), ret);
	list_push_front(&(scene->scene->pyramids.list), list_new(pyramid));
	list_push_front(&(scene->pyramids_lines.list), list_new((void *)line_nb));
}
