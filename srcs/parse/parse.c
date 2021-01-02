/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 18:12:12 by caugier           #+#    #+#             */
/*   Updated: 2021/01/01 20:47:06 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_int.h"
#include "../gc_malloc/gc_malloc.h"
#include "../fd_until/fd_until.h"
#include "../libft/libft.h"
#include "type/type.h"
#include <fcntl.h>
#include <unistd.h>

static t_scene_parse	*new_scene(void)
{
	t_scene_parse	*scene;

	scene = gc_malloc(sizeof(t_scene_parse));
	ft_memset(scene, 0, sizeof(t_scene_parse));
	scene->scene = gc_malloc(sizeof(t_list_scene));
	ft_memset(scene->scene, 0, sizeof(t_list_scene));
	scene->ambient_line = -1;
	scene->resolution_line = -1;
	scene->filter_line = -1;
	scene->scene->filter = filter_none;
	return (scene);
}

static t_list_scene	*post_parse(t_list *lines,
	t_list *elem, t_scene_parse *scene)
{
	validate_scene(lines, scene);
	list_clear(lines);
	process_cameras(scene->scene, scene->scene->cameras);
	elem = (t_list *)scene->scene;
	list_free(scene->planes_lines.list);
	list_free(scene->spheres_lines.list);
	list_free(scene->triangles_lines.list);
	list_free(scene->squares_lines.list);
	list_free(scene->cylinders_lines.list);
	list_free(scene->materials_lines.list);
	list_free(scene->cones_lines.list);
	list_free(scene->pyramids_lines.list);
	list_free(scene->cubes_lines.list);
	gc_free(scene);
	return ((t_list_scene *)elem);
}

static t_list_scene	*parse_lines(int fd)
{
	t_list			*lines;
	t_list			*elem;
	ssize_t			ret;
	t_scene_parse	*scene;
	size_t			i;

	scene = new_scene();
	i = 0;
	lines = NULL;
	while (1)
	{
		elem = list_new(NULL);
		list_push_front(&lines, elem);
		ret = fd_read_until(fd, (char **) & elem->content, '\n');
		if (ret < -1)
		{
			ft_put_strerror(ERRCODE_RD_UNTIL);
			gc_exit(-1);
		}
		if (ret == -1)
			break ;
		parse_line(elem->content, scene, i++, lines);
	}
	return (post_parse(lines, elem, scene));
}

t_scene	*parse(int argc, char **argv)
{
	t_input			input;
	t_list_scene	*scene;
	t_scene			*ret;
	int				fd;

	parse_args(argc, argv, &input);
	fd = gc_open(input.rt_file, O_RDONLY);
	scene = parse_lines(fd);
	gc_close(fd);
	ret = scene_list_to_scene(scene);
	ret->save = input.save;
	return (ret);
}
