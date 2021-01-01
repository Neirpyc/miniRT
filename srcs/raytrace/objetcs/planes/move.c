/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 23:03:50 by caugier           #+#    #+#             */
/*   Updated: 2020/12/30 23:03:50 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "planes.h"

void	move_plane(t_vec3 translation, t_vec3 rotation, t_any_obj *obj)
{
	add_vec3(&obj->plane->position, translation);
	rotation.x *= -1;
	rotation.y = -rotation.z;
	rotation.z = 0;
	rotate_vec3(&obj->plane->normal, rotation);
}
