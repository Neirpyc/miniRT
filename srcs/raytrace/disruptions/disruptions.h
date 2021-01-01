/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disruptions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 12:07:40 by caugier           #+#    #+#             */
/*   Updated: 2020/12/29 15:36:06 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISRUPTIONS_H
# define DISRUPTIONS_H

# include "../raytrace_int.h"

void	apply_normal_disruption(t_vec3 *normal, t_vec3 *pos,
	t_disruption disruption);
void	apply_color_disruptions(t_frgba *color, t_vec3 *normal,
	t_vec3 *pos, t_disruption disruption);

#endif
