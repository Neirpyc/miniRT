/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_list.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 21:07:11 by caugier           #+#    #+#             */
/*   Updated: 2020/12/31 19:34:01 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_LIST_H
# define SCENE_LIST_H

# include "scene.h"

/*
** Materials
*/
typedef struct s_material_list {
	t_material				*content;
	struct s_material_list	*next;
}							t_int_material_list;

typedef union u_material_list {
	t_list					*list;
	t_int_material_list		*materials;
}							t_material_list;

/*
** Camera
*/
typedef struct s_camera_list {
	t_camera				*content;
	struct s_camera_list	*next;
}							t_int_camera_list;

typedef union u_camera_list {
	t_list					*list;
	t_int_camera_list		*cameras;
}							t_camera_list;

/*
** Light
*/
typedef struct s_light_list {
	t_light					*content;
	struct s_light_list		*next;
}							t_int_light_list;

typedef union u_light_list {
	t_list					*list;
	t_int_light_list		*lights;
}							t_light_list;

/*
** Sphere
*/
typedef struct s_sphere_list {
	t_sphere				*content;
	struct s_sphere_list	*next;
}							t_int_sphere_list;

typedef union u_sphere_list {
	t_list					*list;
	t_int_sphere_list		*spheres;
}							t_sphere_list;

/*
** Plane
*/
typedef struct s_plane_list {
	t_plane				*content;
	struct s_plane_list	*next;
}							t_int_plane_list;

typedef union u_plane_list {
	t_list					*list;
	t_int_plane_list		*planes;
}							t_plane_list;

/*
** Square
*/
typedef struct s_square_list {
	t_square				*content;
	struct s_square_list	*next;
}							t_int_square_list;

typedef union u_square_list {
	t_list					*list;
	t_int_square_list		*squares;
}							t_square_list;

/*
** Cylinder
*/
typedef struct s_cylinder_list {
	t_cylinder				*content;
	struct s_cylinder_list	*next;
}							t_int_cylinder_list;

typedef union u_cylinder_list {
	t_list					*list;
	t_int_cylinder_list		*cylinders;
}							t_cylinder_list;

/*
** Triangle
*/
typedef struct s_triangle_list {
	t_triangle				*content;
	struct s_triangle_list	*next;
}							t_int_triangle_list;

typedef union u_triangle_list {
	t_list					*list;
	t_int_triangle_list		*triangles;
}							t_triangle_list;

/*
** Cone
*/
typedef struct s_cone_list {
	t_cone				*content;
	struct s_cone_list	*next;
}							t_int_cone_list;

typedef union u_cone_list {
	t_list					*list;
	t_int_cone_list			*cones;
}							t_cone_list;

/*
** Cube
*/

typedef struct s_cube {
	t_position				center;
	t_rotation				normal;
	double					side;
	t_material				*material;
}							t_cube;

typedef struct s_cube_list {
	t_cube				*content;
	struct s_cube_list	*next;
}							t_int_cube_list;

typedef union u_cube_list {
	t_list					*list;
	t_int_cube_list			*cubes;
}							t_cube_list;

/*
** Pyramids
*/
typedef struct s_pyramid {
	t_position				tip;
	t_rotation				normal;
	double					angle;
	double					height;
	t_material				*material;
}							t_pyramid;

typedef struct s_pyramid_list {
	t_pyramid				*content;
	struct s_pyramid_list	*next;
}							t_int_pyramid_list;

typedef union u_pyramid_list {
	t_list					*list;
	t_int_pyramid_list		*pyramids;
}							t_pyramid_list;

/*
** Discs
*/
typedef struct s_disc_list {
	t_disc					*content;
	struct s_disc_list		*next;
}							t_int_disc_list;

typedef union u_disc_list {
	t_list					*list;
	t_int_disc_list			*discs;
}							t_disc_list;

/*
** Parallel Lights
*/
typedef struct s_parallel_light_list {
	t_parallel_light					*content;
	struct s_parallel_light_list		*next;
}							t_int_parallel_light_list;

typedef union u_parallel_light_list {
	t_list						*list;
	t_int_parallel_light_list	*parallel_lights;
}							t_parallel_light_list;

/*
** Scene
*/
typedef struct s_list_scene {
	t_resolution			resolution;
	t_ambient				ambient;
	t_material_list			materials;
	t_camera_list			cameras;
	t_light_list			lights;
	t_parallel_light_list	p_lights;
	t_sphere_list			spheres;
	t_plane_list			planes;
	t_square_list			squares;
	t_cylinder_list			cylinders;
	t_triangle_list			triangles;
	t_cone_list				cones;
	t_cube_list				cubes;
	t_disc_list				discs;
	t_pyramid_list			pyramids;
	t_filter				filter;
}							t_list_scene;

#endif
