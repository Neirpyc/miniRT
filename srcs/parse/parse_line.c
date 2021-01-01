/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 22:40:35 by caugier           #+#    #+#             */
/*   Updated: 2020/12/31 22:57:14 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_int.h"
#include "../libft/libft.h"
#include "type/type.h"

static size_t	word_len(char *word)
{
	size_t	s;

	s = 0;
	while (!ft_isspace(*word) && *word != '\0')
	{
		word++;
		s++;
	}
	return (s);
}

static int	two_id(const char *line, size_t *pos, t_obj_type *type)
{
	if (line[*pos] == 's' && line[*pos + 1] == 'p')
		*type = sphere;
	else if (line[*pos] == 'p' && line[*pos + 1] == 'l')
		*type = plane;
	else if (line[*pos] == 's' && line[*pos + 1] == 'q')
		*type = square;
	else if (line[*pos] == 'c' && line[*pos + 1] == 'y')
		*type = cylinder;
	else if (line[*pos] == 't' && line[*pos + 1] == 'r')
		*type = triangle;
	else if (line[*pos] == 'm' && line[*pos + 1] == 'a')
		*type = material;
	else if (line[*pos] == 'c' && line[*pos + 1] == 'u')
		*type = cube;
	else if (line[*pos] == 'p' && line[*pos + 1] == 'y')
		*type = pyramid;
	else if (line[*pos] == 'c' && line[*pos + 1] == 'o')
		*type = cone;
	else if (line[*pos] == 'i' && line[*pos + 1] == 'l')
		*type = p_light;
	else
		return (-1);
	(*pos) += 2;
	return (0);
}

const char				g_one_char_specifiers[] = {'R', 'A', 'c', 'l', 'F'};
const t_obj_type		g_one_char_types[] = {render_size, ambient, camera,
										light, filter};

static int	get_type(char *line, size_t *pos, t_obj_type *type)
{
	size_t	s;

	s = word_len(line);
	if (s != 1 && s != 2)
		return (-1);
	if (s == 1)
	{
		s = sizeof(g_one_char_specifiers) / sizeof(*g_one_char_specifiers);
		while (s > 0)
		{
			s--;
			if (g_one_char_specifiers[s] == line[*pos])
			{
				(*pos)++;
				*type = g_one_char_types[s];
				return (0);
			}
		}
	}
	else if (two_id(line, pos, type) == -1)
		return (-1);
	if (ft_isspace(line[*pos]))
		return (0);
	return (-1);
}

static int	is_line_empty(char *line)
{
	while (ft_isspace(*line))
		line++;
	if (*line == '\0')
		return (1);
	return (0);
}

const t_obj_type		g_types[] = {render_size, ambient, camera, light,
							   sphere, plane, square, cylinder, triangle,
							   material, cone, pyramid, cube, p_light, filter};
const t_parse_func		g_funcs[]
	= {parse_resolution, parse_ambient, parse_camera, parse_light,
	parse_sphere, parse_plane, parse_square, parse_cylinder, parse_triangle,
	parse_material, parse_cone, parse_pyramid, parse_cube, parse_p_light,
	parse_filter};

void	parse_line(char *line, t_scene_parse *scene,
	size_t current_line, t_list *lines)
{
	t_obj_type	type;
	size_t		pos;
	t_location	loc;
	size_t		i;

	if (current_line == 0)
		scene->version = is_bonus(lines, &pos);
	if (is_line_empty(line) == 1
		|| (scene->version == FORMAT_BONUS && current_line == 0))
		return ;
	pos = 0;
	loc.line = current_line;
	if (get_type(line, &pos, &type) != 0)
		err_line(line, gen_loc(&loc, 0, 0, 0), ERRCODE_UNK_TYPE);
	i = sizeof(g_funcs) / sizeof(*g_funcs);
	while (i > 0)
	{
		i--;
		if (type == g_types[i])
		{
			g_funcs[i](lines, current_line, &pos, scene);
			break ;
		}
	}
}
