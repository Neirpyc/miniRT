/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bounding_box.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 00:01:44 by caugier           #+#    #+#             */
/*   Updated: 2020/12/31 00:01:44 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "triangles.h"

void	triangle_bounding_box(t_bounding_box *bounding_box, t_any_obj *obj)
{
	t_vec3	pts[4];

	pts[0] = obj->triangle->corner;
	pts[1] = pts[0];
	add_vec3(&pts[1], obj->triangle->edge1);
	pts[2] = pts[0];
	add_vec3(&pts[2], obj->triangle->edge2);
	pts[3] = pts[2];
	add_vec3(&pts[3], obj->triangle->edge1);
	points_to_bb(bounding_box, pts);
}
