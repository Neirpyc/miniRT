/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 16:04:27 by caugier           #+#    #+#             */
/*   Updated: 2020/12/12 16:04:27 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raytrace_int.h"

inline t_vec3	*vec3_sub(t_vec3 *dst, t_vec3 src)
{
	dst->x -= src.x;
	dst->y -= src.y;
	dst->z -= src.z;
	return (dst);
}

inline void	vec3_sub_noret(t_vec3 *dst, t_vec3 src)
{
	dst->x -= src.x;
	dst->y -= src.y;
	dst->z -= src.z;
}
