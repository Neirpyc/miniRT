/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadratic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 16:09:34 by caugier           #+#    #+#             */
/*   Updated: 2020/12/31 17:47:24 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raytrace_int.h"
#include <math.h>

static inline double	swap_if_required(double *t1, double t0, double delta)
{
	if (*t1 > t0)
	{
		delta = *t1;
		*t1 = t0;
		t0 = delta;
	}
	return (t0);
}

inline double	solve_quadratic(double a, double b, double c, double *t1)
{
	double	t0;
	double	delta;
	double	sqrt_delta;

	a *= 2;
	b *= -1;
	delta = b * b - 2 * a * c;
	sqrt_delta = sqrt(delta);
	if (delta < 0)
	{
		*t1 = NAN;
		return (NAN);
	}
	t0 = (b + sqrt_delta) / a;
	if (delta == 0)
	{
		*t1 = NAN;
		return (t0);
	}
	*t1 = (b - sqrt_delta) / a;
	return (swap_if_required(t1, t0, delta));
}
