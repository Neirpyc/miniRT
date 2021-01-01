/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 16:45:53 by caugier           #+#    #+#             */
/*   Updated: 2020/12/31 17:46:06 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raytrace_int.h"
#include <math.h>

inline static void	rotate_x(t_vec3 *vec, double rot)
{
	double	c;
	double	s;
	double	y;

	c = cos(rot);
	s = sin(rot);
	y = vec->y * c - vec->z * s;
	vec->z = vec->y * s + vec->z * c;
	vec->y = y;
}

inline static void	rotate_y(t_vec3 *vec, double rot)
{
	double	c;
	double	s;
	double	x;

	c = cos(rot);
	s = sin(rot);
	x = vec->x * c + vec->z * s;
	vec->z = -vec->x * s + vec->z * c;
	vec->x = x;
}

inline static void	rotate_z(t_vec3 *vec, double rot)
{
	double	c;
	double	s;
	double	x;

	c = cos(rot);
	s = sin(rot);
	x = vec->x * c - vec->y * s;
	vec->y = vec->x * s + vec->y * c;
	vec->x = x;
}

inline static double	un_normalize(double n)
{
	return (-n * M_PI);
}

void	rotate_vec3(t_vec3 *vec, t_rotation rot)
{
	rotate_z(vec, un_normalize(rot.z));
	rotate_y(vec, un_normalize(rot.y));
	rotate_x(vec, un_normalize(rot.x));
}
