/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 15:53:00 by caugier           #+#    #+#             */
/*   Updated: 2020/12/31 18:32:46 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include "../../raytrace/raytrace_int.h"

void	process_square(t_square *square)
{
	t_vec3	aux;

	square->edge_1 = square->normal;
	vec3_cross(&square->edge_1, *init_vec(&aux, 0, 0, -1));
	if (norm_vec3(square->edge_1) == 0)
		init_vec(&square->edge_1, 0, -1, 0);
	normalize_vec3_d(&square->edge_1, square->side);
	square->edge_2 = square->normal;
	vec3_cross(&square->edge_2, square->edge_1);
	normalize_vec3_d(&square->edge_2, square->side);
	aux = square->edge_1;
	scale_vec3(&aux, 0.5);
	vec3_sub_noret(&square->corner, aux);
	aux = square->edge_2;
	scale_vec3(&aux, 0.5);
	vec3_sub_noret(&square->corner, aux);
	square->side_squared = square->side * square->side - 1e-5;
}

static t_location	parse_first_part(size_t *pos, t_location *loc,
	char *line, t_square *square)
{
	int		ret;

	ret = parse_position(line, pos, &square->corner);
	err_line(line, gen_loc(loc, *pos, 1, 1), ret);
	ret = parse_rotation(line, pos, &square->normal);
	err_line(line, gen_loc(loc, *pos, 2, 2), ret);
	ret = parse_float_0inf(line, pos, &square->side);
	err_line(line, gen_loc(loc, *pos, 3, 3), ret);
	process_square(square);
	return (*loc);
}

void	parse_square(t_list *lines, size_t line_nb,
	size_t *pos, t_scene_parse *scene)
{
	int			ret;
	t_location	loc;
	char		*line;
	t_square	*square;

	square = gc_malloc(sizeof(t_square));
	line = ((char *)lines->content);
	loc.line = line_nb;
	loc = parse_first_part(pos, &loc, line, square);
	if (scene->version == FORMAT_DEFAULT)
	{
		square->material = new_material();
		ret = parse_rgb(line, pos, &square->material->color);
		err_line(line, gen_loc(&loc, *pos, 4, 4), ret);
	}
	else
	{
		ret = parse_p_long(line, pos, (signed long long *) & square->material);
		err_line(line, gen_loc(&loc, *pos, 4, 4), ret);
	}
	ret = parse_endl(line, pos);
	err_line(line, gen_loc(&loc, *pos, 5, 5), ret);
	list_push_front(&(scene->scene->squares.list), list_new(square));
	list_push_front(&(scene->squares_lines.list), list_new((void *)line_nb));
}
