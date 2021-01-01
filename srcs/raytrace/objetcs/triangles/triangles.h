/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangles.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 21:28:34 by caugier           #+#    #+#             */
/*   Updated: 2020/12/20 21:37:10 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIANGLES_H
# define TRIANGLES_H

# include "../objects.h"

t_intersection	*get_triangle_normal(t_ray *ray,
	t_intersection *intersection, t_any_obj *obj);
t_material		*get_triangle_material(t_any_obj *obj);
double			triangle_get_t(t_ray *ray,
	t_intersection *intersection, t_any_obj *obj) __attribute__((hot, pure));
t_intersection	*triangle_intersect(t_ray *ray,
	t_intersection *intersection, t_any_obj *obj);
void			move_triangle(t_vec3 translation, t_vec3 rotation,
	t_any_obj *obj);
void			triangle_bounding_box(t_bounding_box *bounding_box,
	t_any_obj *obj);

#endif
