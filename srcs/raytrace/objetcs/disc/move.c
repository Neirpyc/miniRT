/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 23:35:42 by caugier           #+#    #+#             */
/*   Updated: 2020/12/30 23:39:17 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disc.h"

void	move_disc(t_vec3 translation, t_vec3 rotation,
	t_any_obj *obj)
{
	add_vec3(&obj->disc->center, translation);
	rotation.x *= -1;
	rotation.y = -rotation.z;
	rotation.z = 0;
	rotate_vec3(&obj->disc->normal, rotation);
}
