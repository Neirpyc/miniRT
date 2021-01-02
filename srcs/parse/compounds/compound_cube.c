/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compound_cube.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 22:45:57 by caugier           #+#    #+#             */
/*   Updated: 2021/01/01 19:45:08 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../gc_malloc/gc_malloc.h"
#include "../../raytrace/raytrace_int.h"
#include "../parse_int.h"

static void	add_square(t_list_scene *scene, t_cube *cube, t_vec3 n)
{
	t_square	*square;

	square = gc_malloc(sizeof(t_square));
	square->material = cube->material;
	square->normal = n;
	square->side = cube->side;
	square->corner = cube->center;
	vec3_sub_noret(&square->corner, n);
	process_square(square);
	list_push_front(&scene->squares.list, list_new(square));
}

void	expand_cubes(t_list_scene *scene, t_cube_list cubes)
{
	t_vec3				n;
	t_vec3				aux;

	while (cubes.list != NULL)
	{
		n = cubes.cubes->content->normal;
		add_square(scene, cubes.cubes->content, n);
		scale_vec3(&n, -1);
		add_square(scene, cubes.cubes->content, n);
		vec3_cross(&n, *init_vec(&aux, 0, 0, -1));
		if (norm_vec3(n) == 0)
			init_vec(&n, 0, -1, 0);
		add_square(scene, cubes.cubes->content, n);
		scale_vec3(&n, -1);
		add_square(scene, cubes.cubes->content, n);
		vec3_cross(&n, cubes.cubes->content->normal);
		add_square(scene, cubes.cubes->content, n);
		scale_vec3(&n, -1);
		add_square(scene, cubes.cubes->content, n);
		cubes.list = cubes.list->next;
	}
}
