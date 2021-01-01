/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disruptions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 15:36:07 by caugier           #+#    #+#             */
/*   Updated: 2020/12/29 15:37:43 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disruptions_int.h"

inline void	apply_normal_disruption(t_vec3 *normal, t_vec3 *pos,
	t_disruption disruption)
{
	if (disruption == disruption_sine)
		sine(normal, pos);
}

inline void	apply_color_disruptions(t_frgba *color, t_vec3 *normal,
	t_vec3 *pos, t_disruption disruption)
{
	if (disruption == disruption_check)
		checkerboard(pos, color);
	else if (disruption == disruption_rainbow)
		rainbow(normal, color);
}
