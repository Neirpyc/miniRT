/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 14:41:44 by caugier           #+#    #+#             */
/*   Updated: 2020/12/30 23:37:22 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disc.h"

void	get_disc_funcs(t_funcs *funcs)
{
	funcs->get_t = disc_get_t;
	funcs->normal = get_disc_normal;
	funcs->intersect = disc_intersect;
	funcs->get_material = get_disc_material;
	funcs->move = move_disc;
	funcs->bounding_box = disc_bounding_box;
}
