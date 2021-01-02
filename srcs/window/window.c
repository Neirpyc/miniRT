/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 22:33:01 by caugier           #+#    #+#             */
/*   Updated: 2021/01/02 16:01:06 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/X.h>
#include <X11/keysym.h>
#include "window_int.h"
#include "../gc_malloc/gc_malloc.h"
#include "../errors/errors.h"

void						*g_mlx = NULL;
void						*g_window = NULL;

void	open_window(int *width, int *height)
{
	int	size_x;
	int	size_y;

	g_mlx = mlx_init();
	if (g_mlx == NULL)
		gc_exit_strerror(ERRCODE_CNT_IMLX, -1);
	mlx_get_screen_size(g_mlx, &size_x, &size_y);
	if (*width > size_x)
		*width = size_x;
	if (*height > size_y)
		*height = size_y;
	g_window = mlx_new_window(g_mlx, (int) * width,
			(int) * height, WINDOW_TITLE);
	if (g_window == NULL)
	{
		close_window(NULL);
		gc_exit_strerror(ERRCODE_CNT_OWIN, -1);
	}
	init_img_buffer(*width, *height);
}

void	close_window(void *param)
{
	(void)param;
	if (g_mlx == NULL)
		return ;
	if (g_window != NULL)
	{
		mlx_destroy_window(g_mlx, g_window);
		g_window = NULL;
	}
	mlx_destroy_display(g_mlx);
	free(g_mlx);
	g_mlx = NULL;
}

const t_interaction_func	g_functions[] = {next_camera, prev_camera,
							 move_forward, move_backward,
							 move_left, move_right, move_up,
							 move_down, force_render,
							 rotate_xm, rotate_xp,
							 rotate_nm, rotate_np,
							 mode_object, mode_camera,
							 next_object, prev_object, rotate_ym, rotate_yp};
const int					g_keys[] = {XK_Page_Up, XK_Page_Down, XK_z,
						 				XK_s, XK_q, XK_d, XK_Shift_L,
						 				XK_Control_L, XK_space, XK_t, XK_g,
						 				XK_f, XK_h, XK_o, XK_c, XK_p, XK_m,
						 				XK_u, XK_j};

static int	button_press(int keycode, void *param)
{
	size_t	i;

	if (keycode == XK_Escape && g_mlx != NULL)
		gc_exit(0);
	i = sizeof(g_functions);
	while (i > 0)
	{
		i--;
		if (keycode == g_keys[i])
		{
			g_functions[i](param);
			break ;
		}
	}
	return (0);
}

static int	x_exit(void *param)
{
	return (button_press(XK_Escape, param));
}

void	loop_window(t_render *rd)
{
	mlx_hook(g_window, ClientMessage, NoEventMask, x_exit, 0);
	mlx_key_hook(g_window, button_press, (void *)rd);
	mlx_loop(g_mlx);
}
