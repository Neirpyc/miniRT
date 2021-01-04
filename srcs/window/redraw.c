/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redraw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 13:36:21 by caugier           #+#    #+#             */
/*   Updated: 2021/01/04 11:20:34 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window_int.h"
#include "../libft/libft.h"

static inline void	get_black(t_rgba *color)
{
	color->rgba.red = 0;
	color->rgba.green = 0;
	color->rgba.blue = 0;
	color->rgba.alpha = 255;
}

void	black_buffer(int height)
{
	t_rgba	color;
	int		x;
	int		y;
	size_t	size;
	char	*pos;

	get_black(&color);
	if (g_mlx != NULL)
		color.nbr = mlx_get_color_value(g_mlx, color.nbr);
	size = g_image_buffer.bits_per_pixel / 8;
	pos = g_image_buffer.address;
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < g_image_buffer.width)
		{
			ft_memcpy(pos, &color.nbr, size);
			pos += size;
			x++;
		}
		y++;
		pos += g_image_buffer.bytes_per_line;
	}
}

int	redraw(void *param)
{
	(void)param;
	flush_window_buffer();
	return (0);
}
