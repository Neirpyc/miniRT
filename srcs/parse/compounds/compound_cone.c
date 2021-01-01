/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compound_cone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 11:50:48 by caugier           #+#    #+#             */
/*   Updated: 2020/12/27 12:42:25 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../gc_malloc/gc_malloc.h"
#include "../../raytrace/raytrace_int.h"
#include "../parse_int.h"
#include <math.h>

void	expand_cones(t_list_scene *scene, t_cone_list cones)
{
	t_disc	*disc;

	while (cones.list != NULL)
	{
		disc = gc_malloc(sizeof(t_disc));
		disc->center = cones.cones->content->direction;
		scale_vec3(&disc->center, cones.cones->content->height);
		add_vec3(&disc->center, cones.cones->content->position);
		disc->material = cones.cones->content->material;
		disc->normal = cones.cones->content->direction;
		disc->radius = tan(cones.cones->content->angle) * cones
			.cones->content->height;
		list_push_front(&scene->discs.list, list_new(disc));
		cones.list = cones.list->next;
	}
}
