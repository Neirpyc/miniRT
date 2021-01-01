/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disruptions_int.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 15:34:17 by caugier           #+#    #+#             */
/*   Updated: 2020/12/29 15:34:39 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISRUPTIONS_INT_H
# define DISRUPTIONS_INT_H

# include "disruptions.h"

void	sine(t_vec3 *normal, t_vec3 *position);
void	checkerboard(t_vec3 *position, t_frgba *color);
void	rainbow(t_vec3 *normal, t_frgba *color);

#endif
