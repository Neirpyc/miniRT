/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 12:36:22 by caugier           #+#    #+#             */
/*   Updated: 2021/01/02 12:36:24 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../render_int.h"

void	rotate_ym(t_render *rd)
{
	t_vec3	rot;
	t_vec3	trans;

	rot.x = 0;
	rot.y = -1;
	rot.z = 0;
	trans.x = 0;
	trans.y = 0;
	trans.z = 0;
	move(rd, trans, rot);
}
