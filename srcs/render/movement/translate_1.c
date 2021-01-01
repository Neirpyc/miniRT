/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 17:42:59 by caugier           #+#    #+#             */
/*   Updated: 2020/12/31 17:35:12 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../render_int.h"

void	move_down(t_render *rd)
{
	t_vec3	rot;
	t_vec3	trans;

	rot.x = 0;
	rot.y = 0;
	rot.z = 0;
	trans.x = 0;
	trans.y = 0;
	trans.z = -1;
	move(rd, trans, rot);
}
