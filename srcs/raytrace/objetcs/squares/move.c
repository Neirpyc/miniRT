/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 23:16:12 by caugier           #+#    #+#             */
/*   Updated: 2020/12/30 23:30:06 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "squares.h"

void	move_square(t_vec3 translation, t_vec3 rotation, t_any_obj *obj)
{
	add_vec3(&obj->square->corner, translation);
	rotation.x *= -1;
	rotation.y = -rotation.z;
	rotation.z = 0;
	rotate_vec3(&obj->square->edge_1, rotation);
	rotate_vec3(&obj->square->edge_2, rotation);
	rotate_vec3(&obj->square->normal, rotation);
}
