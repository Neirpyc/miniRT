/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 14:41:44 by caugier           #+#    #+#             */
/*   Updated: 2020/12/30 23:18:50 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "squares.h"

void	get_square_funcs(t_funcs *funcs)
{
	funcs->get_t = square_get_t;
	funcs->normal = get_square_normal;
	funcs->intersect = square_intersect;
	funcs->get_material = get_square_material;
	funcs->move = move_square;
	funcs->bounding_box = square_bounding_box;
}
