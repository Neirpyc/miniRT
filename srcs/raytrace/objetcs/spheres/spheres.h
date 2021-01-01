/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spheres.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 13:30:33 by caugier           #+#    #+#             */
/*   Updated: 2020/12/20 15:16:25 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERES_H
# define SPHERES_H

# include "../objects.h"

t_material		*get_sphere_material(t_any_obj *obj);
double			get_sphere_t(t_ray *ray,
	t_intersection *intersection, t_any_obj *obj) __attribute__((hot, pure));
t_intersection	*sphere_intersect(t_ray *ray,
	t_intersection *intersection, t_any_obj *obj);
t_intersection	*get_sphere_normal(t_ray *ray,
	t_intersection *intersection, t_any_obj *obj);
void			move_sphere(t_vec3 translation, t_vec3 rotation,
	t_any_obj *obj);
void			sphere_bounding_box(t_bounding_box *bounding_box,
	t_any_obj *obj);

#endif
