/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 23:37:55 by caugier           #+#    #+#             */
/*   Updated: 2020/12/30 23:39:17 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"

void	move_cylinder(t_vec3 translation, t_vec3 rotation,
	t_any_obj *obj)
{
	add_vec3(&obj->cylinder->position, translation);
	rotation.x *= -1;
	rotation.y = -rotation.z;
	rotation.z = 0;
	rotate_vec3(&obj->cylinder->axis, rotation);
}
