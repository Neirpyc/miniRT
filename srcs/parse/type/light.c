/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 18:45:05 by caugier           #+#    #+#             */
/*   Updated: 2020/12/17 19:45:43 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include <math.h>

void	parse_light(t_list *lines, size_t line_nb,
	size_t *pos, t_scene_parse *scene)
{
	int			ret;
	t_location	loc;
	char		*line;
	t_light		*light;

	light = gc_malloc(sizeof(t_light));
	line = ((char *)lines->content);
	loc.line = line_nb;
	ret = parse_position(line, pos, &light->position);
	err_line(line, gen_loc(&loc, *pos, 1, 1), ret);
	ret = parse_float_01(line, pos, &light->strength);
	err_line(line, gen_loc(&loc, *pos, 2, 2), ret);
	light->strength = 1 / (pow((1 - pow(light->strength, 1. / 10.)), 3)) - 1;
	ret = parse_rgb(line, pos, &light->color);
	err_line(line, gen_loc(&loc, *pos, 3, 3), ret);
	ret = parse_endl(line, pos);
	err_line(line, gen_loc(&loc, *pos, 4, 4), ret);
	list_push_front(&(scene->scene->lights.list), list_new(light));
}
