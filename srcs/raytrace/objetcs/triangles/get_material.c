/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_material.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 21:34:12 by caugier           #+#    #+#             */
/*   Updated: 2020/12/20 21:34:12 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "triangles.h"

t_material	*get_triangle_material(t_any_obj *obj)
{
	return (obj->triangle->material);
}
