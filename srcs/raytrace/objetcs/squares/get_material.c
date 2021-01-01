/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_material.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 14:43:01 by caugier           #+#    #+#             */
/*   Updated: 2020/12/20 18:41:05 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "squares.h"

t_material	*get_square_material(t_any_obj *obj)
{
	return (obj->square->material);
}
