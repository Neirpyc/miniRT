/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_mode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 17:25:38 by caugier           #+#    #+#             */
/*   Updated: 2020/12/30 17:25:38 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_int.h"

void	mode_object(t_render *rd)
{
	rd->mode = MODE_OBJ;
}

void	mode_camera(t_render *rd)
{
	rd->mode = MODE_CAM;
}
