/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compound_cylinder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 22:17:38 by caugier           #+#    #+#             */
/*   Updated: 2020/12/26 22:44:14 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../gc_malloc/gc_malloc.h"
#include "../../raytrace/raytrace_int.h"
#include "../parse_int.h"
#include <math.h>

static void	add_disc(t_list_scene *scene, t_cylinder *cylinder, t_vec3 pos)
{
	t_disc	*disc;

	disc = gc_malloc(sizeof(t_disc));
	disc->normal = cylinder->axis;
	disc->material = cylinder->material;
	disc->center = pos;
	disc->radius = sqrt(cylinder->rad_sq);
	list_push_front(&scene->discs.list, list_new(disc));
}

void	expand_cylinders(t_list_scene *scene, t_cylinder_list cylinders)
{
	t_vec3				aux;

	while (cylinders.list != NULL)
	{
		aux = cylinders.cylinders->content->axis;
		scale_vec3(&aux, cylinders.cylinders->content->height / 2);
		add_vec3(&aux, cylinders.cylinders->content->position);
		add_disc(scene, cylinders.cylinders->content, aux);
		aux = cylinders.cylinders->content->axis;
		scale_vec3(&aux, -cylinders.cylinders->content->height / 2);
		add_vec3(&aux, cylinders.cylinders->content->position);
		add_disc(scene, cylinders.cylinders->content, aux);
		cylinders.list = cylinders.list->next;
	}
}
