/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 20:53:47 by caugier           #+#    #+#             */
/*   Updated: 2020/12/09 17:44:31 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"

static t_location	parse_first_part(size_t *pos, t_location *loc,
	char *line, t_sphere *sphere)
{
	int	ret;

	ret = parse_position(line, pos, &sphere->position);
	err_line(line, gen_loc(loc, *pos, 1, 1), ret);
	ret = parse_float_0inf(line, pos, &sphere->radius);
	sphere->radius /= 2;
	err_line(line, gen_loc(loc, *pos, 2, 2), ret);
	sphere->radius_sq = sphere->radius * sphere->radius;
	return (*loc);
}

void	parse_sphere(t_list *lines, size_t line_nb,
	size_t *pos, t_scene_parse *scene)
{
	int			ret;
	t_location	loc;
	char		*line;
	t_sphere	*sphere;

	sphere = gc_malloc(sizeof(t_sphere));
	line = ((char *)lines->content);
	loc.line = line_nb;
	loc = parse_first_part(pos, &loc, line, sphere);
	if (scene->version == FORMAT_DEFAULT)
	{
		sphere->material = new_material();
		ret = parse_rgb(line, pos, &sphere->material->color);
		err_line(line, gen_loc(&loc, *pos, 3, 3), ret);
	}
	else
	{
		ret = parse_p_long(line, pos, (signed long long *) & sphere->material);
		err_line(line, gen_loc(&loc, *pos, 3, 3), ret);
	}
	ret = parse_endl(line, pos);
	err_line(line, gen_loc(&loc, *pos, 4, 4), ret);
	list_push_front(&(scene->scene->spheres.list), list_new(sphere));
	list_push_front(&(scene->spheres_lines.list), list_new((void *)line_nb));
}
