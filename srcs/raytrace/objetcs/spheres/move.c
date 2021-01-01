/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 23:12:29 by caugier           #+#    #+#             */
/*   Updated: 2020/12/30 23:12:29 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "spheres.h"

void	move_sphere(t_vec3 translation, t_vec3 rotation, t_any_obj *obj)
{
	(void)rotation;
	add_vec3(&obj->plane->position, translation);
}
