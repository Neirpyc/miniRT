/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 21:28:58 by caugier           #+#    #+#             */
/*   Updated: 2020/12/30 23:33:51 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "triangles.h"

void	get_triangle_funcs(t_funcs *funcs)
{
	funcs->get_t = triangle_get_t;
	funcs->normal = get_triangle_normal;
	funcs->intersect = triangle_intersect;
	funcs->get_material = get_triangle_material;
	funcs->move = move_triangle;
	funcs->bounding_box = triangle_bounding_box;
}
