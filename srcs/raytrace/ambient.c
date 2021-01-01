/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 23:18:50 by caugier           #+#    #+#             */
/*   Updated: 2020/12/18 19:33:51 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytrace_int.h"

void	init_frgba_new_ray(t_frgba *c)
{
	c->red = 1;
	c->blue = 1;
	c->green = 1;
	c->alpha = 1;
}

void	init_frgba(t_frgba *c)
{
	c->red = 0;
	c->blue = 0;
	c->green = 0;
	c->alpha = 1;
}

void	empty_frgba(t_frgba *c)
{
	c->red = 0;
	c->blue = 0;
	c->green = 0;
	c->alpha = 0;
}

void	add_colors(t_frgba *c1, t_frgba c2, double mult)
{
	c1->red += c2.red * mult;
	c1->green += c2.green * mult;
	c1->blue += c2.blue * mult;
}

void	mix_colors(t_ray *ray, t_frgba color, double mult)
{
	ray->color.red *= color.red * mult;
	ray->color.green *= color.green * mult;
	ray->color.blue *= color.blue * mult;
}
