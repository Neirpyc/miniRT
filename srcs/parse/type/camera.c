/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 20:40:57 by caugier           #+#    #+#             */
/*   Updated: 2020/12/31 18:36:23 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include <math.h>
#include "../../raytrace/raytrace_int.h"

void	process_cameras(t_list_scene *scene, t_camera_list cams)
{
	t_vec3			aux;
	t_camera_parse	*old_cam;
	t_camera		*new_cam;

	if (cams.list == NULL)
		return ;
	old_cam = (t_camera_parse *)cams.cameras->content;
	new_cam = gc_malloc(sizeof(t_camera));
	new_cam->origin = old_cam->position;
	new_cam->normal = old_cam->rotation;
	new_cam->d_x = new_cam->normal;
	vec3_cross(&new_cam->d_x, *init_vec(&aux, 0, 0, -1));
	if (norm_vec3(new_cam->d_x) == 0)
		init_vec(&new_cam->d_x, 0, -1, 0);
	normalize_vec3_d(&new_cam->d_x, tan(old_cam->fov * M_PI / 360));
	new_cam->d_y = new_cam->normal;
	vec3_cross(&new_cam->d_y, new_cam->d_x);
	normalize_vec3_d(&new_cam->d_y, (double)scene->resolution.height
	/ (double)scene->resolution.width * tan(old_cam->fov * M_PI / 360));
	new_cam->bounces = old_cam->bounces;
	new_cam->sub_pixels = old_cam->sub_pixels;
	gc_free(cams.cameras->content);
	cams.cameras->content = new_cam;
	process_cameras(scene, (t_camera_list)cams.cameras->next);
}

static void	parse_first_part(size_t *pos, t_location *loc,
	char *line, t_camera_parse *cam)
{
	int	ret;

	ret = parse_position(line, pos, &cam->position);
	err_line(line, gen_loc(loc, *pos, 1, 1), ret);
	ret = parse_rotation(line, pos, &cam->rotation);
	err_line(line, gen_loc(loc, *pos, 2, 2), ret);
	ret = parse_180_dbl(line, pos, &cam->fov);
	err_line(line, gen_loc(loc, *pos, 3, 3), ret);
}

void	parse_camera(t_list *lines, size_t line_nb,
	size_t *pos, t_scene_parse *scene)
{
	int				ret;
	t_location		loc;
	char			*line;
	t_camera_parse	*cam;

	cam = gc_malloc(sizeof(t_camera_parse));
	line = ((char *)lines->content);
	loc.line = line_nb;
	parse_first_part(pos, &loc, line, cam);
	if (scene->version == FORMAT_BONUS)
	{
		ret = parse_p_int(line, pos, &cam->bounces);
		err_line(line, gen_loc(&loc, *pos, 4, 4), ret);
		ret = parse_p_int(line, pos, &cam->sub_pixels);
		err_line(line, gen_loc(&loc, *pos, 5, 5), ret);
		ret = parse_endl(line, pos);
		err_line(line, gen_loc(&loc, *pos, 6, 6), ret);
	}
	else
	{
		cam->bounces = 3;
		cam->sub_pixels = 1;
		err_line(line, gen_loc(&loc, *pos, 4, 4), parse_endl(line, pos));
	}
	list_push_front(&(scene->scene->cameras.list), list_new(cam));
}
