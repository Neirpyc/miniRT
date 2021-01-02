/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 20:40:57 by caugier           #+#    #+#             */
/*   Updated: 2021/01/02 16:34:44 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include <math.h>

void	parse_ambient(t_list *lines, size_t line_nb,
	size_t *pos, t_scene_parse *scene)
{
	int			ret;
	t_location	loc;
	char		*line;

	if (scene->ambient_line != -1)
		err_dup_line(lines, scene->ambient_line, line_nb, ERRCODE_AMB_RE);
	line = ((char *)lines->content);
	loc.line = line_nb;
	ret = parse_float_01(line, pos, &scene->scene->ambient.strength);
	err_line(line, gen_loc(&loc, *pos, 1, 1), ret);
	scene->scene->ambient.strength = 1 / (
		pow((1 - pow(scene->scene->ambient.strength, 1. / 10.)), 3)) - 1;
	ret = parse_rgb(line, pos, &scene->scene->ambient.color);
	err_line(line, gen_loc(&loc, *pos, 2, 2), ret);
	ret = parse_endl(line, pos);
	err_line(line, gen_loc(&loc, *pos, 3, 3), ret);
	scene->ambient_line = line_nb;
}
