/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 22:30:46 by caugier           #+#    #+#             */
/*   Updated: 2020/12/19 18:04:35 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include "../raytrace/raytrace.h"
# include "../render/render.h"

void		open_window(int *width, int *height);
void		close_window(void *param);
void		loop_window(t_render *rd);
void		put_px(t_rgba px, int x, int y, t_filter filter);
void		init_img_buffer(int width, int height);

void		free_img_buffer(void *arg);
void		flush_window_buffer(void);

#endif
