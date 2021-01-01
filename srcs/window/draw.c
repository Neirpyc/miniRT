/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 18:36:32 by caugier           #+#    #+#             */
/*   Updated: 2020/12/31 19:43:32 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raytrace/raytrace_int.h"
#include "window_int.h"
#include <stdlib.h>
#include "../errors/errors.h"
#include "../gc_malloc/gc_malloc.h"
#include "../libft/libft.h"
#include "filters/filters.h"

t_mlx_image_wrapper	g_image_buffer = {.address = NULL};

void	free_img_buffer(void *arg)
{
	(void)arg;
	if (g_image_buffer.image != NULL)
	{
		mlx_destroy_image(g_mlx, g_image_buffer.image);
		g_image_buffer.image = NULL;
		g_image_buffer.address = NULL;
	}
	else if (g_image_buffer.address != NULL)
	{
		gc_free(g_image_buffer.address);
		g_image_buffer.address = NULL;
	}
}

void	flush_window_buffer(void)
{
	if (g_mlx != NULL)
		mlx_put_image_to_window(g_mlx, g_window, g_image_buffer.image,
			0, 0);
}

void	init_img_buffer(int width, int height)
{
	if (g_image_buffer.address == NULL)
	{
		if (g_mlx != NULL)
		{
			g_image_buffer.image = mlx_new_image(g_mlx, width, height);
			if (g_image_buffer.image == NULL)
				gc_exit_strerror(ERRCODE_CNT_ALLOC_FBUF, -1);
			g_image_buffer.address = mlx_get_data_addr(g_image_buffer.image,
					&g_image_buffer.bits_per_pixel, &g_image_buffer.endian,
					&g_image_buffer.bytes_per_line);
			if (g_image_buffer.address == NULL)
				gc_exit_strerror(ERRCODE_CNT_ALLOC_FBUF, -1);
		}
		else
		{
			g_image_buffer.address = gc_malloc(32 * width * height);
			g_image_buffer.bits_per_pixel = 32;
			g_image_buffer.bytes_per_line = 0;
			g_image_buffer.endian = 0;
		}
		g_image_buffer.width = width;
	}
}

inline void	put_px(t_rgba px, int x, int y, t_filter filter)
{
	if (g_mlx != NULL)
		px.nbr = mlx_get_color_value(g_mlx, px.nbr);
	apply_filters(&px, filter);
	ft_memcpy((char *)g_image_buffer.address
	+ (((g_image_buffer.bits_per_pixel * g_image_buffer.width / 8)
	+ g_image_buffer.bytes_per_line) * y)
	+ (x * g_image_buffer.bits_per_pixel / 8), &px.nbr,
	g_image_buffer.bits_per_pixel / 8);
}
