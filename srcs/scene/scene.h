/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 20:42:32 by caugier           #+#    #+#             */
/*   Updated: 2020/12/31 19:32:47 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "../lists/lists.h"
# include "../common/common.h"

/*
** Arrays
*/
typedef struct s_array {
	void					*array;
	size_t					size;
}							t_array;

/*
** Disruption
*/
typedef enum e_disruption {
	disruption_none,
	disruption_sine,
	disruption_check,
	disruption_rainbow,
}							t_disruption;

/*
** Materials
*/
typedef struct s_material {
	t_frgba					color;
	double					spec_k;
	double					refraction_indice;
	t_disruption			disruption;
	signed long long		id;
}							t_material;

/*
** Resolution
*/
typedef struct s_resolution {
	int						width;
	int						height;
}							t_resolution;

/*
** Ambient
*/
typedef struct s_ambient {
	t_frgba					color;
	double					strength;
}							t_ambient;

/*
** Camera
*/
typedef struct s_fov {
	double					x_fov;
	double					y_fov;
}							t_fov;

typedef struct s_camera {
	t_position				origin;
	t_vec3					normal;
	t_vec3					d_x;
	t_vec3					d_y;
	int						bounces;
	int						sub_pixels;
}							t_camera;

typedef struct s_camera_array {
	t_camera				*array;
	size_t					size;
}							t_int_camera_array;

typedef union u_camera_array {
	t_array					array;
	t_int_camera_array		cameras;
}							t_camera_array;

/*
** Light
*/
typedef struct s_light {
	t_position				position;
	t_frgba					color;
	double					strength;
}							t_light;

typedef struct s_light_array {
	t_light					*array;
	size_t					size;
}							t_int_light_array;

typedef union u_light_array {
	t_array					array;
	t_int_light_array		lights;
}							t_light_array;

/*
** Sphere
*/
typedef struct s_sphere {
	t_position				position;
	t_material				*material;
	double					radius_sq;
	double					radius;
}							t_sphere;

typedef struct s_sphere_array {
	t_sphere				*array;
	size_t					size;
}							t_int_sphere_array;

typedef union u_sphere_array {
	t_array					*array;
	t_int_sphere_array		*spheres;
}							t_sphere_array;

/*
** Plane
*/
typedef struct s_plane {
	t_position				position;
	t_rotation				normal;
	t_material				*material;
}							t_plane;

typedef struct s_plane_array {
	t_plane					*array;
	size_t					size;
}							t_int_plane_array;

typedef union u_plane_array {
	t_array					*array;
	t_int_plane_array		*planes;
}							t_plane_array;

/*
** Square
*/
typedef struct s_square {
	t_position				corner;
	t_rotation				normal;
	t_vec3					edge_1;
	t_vec3					edge_2;
	t_material				*material;
	double					side_squared;
	double					side;
}							t_square;

typedef struct s_square_array {
	t_square				*array;
	size_t					size;
}							t_int_square_array;

typedef union u_square_array {
	t_array					*array;
	t_int_square_array		*squares;
}							t_square_array;

/*
** Cylinder
*/
typedef struct s_cylinder {
	t_position				position;
	t_vec3					axis;
	t_material				*material;
	double					rad_sq;
	double					radius;
	double					height;
	double					max_offset;
}							t_cylinder;

typedef struct s_cylinder_array {
	t_cylinder				*array;
	size_t					size;
}							t_int_cylinder_array;

typedef union u_cylinder_array {
	t_array					*array;
	t_int_cylinder_array	*cylinders;
}							t_cylinder_array;

/*
** Triangle
*/
typedef struct s_triangle {
	t_position				corner;
	t_vec3					edge1;
	t_vec3					edge2;
	t_vec3					normal;
	t_material				*material;
}							t_triangle;

typedef struct s_triangle_array {
	t_triangle				*array;
	size_t					size;
}							t_int_triangle_array;

typedef union u_triangle_array {
	t_array					*array;
	t_int_triangle_array	*triangles;
}							t_triangle_array;

/*
** Cone
*/
typedef struct s_cone {
	t_position				position;
	t_vec3					direction;
	double					height;
	double					angle;
	double					cos;
	double					cos_sq;
	double					max_dst;
	t_material				*material;
}							t_cone;

typedef struct s_cone_array {
	t_cone					*array;
	size_t					size;
}							t_int_cone_array;

typedef union u_cone_array {
	t_array					*array;
	t_int_cone_array		*cones;
}							t_cone_array;

/*
** Discs
*/
typedef struct s_disc {
	t_position				center;
	t_vec3					normal;
	double					radius;
	t_material				*material;
}							t_disc;

typedef struct s_disc_array {
	t_disc					*array;
	size_t					size;
}							t_int_disc_array;

typedef union u_disc_array {
	t_array					*array;
	t_int_disc_array		*discs;
}							t_disc_array;

/*
** Parallel Lights
*/
typedef struct s_parallel_light {
	t_position				position;
	t_rotation				normal;
	t_frgba					color;
	double					strength;
	t_material				*material;
}							t_parallel_light;

typedef struct s_parallel_light_array {
	t_parallel_light		*array;
	size_t					size;
}							t_int_p_light_array;

typedef union u_parallel_light_array {
	t_array					array;
	t_int_p_light_array		p_lights;
}							t_parallel_light_array;

/*
** Function Arrays
*/
typedef union u_any_obj {
	t_sphere				*sphere;
	t_plane					*plane;
	t_square				*square;
	t_cylinder				*cylinder;
	t_triangle				*triangle;
	t_disc					*disc;
	t_cone					*cone;
}							t_any_obj;

typedef struct s_ray		t_ray;

typedef struct s_funcs {
	t_material				*(*get_material)(t_any_obj *obj);
	double					(*get_t)(t_ray *ray,
		t_intersection *intersection, t_any_obj *obj);
	t_intersection			*(*intersect)(t_ray *ray,
		t_intersection *intersection, t_any_obj *obj);
	t_intersection			*(*normal)(t_ray *ray,
		t_intersection *intersection, t_any_obj *obj);
	void					(*move)(t_vec3 translation, t_vec3 rotation,
		t_any_obj *obj);
	void					(*bounding_box)(t_bounding_box *bounding_box,
		t_any_obj *obj);
}							t_funcs;

typedef struct s_object {
	t_any_obj				object;
	t_material				*material;
	t_funcs					functions;
	t_bounding_box			bounding_box;
}							t_object;

typedef struct s_object_array {
	t_object				*objects;
	size_t					size;
}							t_object_array;

typedef union u_object_array {
	t_array					array;
	t_object_array			objects;
}							t_objects;

/*
** Filter
*/
typedef enum e_filter {
	filter_none,
	filter_red,
	filter_green,
	filter_blue,
}							t_filter;

/*
** Scene
*/
typedef struct s_scene {
	t_resolution			resolution;
	t_ambient				ambient;
	t_list					*materials;
	t_camera_array			cameras;
	t_light_array			lights;
	t_parallel_light_array	p_lights;
	t_objects				objects;
	t_filter				filter;
	int						save;
}							t_scene;

void						free_scene(t_scene *scene);

#endif
