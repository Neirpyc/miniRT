/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rainbow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 12:12:41 by caugier           #+#    #+#             */
/*   Updated: 2020/12/29 16:29:20 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disruptions_int.h"
#include <math.h>

inline void	rainbow(t_vec3 *normal, t_frgba *color)
{
	color->red *= fabs(normal->x);
	color->green *= fabs(normal->y);
	color->blue *= fabs(normal->z);
}
