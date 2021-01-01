/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 14:41:44 by caugier           #+#    #+#             */
/*   Updated: 2020/12/20 14:46:56 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "planes.h"

void	get_plane_funcs(t_funcs *funcs)
{
	funcs->get_t = plane_get_t;
	funcs->normal = get_plane_normal;
	funcs->intersect = plane_intersect;
	funcs->get_material = get_plane_material;
	funcs->move = move_plane;
	funcs->bounding_box = plane_bounding_box;
}
