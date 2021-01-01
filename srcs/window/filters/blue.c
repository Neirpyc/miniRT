/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blue.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 11:31:38 by caugier           #+#    #+#             */
/*   Updated: 2020/12/29 11:33:44 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filters_int.h"

inline void	f_filter_blue(t_rgba *color)
{
	color->rgba.red = 0;
	color->rgba.green = 0;
}
