/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace_pixel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 15:17:35 by caugier           #+#    #+#             */
/*   Updated: 2020/12/31 18:03:20 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytrace_int.h"
#include "../window/window.h"
#include <math.h>

void	raytrace_pt(t_frgba *rgba, t_scene *scene, t_camera *cam, t_vec2 *pos)
{
	t_ray	ray;

	fill_ray(&ray, cam, scene, pos);
	simulate_ray(&ray, scene, cam->bounces);
	rgba->red += ray.color.red;
	rgba->green += ray.color.green;
	rgba->blue += ray.color.blue;
	rgba->alpha += ray.color.alpha;
}

static void	raytrace_int(t_vec2 xy, t_scene *scene,
	t_camera *cam, t_frgba *color)
{
	long long int	sub_x;
	long long int	sub_y;
	long long int	i;
	t_vec2			pos;

	sub_y = 0;
	i = 0;
	while (sub_y < cam->sub_pixels)
	{
		sub_x = 0;
		while (sub_x < cam->sub_pixels)
		{
			pos.x = (xy.x + (double)sub_x / (double)
					cam->sub_pixels) / (double)scene->resolution.width;
			pos.y = (xy.y + (double)sub_y / (double)cam->sub_pixels)
				/ (double)scene->resolution.height;
			raytrace_pt(color, scene, cam, &pos);
			sub_x++;
			i++;
		}
		sub_y++;
	}
}

static inline double	sqrt_rect(double d)
{
	double	rt;

	rt = sqrt(d);
	if (rt > 1)
		return (1);
	return (rt);
}

void	raytrace_pixel(int x, int y, t_scene *scene, t_camera *cam)
{
	t_vec2	vec;
	t_frgba	color;
	t_rgba	out_c;

	vec.x = (double)x;
	vec.y = (double)y;
	empty_frgba(&color);
	raytrace_int(vec, scene, cam, &color);
	color.red = color.red / (cam->sub_pixels * cam->sub_pixels);
	color.green = color.green / (cam->sub_pixels * cam->sub_pixels);
	color.blue = color.blue / (cam->sub_pixels * cam->sub_pixels);
	color.alpha = color.alpha / (cam->sub_pixels * cam->sub_pixels);
	out_c.rgba.red = (unsigned char)(255 * sqrt_rect(color.red));
	out_c.rgba.green = (unsigned char)(255 * sqrt_rect(color.green));
	out_c.rgba.blue = (unsigned char)(255 * sqrt_rect(color.blue));
	out_c.rgba.alpha = (unsigned char)(255 * sqrt_rect(color.alpha));
	put_px(out_c, x, y, scene->filter);
}
