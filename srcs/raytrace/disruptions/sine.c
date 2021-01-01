/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sine.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 12:10:55 by caugier           #+#    #+#             */
/*   Updated: 2020/12/31 17:49:07 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disruptions_int.h"
#include <math.h>

inline void	sine(t_vec3 *normal, t_vec3 *position)
{
	double	k;
	double	delta;

	k = sin(position->y / M_2_PI) / 5;
	delta = normal->z * k;
	normal->z -= delta;
	normal->y += delta;
	normalize_vec3(normal);
}
