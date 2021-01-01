/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_material.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 13:34:13 by caugier           #+#    #+#             */
/*   Updated: 2020/12/13 13:34:13 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "spheres.h"

t_material	*get_sphere_material(t_any_obj *obj)
{
	return (obj->sphere->material);
}
