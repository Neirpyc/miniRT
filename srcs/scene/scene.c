/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 19:46:15 by caugier           #+#    #+#             */
/*   Updated: 2020/12/31 19:33:29 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene_parse.h"
#include "../gc_malloc/gc_malloc.h"

void	free_scene(t_scene *scene)
{
	size_t	i;

	i = 0;
	while (i < scene->objects.array.size)
	{
		gc_free(scene->objects.objects.objects[i].object.sphere);
		i++;
	}
	gc_free(scene->objects.array.array);
	gc_free(scene->cameras.array.array);
	gc_free(scene->p_lights.array.array);
	list_clear(scene->materials);
	gc_free(scene->lights.array.array);
	gc_free(scene);
}
