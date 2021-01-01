/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_light.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 12:25:14 by caugier           #+#    #+#             */
/*   Updated: 2020/12/28 12:29:42 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include <math.h>

void	parse_p_light(t_list *lines, size_t line_nb,
	size_t *pos, t_scene_parse *scene)
{
	int					ret;
	t_location			loc;
	char				*line;
	t_parallel_light	*light;

	light = gc_malloc(sizeof(t_parallel_light));
	line = ((char *)lines->content);
	loc.line = line_nb;
	ret = parse_position(line, pos, &light->position);
	err_line(line, gen_loc(&loc, *pos, 1, 1), ret);
	ret = parse_rotation(line, pos, &light->normal);
	err_line(line, gen_loc(&loc, *pos, 2, 2), ret);
	ret = parse_float_01(line, pos, &light->strength);
	err_line(line, gen_loc(&loc, *pos, 3, 3), ret);
	light->strength = 1 / (pow((1 - pow(light->strength, 1. / 10.)), 3)) - 1;
	ret = parse_rgb(line, pos, &light->color);
	err_line(line, gen_loc(&loc, *pos, 4, 4), ret);
	ret = parse_endl(line, pos);
	err_line(line, gen_loc(&loc, *pos, 5, 5), ret);
	list_push_front(&(scene->scene->p_lights.list), list_new(light));
}
