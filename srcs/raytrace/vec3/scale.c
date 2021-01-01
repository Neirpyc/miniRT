/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 18:50:22 by caugier           #+#    #+#             */
/*   Updated: 2020/12/31 17:45:15 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raytrace_int.h"

inline t_vec3	*scale_vec3(t_vec3 *vec, double scale_f)
{
	vec->x *= scale_f;
	vec->y *= scale_f;
	vec->z *= scale_f;
	return (vec);
}

t_vec3	*scale_vec3_vec3(t_vec3 *vec, t_vec3 *scale)
{
	vec->x *= scale->x;
	vec->y *= scale->y;
	vec->z *= scale->z;
	return (vec);
}

t_vec3	*scale_vec3_dbl(t_vec3 *vec, double scale_x,
		double scale_y, double scale_z)
{
	vec->x *= scale_x;
	vec->y *= scale_y;
	vec->z *= scale_z;
	return (vec);
}
