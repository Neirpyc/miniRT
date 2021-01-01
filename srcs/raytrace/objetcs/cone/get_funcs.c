/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 12:35:42 by caugier           #+#    #+#             */
/*   Updated: 2020/12/30 23:40:48 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cone.h"

void	get_cone_funcs(t_funcs *funcs)
{
	funcs->get_t = get_cone_t;
	funcs->normal = get_cone_normal;
	funcs->intersect = cone_intersect;
	funcs->get_material = get_cone_material;
	funcs->move = move_cone;
	funcs->bounding_box = cone_bounding_box;
}
