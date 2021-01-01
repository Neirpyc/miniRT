/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fresnel.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 12:23:57 by caugier           #+#    #+#             */
/*   Updated: 2020/12/31 17:48:09 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raytrace_int.h"
#include <math.h>

double	fresnel_spec_amount(double n1, double n2,
	double coeff, t_intersection *intersection)
{
	double	r0;
	double	cos_x;
	double	n;
	double	ret;

	r0 = (n1 - n2) / (n1 + n2);
	r0 *= r0;
	cos_x = -vec3_scalar(intersection->normal, intersection->intersection);
	if (n1 > n2)
	{
		n = n1 / n2;
		ret = n * n * (1. - cos_x * cos_x);
		if (ret > 1.0)
			return (1.0);
		cos_x = sqrt(1. - ret);
	}
	n = 1. - cos_x;
	ret = r0 + (1. - r0) * n * n * n * n * n;
	ret = (coeff + (1. - coeff) * ret);
	return (ret);
}
