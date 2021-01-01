/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_vecs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 18:33:29 by caugier           #+#    #+#             */
/*   Updated: 2020/12/17 19:38:19 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raytrace_int.h"
#include <math.h>

t_vec3	*vec_100(t_vec3 *vec)
{
	vec->x = 1;
	vec->y = 0;
	vec->z = 0;
	return (vec);
}

t_vec3	*vec_010(t_vec3 *vec)
{
	vec->x = 0;
	vec->y = 1;
	vec->z = 0;
	return (vec);
}

t_vec3	*vec_001(t_vec3 *vec)
{
	vec->x = 0;
	vec->y = 0;
	vec->z = 1;
	return (vec);
}

t_vec3	*init_vec(t_vec3 *vec, double x, double y, double z)
{
	vec->x = x;
	vec->y = y;
	vec->z = z;
	return (vec);
}

inline t_vec3	*vec_nan(t_vec3 *vec)
{
	vec->x = NAN;
	return (vec);
}
