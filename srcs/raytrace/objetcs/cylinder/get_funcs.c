/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 13:43:33 by caugier           #+#    #+#             */
/*   Updated: 2020/12/30 23:39:17 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"

void	get_cylinder_funcs(t_funcs *funcs)
{
	funcs->normal = get_cylinder_normal;
	funcs->get_t = get_cylinder_t;
	funcs->get_material = get_cylinder_material;
	funcs->intersect = cylinder_intersect;
	funcs->move = move_cylinder;
	funcs->bounding_box = cylinder_bounding_box;
}
