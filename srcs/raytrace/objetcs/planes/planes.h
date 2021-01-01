/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   planes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 14:40:40 by caugier           #+#    #+#             */
/*   Updated: 2020/12/20 14:46:56 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANES_H
# define PLANES_H

# include "../objects.h"

t_material		*get_plane_material(t_any_obj *obj);
double			plane_get_t(t_ray *ray,
	t_intersection *intersection, t_any_obj *obj) __attribute__((hot, pure));
t_intersection	*plane_intersect(t_ray *ray,
	t_intersection *intersection, t_any_obj *obj);
t_intersection	*get_plane_normal(t_ray *ray,
	t_intersection *intersection, t_any_obj *obj);
void			move_plane(t_vec3 translation, t_vec3 rotation, t_any_obj *obj);
void			plane_bounding_box(t_bounding_box *bounding_box,
	t_any_obj *obj);

#endif
