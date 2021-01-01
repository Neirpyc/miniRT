/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 18:45:05 by caugier           #+#    #+#             */
/*   Updated: 2020/12/13 12:20:20 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"

static void	parse_last_part(size_t *pos, t_location *loc,
	char *line, t_material *material)
{
	int	ret;

	ret = parse_p_long(line, pos, &material->id);
	err_line(line, gen_loc(loc, *pos, 1, 1), ret);
	ret = parse_float_01(line, pos, &material->spec_k);
	err_line(line, gen_loc(loc, *pos, 2, 2), ret);
	ret = parse_float_1inf(line, pos, &material->refraction_indice);
	err_line(line, gen_loc(loc, *pos, 3, 3), ret);
	ret = parse_rgb(line, pos, &material->color);
	err_line(line, gen_loc(loc, *pos, 4, 4), ret);
	ret = parse_disruption(line, pos, &material->disruption);
	err_line(line, gen_loc(loc, *pos, 5, 5), ret);
	ret = parse_endl(line, pos);
	err_line(line, gen_loc(loc, *pos, 6, 6), ret);
}

void	parse_material(t_list *lines, size_t line_nb,
	size_t *pos, t_scene_parse *scene)
{
	t_location	loc;
	char		*line;
	t_material	*material;

	material = gc_malloc(sizeof(t_material));
	line = ((char *)lines->content);
	loc.line = line_nb;
	if (scene->version == FORMAT_DEFAULT)
	{
		*pos = 0;
		err_line(line, gen_loc(&loc, *pos, 0, 0), ERRCODE_MAT_WDEF);
	}
	parse_last_part(pos, &loc, line, material);
	list_push_front(&(scene->scene->materials.list), list_new(material));
	list_push_front(&(scene->materials_lines.list), list_new((void *)line_nb));
}
