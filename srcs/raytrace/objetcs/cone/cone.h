/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 12:35:51 by caugier           #+#    #+#             */
/*   Updated: 2020/12/31 21:20:30 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONE_H
# define CONE_H

# include "../objects.h"

t_material		*get_cone_material(t_any_obj *obj);
double			get_cone_t(t_ray *ray,
	t_intersection *intersection, t_any_obj *obj) __attribute__((hot, pure));
t_intersection	*cone_intersect(t_ray *ray,
	t_intersection *intersection, t_any_obj *obj);
t_intersection	*get_cone_normal(t_ray *ray,
	t_intersection *intersection, t_any_obj *obj);
void			move_cone(t_vec3 translation, t_vec3 rotation,
	t_any_obj *obj);
void			cone_bounding_box(t_bounding_box *bounding_box,
	t_any_obj *obj);

#endif
