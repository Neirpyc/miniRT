/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bounding_box.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 00:01:44 by caugier           #+#    #+#             */
/*   Updated: 2020/12/31 00:36:31 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "spheres.h"

void	sphere_bounding_box(t_bounding_box *bounding_box, t_any_obj *obj)
{
	bounding_box->x.min = obj->sphere->position.x - obj->sphere->radius;
	bounding_box->x.max = obj->sphere->position.x + obj->sphere->radius;
	bounding_box->y.min = obj->sphere->position.y - obj->sphere->radius;
	bounding_box->y.max = obj->sphere->position.y + obj->sphere->radius;
	bounding_box->z.min = obj->sphere->position.z - obj->sphere->radius;
	bounding_box->z.max = obj->sphere->position.z + obj->sphere->radius;
}
