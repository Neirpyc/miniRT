/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_eq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 23:03:35 by caugier           #+#    #+#             */
/*   Updated: 2020/12/12 23:03:35 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raytrace_int.h"
#include <math.h>

inline int	vec3_is_nan(t_vec3 vec)
{
	return (isnan(vec.x) || isnan(vec.y) || isnan(vec.z));
}
