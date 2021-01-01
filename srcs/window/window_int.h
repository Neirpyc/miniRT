/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_int.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 22:31:02 by caugier           #+#    #+#             */
/*   Updated: 2020/12/31 19:47:29 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_INT_H
# define WINDOW_INT_H

# define WINDOW_TITLE "MiniRT - MiniRT Is Not an Interesting Ray Tracer"

# include "window.h"
# include <mlx.h>

typedef struct s_mlx_image_wrapper {
	void				*image;
	void				*address;
	int					bytes_per_line;
	int					bits_per_pixel;
	int					endian;
	int					width;
}						t_mlx_image_wrapper;

typedef void				(*t_interaction_func)(t_render *render);

extern void					*g_mlx;
extern void					*g_window;
extern t_mlx_image_wrapper	g_image_buffer;

#endif
