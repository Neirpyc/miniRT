/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_parse.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 14:52:31 by caugier           #+#    #+#             */
/*   Updated: 2020/12/31 19:29:03 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_PARSE_H
# define SCENE_PARSE_H

# include "scene_list.h"

# define FORMAT_DEFAULT 0u
# define FORMAT_BONUS 1u

typedef struct s_line_list {
	unsigned long long int nbr : sizeof(void *) * 8;
	struct s_line_list		*next;
}							t_int_line_list;

typedef union u_id_line_list {
	t_list					*list;
	t_int_line_list			*id_line_list;
}							t_id_line_list;

typedef struct s_scene_parse {
	t_id_line_list			materials_lines;
	t_id_line_list			spheres_lines;
	t_id_line_list			planes_lines;
	t_id_line_list			squares_lines;
	t_id_line_list			cylinders_lines;
	t_id_line_list			triangles_lines;
	t_id_line_list			cones_lines;
	t_id_line_list			cubes_lines;
	t_id_line_list			pyramids_lines;
	t_list_scene			*scene;
	int						resolution_line;
	int						ambient_line;
	int						filter_line;
	unsigned int			version : 1;
}							t_scene_parse;

typedef struct s_camera_parse {
	t_position				position;
	t_rotation				rotation;
	double					fov;
	int						bounces;
	int						sub_pixels;
}							t_camera_parse;

typedef enum e_obj_type {
	render_size,
	ambient,
	camera,
	light,
	sphere,
	plane,
	square,
	cylinder,
	triangle,
	material,
	cone,
	pyramid,
	cube,
	p_light,
	filter,
}							t_obj_type;

#endif
