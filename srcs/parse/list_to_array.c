/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 21:26:10 by caugier           #+#    #+#             */
/*   Updated: 2020/12/31 19:09:50 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_int.h"
#include "../gc_malloc/gc_malloc.h"
#include "../libft/libft.h"
#include "../raytrace/objetcs/objects.h"

static size_t	list_to_array(t_list *lst, size_t size, t_array *ptr)
{
	t_list	*current;
	t_list	*old;
	size_t	i;

	ptr->size = list_size(lst);
	ptr->array = gc_malloc(size * ptr->size);
	current = lst;
	i = ptr->size;
	while (i != 0)
	{
		i--;
		ft_memcpy((char *)ptr->array + i * size, current->content, size);
		old = current;
		current = current->next;
		gc_free(old->content);
		gc_free(old);
	}
	return (i);
}

t_scene	*scene_list_to_scene(t_list_scene *old)
{
	t_scene	*new;

	expand_compounds(old);
	new = gc_malloc(sizeof(t_scene));
	list_to_array(old->cameras.list, sizeof(t_camera), &new->cameras.array);
	new->materials = old->materials.list;
	list_to_array(old->lights.list, sizeof(t_light), &new->lights.array);
	list_to_array(old->p_lights.list, sizeof(t_parallel_light),
		&new->p_lights.array);
	new->objects.array.array
		= gc_malloc(sizeof(t_object) * object_count(old));
	new->objects.array.size = 0;
	fill_all_funcs(old, new);
	new->resolution = old->resolution;
	new->ambient = old->ambient;
	new->filter = old->filter;
	gc_free(old);
	return (new);
}
