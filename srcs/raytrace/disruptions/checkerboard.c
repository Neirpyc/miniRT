/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerboard.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 12:12:43 by caugier           #+#    #+#             */
/*   Updated: 2021/01/02 20:15:10 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disruptions_int.h"
#include <math.h>

inline void	checkerboard(t_vec3 *position, t_frgba *color)
{
	unsigned int	state;

	state = 0;
	state ^= (unsigned int)fmod(fabs(position->x - 1e-5), 2 + 1e-10);
	state ^= (unsigned int)fmod(fabs(position->y - 1e-5), 2 + 1e-10);
	state ^= (unsigned int)fmod(fabs(position->z - 1e-5), 2 + 1e-10);
	state ^= (unsigned int)(position->x - 1e5 > 0);
	state ^= (unsigned int)(position->y - 1e5 > 0);
	state ^= (unsigned int)(position->z - 1e5 > 0);
	if (state > 0)
	{
		color->red = 0;
		color->green = 0;
		color->blue = 0;
	}
}
