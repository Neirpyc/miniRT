/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 14:21:28 by caugier           #+#    #+#             */
/*   Updated: 2020/12/31 17:40:40 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "../scene/scene.h"

typedef struct s_render {
	t_scene	*scene;
	ssize_t	cam_id;
	ssize_t	obj_id;
	int		mode;
}				t_render;

/*
** Render
*/
void			start_rendering_threads(int count, t_scene *scene);
void			stop_threads(void *param);
void			render(t_camera *cam);
t_render		*new_render(t_scene *scene);
void			force_render(t_render *rd);

/*
** Cameras
*/
void			next_camera(t_render *rd);
void			prev_camera(t_render *rd);
void			mode_camera(t_render *rd);

/*
** Objects
*/
void			next_object(t_render *rd);
void			prev_object(t_render *rd);
void			mode_object(t_render *rd);

/*
** Movement
*/
void			move_forward(t_render *rd);
void			move_backward(t_render *rd);
void			move_left(t_render *rd);
void			move_right(t_render *rd);
void			move_up(t_render *rd);
void			move_down(t_render *rd);
void			rotate_xp(t_render *rd);
void			rotate_xm(t_render *rd);
void			rotate_np(t_render *rd);
void			rotate_nm(t_render *rd);
void			rotate_ym(t_render *rd);
void			rotate_yp(t_render *rd);

#endif
