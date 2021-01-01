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
#include <math.h>

double	norm_vec3(t_vec3 vec)
{
	return (sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z));
}

t_vec3	*normalize_vec3(t_vec3 *vec)
{
	return (scale_vec3(vec, 1. / norm_vec3(*vec)));
}

t_vec3	*normalize_vec3_d(t_vec3 *vec, double norm)
{
	return (scale_vec3(vec, norm / norm_vec3(*vec)));
}
