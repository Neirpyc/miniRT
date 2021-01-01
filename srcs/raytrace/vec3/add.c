/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 19:18:21 by caugier           #+#    #+#             */
/*   Updated: 2020/12/11 19:29:02 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raytrace_int.h"

inline t_vec3	*add_vec3(t_vec3 *dst, t_vec3 src)
{
	dst->x += src.x;
	dst->y += src.y;
	dst->z += src.z;
	return (dst);
}
