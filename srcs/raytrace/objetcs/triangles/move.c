/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 23:31:29 by caugier           #+#    #+#             */
/*   Updated: 2020/12/31 20:02:05 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "triangles.h"

void	move_triangle(t_vec3 translation, t_vec3 rotation, t_any_obj *obj)
{
	double	tmp;

	add_vec3(&obj->cylinder->position, translation);
	rotation.x *= -1;
	tmp = rotation.y;
	rotation.y = -rotation.z;
	rotation.z = tmp;
	rotate_vec3(&obj->triangle->edge1, rotation);
	rotate_vec3(&obj->triangle->edge2, rotation);
	rotate_vec3(&obj->triangle->normal, rotation);
}
