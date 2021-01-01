/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 13:33:21 by caugier           #+#    #+#             */
/*   Updated: 2020/12/30 23:13:12 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "spheres.h"

void	get_sphere_funcs(t_funcs *funcs)
{
	funcs->get_t = get_sphere_t;
	funcs->normal = get_sphere_normal;
	funcs->get_material = get_sphere_material;
	funcs->intersect = sphere_intersect;
	funcs->move = move_sphere;
	funcs->bounding_box = sphere_bounding_box;
}
