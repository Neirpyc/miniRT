/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 12:54:44 by caugier           #+#    #+#             */
/*   Updated: 2020/12/13 13:24:15 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include "../../scene/scene.h"
# include "../raytrace_int.h"

/*
** Spheres
*/
void	get_sphere_funcs(t_funcs *funcs);

/*
** Planes
*/
void	get_plane_funcs(t_funcs *funcs);

/*
** Squares
*/
void	get_square_funcs(t_funcs *funcs);

/*
** Triangles
*/
void	get_triangle_funcs(t_funcs *funcs);

/*
** Cylinders
*/
void	get_cylinder_funcs(t_funcs *funcs);

/*
** Discs
*/
void	get_disc_funcs(t_funcs *funcs);

/*
** Cones
*/
void	get_cone_funcs(t_funcs *funcs);

#endif
