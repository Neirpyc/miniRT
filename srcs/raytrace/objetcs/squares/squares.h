/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   squares.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 18:38:09 by caugier           #+#    #+#             */
/*   Updated: 2020/12/20 18:46:33 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUARES_H
# define SQUARES_H

# include "../objects.h"

t_material		*get_square_material(t_any_obj *obj);
double			square_get_t(t_ray *ray,
	t_intersection *intersection, t_any_obj *obj) __attribute__((hot, pure));
t_intersection	*square_intersect(t_ray *ray,
	t_intersection *intersection, t_any_obj *obj);
t_intersection	*get_square_normal(t_ray *ray,
	t_intersection *intersection, t_any_obj *obj);
void			move_square(t_vec3 translation, t_vec3 rotation,
	t_any_obj *obj);
void			square_bounding_box(t_bounding_box *bounding_box,
	t_any_obj *obj);

#endif
