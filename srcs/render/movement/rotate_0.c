/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 17:58:58 by caugier           #+#    #+#             */
/*   Updated: 2021/01/02 12:36:03 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../render_int.h"

void	rotate_xp(t_render *rd)
{
	t_vec3	rot;
	t_vec3	trans;

	rot.x = 1;
	rot.y = 0;
	rot.z = 0;
	trans.x = 0;
	trans.y = 0;
	trans.z = 0;
	move(rd, trans, rot);
}

void	rotate_xm(t_render *rd)
{
	t_vec3	rot;
	t_vec3	trans;

	rot.x = -1;
	rot.y = 0;
	rot.z = 0;
	trans.x = 0;
	trans.y = 0;
	trans.z = 0;
	move(rd, trans, rot);
}

void	rotate_np(t_render *rd)
{
	t_vec3	rot;
	t_vec3	trans;

	rot.x = 0;
	rot.y = 0;
	rot.z = 1;
	trans.x = 0;
	trans.y = 0;
	trans.z = 0;
	move(rd, trans, rot);
}

void	rotate_nm(t_render *rd)
{
	t_vec3	rot;
	t_vec3	trans;

	rot.x = 0;
	rot.y = 0;
	rot.z = -1;
	trans.x = 0;
	trans.y = 0;
	trans.z = 0;
	move(rd, trans, rot);
}

void	rotate_yp(t_render *rd)
{
	t_vec3	rot;
	t_vec3	trans;

	rot.x = 0;
	rot.y = 1;
	rot.z = 0;
	trans.x = 0;
	trans.y = 0;
	trans.z = 0;
	move(rd, trans, rot);
}
