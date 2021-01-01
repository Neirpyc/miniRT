/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 17:32:30 by caugier           #+#    #+#             */
/*   Updated: 2020/12/30 17:56:35 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../render_int.h"

void	move_forward(t_render *rd)
{
	t_vec3	rot;
	t_vec3	trans;

	rot.x = 0;
	rot.y = 0;
	rot.z = 0;
	trans.x = 1;
	trans.y = 0;
	trans.z = 0;
	move(rd, trans, rot);
}

void	move_backward(t_render *rd)
{
	t_vec3	rot;
	t_vec3	trans;

	rot.x = 0;
	rot.y = 0;
	rot.z = 0;
	trans.x = -1;
	trans.y = 0;
	trans.z = 0;
	move(rd, trans, rot);
}

void	move_left(t_render *rd)
{
	t_vec3	rot;
	t_vec3	trans;

	rot.x = 1;
	rot.y = 0;
	rot.z = 0;
	trans.x = 0;
	trans.y = 1;
	trans.z = 0;
	move(rd, trans, rot);
}

void	move_right(t_render *rd)
{
	t_vec3	rot;
	t_vec3	trans;

	rot.x = 0;
	rot.y = 0;
	rot.z = 0;
	trans.x = 0;
	trans.y = -1;
	trans.z = 0;
	move(rd, trans, rot);
}

void	move_up(t_render *rd)
{
	t_vec3	rot;
	t_vec3	trans;

	rot.x = 0;
	rot.y = 0;
	rot.z = 0;
	trans.x = 0;
	trans.y = 0;
	trans.z = 1;
	move(rd, trans, rot);
}
