/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_objetcs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 17:27:03 by caugier           #+#    #+#             */
/*   Updated: 2020/12/30 17:27:03 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_int.h"

static void	sw_obj(t_render *rd, int d)
{
	rd->obj_id += d;
	while (rd->obj_id < 0)
		rd->obj_id += rd->scene->objects.array.size;
	while (rd->obj_id >= (ssize_t)rd->scene->objects.array.size)
		rd->obj_id -= rd->scene->objects.array.size;
}

void	next_object(t_render *rd)
{
	sw_obj(rd, 1);
}

void	prev_object(t_render *rd)
{
	sw_obj(rd, -1);
}
