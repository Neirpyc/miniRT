/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 21:00:55 by caugier           #+#    #+#             */
/*   Updated: 2020/12/20 21:00:55 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raytrace_int.h"

inline void	vec3_cross(t_vec3 *v1, t_vec3 v2)
{
	t_vec3	aux;

	aux = *v1;
	v1->x = aux.y * v2.z - aux.z * v2.y;
	v1->y = aux.z * v2.x - aux.x * v2.z;
	v1->z = aux.x * v2.y - aux.y * v2.x;
}
