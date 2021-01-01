/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 11:30:22 by caugier           #+#    #+#             */
/*   Updated: 2020/12/29 11:33:44 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filters_int.h"

inline void	apply_filters(t_rgba *color, t_filter filter)
{
	if (filter == filter_none)
		return ;
	if (filter == filter_red)
	{
		f_filter_red(color);
		return ;
	}
	if (filter == filter_green)
	{
		f_filter_green(color);
		return ;
	}
	if (filter == filter_blue)
	{
		f_filter_blue(color);
		return ;
	}
}
