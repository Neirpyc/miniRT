/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 18:19:01 by caugier           #+#    #+#             */
/*   Updated: 2020/12/10 21:58:23 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
# define TYPE_H

# include "../parse_int.h"
# include "../../gc_malloc/gc_malloc.h"

void	parse_resolution(t_list *lines, size_t line_nb, size_t *pos,
	t_scene_parse *scene);
void	parse_ambient(t_list *lines, size_t line_nb, size_t *pos,
	t_scene_parse *scene);
void	parse_camera(t_list *lines, size_t line_nb, size_t *pos,
	t_scene_parse *scene);
void	parse_light(t_list *lines, size_t line_nb, size_t *pos,
	t_scene_parse *scene);
void	parse_material(t_list *lines, size_t line_nb, size_t *pos,
	t_scene_parse *scene);
void	parse_sphere(t_list *lines, size_t line_nb, size_t *pos,
	t_scene_parse *scene);
void	parse_plane(t_list *lines, size_t line_nb, size_t *pos,
	t_scene_parse *scene);
void	parse_square(t_list *lines, size_t line_nb, size_t *pos,
	t_scene_parse *scene);
void	parse_cylinder(t_list *lines, size_t line_nb, size_t *pos,
	t_scene_parse *scene);
void	parse_triangle(t_list *lines, size_t line_nb, size_t *pos,
	t_scene_parse *scene);
void	parse_cone(t_list *lines, size_t line_nb, size_t *pos,
	t_scene_parse *scene);
void	parse_cube(t_list *lines, size_t line_nb, size_t *pos,
	t_scene_parse *scene);
void	parse_pyramid(t_list *lines, size_t line_nb, size_t *pos,
	t_scene_parse *scene);
void	parse_p_light(t_list *lines, size_t line_nb,
	size_t *pos, t_scene_parse *scene);
void	parse_filter(t_list *lines, size_t line_nb,
	size_t *pos, t_scene_parse *scene);

void	process_cameras(t_list_scene *scene, t_camera_list cams);

#endif
