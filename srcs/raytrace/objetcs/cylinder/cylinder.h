/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 13:42:40 by caugier           #+#    #+#             */
/*   Updated: 2020/12/23 16:58:54 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H

# include "../objects.h"

t_material		*get_cylinder_material(t_any_obj *obj);
double			get_cylinder_t(t_ray *ray,
	t_intersection *intersection, t_any_obj *obj) __attribute__((hot, pure));
t_intersection	*cylinder_intersect(t_ray *ray,
	t_intersection *intersection, t_any_obj *obj);
t_intersection	*get_cylinder_normal(t_ray *ray,
	t_intersection *intersection, t_any_obj *obj);
void			move_cylinder(t_vec3 translation, t_vec3 rotation,
	t_any_obj *obj);
void			cylinder_bounding_box(t_bounding_box *bounding_box,
	t_any_obj *obj);

#endif
