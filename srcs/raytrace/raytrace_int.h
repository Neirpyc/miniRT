/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace_int.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 13:50:00 by caugier           #+#    #+#             */
/*   Updated: 2021/01/01 00:17:53 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACE_INT_H
# define RAYTRACE_INT_H

# include "raytrace.h"
# include <stdlib.h>

# ifndef COLOR_THRESHOLD
#  define COLOR_THRESHOLD 0.05
# endif

# define RI_AIR 1.000273

typedef struct s_vec2 {
	double	x;
	double	y;
}						t_vec2;

typedef struct s_ray {
	t_vec3		direction;
	t_vec3		invdir;
	t_position	origin;
	int			bounces;
	t_frgba		color;
}						t_ray;

void					raytrace_pixel(int x, int y,
	t_scene *scene, t_camera *cam);
int				bounding_box_intersect(t_bounding_box *bb, t_ray
*ray, double best_t) __attribute__((hot, pure, always_inline));
void					points_to_bb(t_bounding_box *bb, t_vec3 pts[4]);

t_vec3					*add_vec3(
	t_vec3 *dst, t_vec3 src) __attribute__((hot));
t_vec3					*scale_vec3(
	t_vec3 *vec, double scale_f) __attribute__((hot));
t_vec3					*normalize_vec3(t_vec3 *vec);
void					fill_ray(t_ray *ray, t_camera *cam,
	t_scene *scene, t_vec2 *pos);
void					simulate_ray(t_ray *ray, t_scene *scene,
	int max_bounces);
void					mix_colors(t_ray *ray, t_frgba color, double mult);
void					add_colors(t_frgba *c1, t_frgba c2, double mult);
void					init_frgba(t_frgba *c);
void					init_frgba_new_ray(t_frgba *c);
void					empty_frgba(t_frgba *c);
void					get_best_intersection(t_scene *scene, t_ray *ray,
	t_intersection *in, size_t *i);

t_frgba					*get_diffuse_color(
	t_frgba *color,
	t_intersection *intersection,
	t_scene *scene,
	t_disruption disruption);
t_frgba					*get_specular_color(t_frgba *color, t_ray *incident,
	t_intersection *intersection, t_scene *scene);

void					rotate_vec3(t_vec3 *vec, t_rotation rot);

t_vec3					*scale_vec3(t_vec3 *vec, double scale_f);
t_vec3					*scale_vec3_vec3(t_vec3 *vec, t_vec3 *scale);
t_vec3					*scale_vec3_dbl(t_vec3 *vec,
	double scale_x, double scale_y, double scale_z);

double					norm_vec3(t_vec3 vec) __attribute__((const, hot));
t_vec3					*normalize_vec3(t_vec3 *vec);
t_vec3					*normalize_vec3_d(t_vec3 *vec, double norm);

t_vec3					*add_vec3(t_vec3 *dst, t_vec3 src);
t_vec3					*vec3_sub(
	t_vec3 *dst, t_vec3 src) __attribute__((hot, always_inline));
void					vec3_sub_noret(
	t_vec3 *dst, t_vec3 src) __attribute__((hot, always_inline));
double					vec3_scalar(
	const t_vec3 v1, const t_vec3 v2) __attribute__((hot, pure));
void					vec3_cross(t_vec3 *v1, t_vec3 v2);

t_vec3					*vec_100(t_vec3 *vec);
t_vec3					*vec_010(t_vec3 *vec);
t_vec3					*vec_001(t_vec3 *vec);
t_vec3					*vec_nan(t_vec3 *vec);
t_vec3					*init_vec(t_vec3 *vec, double x, double y, double z);

int						vec3_is_nan(t_vec3 vec);

double					fresnel_spec_amount(double n1, double n2,
	double coeff, t_intersection *intersection);

double					solve_quadratic(double a,
	double b, double c, double *t1) __attribute__((hot, pure));
double					reflectance(t_intersection *intersection,
	t_ray *incident, double n2);

#endif
