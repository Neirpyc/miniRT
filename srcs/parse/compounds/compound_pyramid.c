/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compound_pyramid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 23:00:33 by caugier           #+#    #+#             */
/*   Updated: 2020/12/31 18:27:37 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../gc_malloc/gc_malloc.h"
#include "../../raytrace/raytrace_int.h"
#include "../parse_int.h"
#include <math.h>

static t_square	*add_pyramid_square(t_list_scene *scene, t_pyramid *pyramid)
{
	t_square	*square;

	square = gc_malloc(sizeof(t_square));
	square->material = pyramid->material;
	square->normal = pyramid->normal;
	square->side = tan(pyramid->angle) * pyramid->height * 2;
	square->corner = pyramid->normal;
	scale_vec3(&square->corner, pyramid->height);
	add_vec3(&square->corner, pyramid->tip);
	process_square(square);
	list_push_front(&scene->squares.list, list_new(square));
	return (square);
}

static void	add_triangle(t_list_scene *scene, t_pyramid *pyramid,
	t_vec3 e0, t_vec3 e1)
{
	t_triangle	*triangle;

	triangle = gc_malloc(sizeof(t_triangle));
	triangle->material = pyramid->material;
	triangle->corner = pyramid->tip;
	triangle->edge1 = e0;
	triangle->edge2 = e1;
	triangle->normal = triangle->edge1;
	vec3_cross(&triangle->normal, triangle->edge2);
	list_push_front(&scene->triangles.list, list_new(triangle));
}

void	expand_pyramids(t_list_scene *scene, t_pyramid_list pyramids)
{
	t_square		*sq;
	t_vec3			e0;
	t_vec3			e1;

	while (pyramids.list != NULL)
	{
		sq = add_pyramid_square(scene, pyramids.pyramids->content);
		e0 = sq->corner;
		vec3_sub_noret(&e0, pyramids.pyramids->content->tip);
		e1 = e0;
		add_vec3(&e1, sq->edge_1);
		add_triangle(scene, pyramids.pyramids->content, e0, e1);
		e0 = e1;
		add_vec3(&e0, sq->edge_2);
		add_triangle(scene, pyramids.pyramids->content, e0, e1);
		e1 = e0;
		vec3_sub_noret(&e1, sq->edge_1);
		add_triangle(scene, pyramids.pyramids->content, e0, e1);
		e0 = e1;
		vec3_sub_noret(&e0, sq->edge_2);
		add_triangle(scene, pyramids.pyramids->content, e0, e1);
		pyramids.list = pyramids.list->next;
	}
}
