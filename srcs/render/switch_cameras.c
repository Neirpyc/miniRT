/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_cameras.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 14:21:13 by caugier           #+#    #+#             */
/*   Updated: 2021/01/02 15:59:51 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void	sw_camera(t_render *rd, int d)
{
	rd->cam_id += d;
	while (rd->cam_id < 0)
		rd->cam_id += rd->scene->cameras.array.size;
	while (rd->cam_id >= (ssize_t)rd->scene->cameras.array.size)
		rd->cam_id -= rd->scene->cameras.array.size;
	render(&rd->scene->cameras.cameras.array[rd->cam_id]);
}

void	next_camera(t_render *rd)
{
	sw_camera(rd, 1);
}

void	prev_camera(t_render *rd)
{
	sw_camera(rd, -1);
}
