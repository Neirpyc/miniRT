/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disc.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 22:30:56 by caugier           #+#    #+#             */
/*   Updated: 2020/12/26 22:30:56 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISC_H
# define DISC_H

# include "../objects.h"

t_material		*get_disc_material(t_any_obj *obj);
double			disc_get_t(t_ray *ray,
	t_intersection *intersection, t_any_obj *obj) __attribute__((hot, pure));
t_intersection	*disc_intersect(t_ray *ray,
	t_intersection *intersection, t_any_obj *obj);
t_intersection	*get_disc_normal(t_ray *ray,
	t_intersection *intersection, t_any_obj *obj);
void			move_disc(t_vec3 translation, t_vec3 rotation,
	t_any_obj *obj);
void			disc_bounding_box(t_bounding_box *bounding_box,
	t_any_obj *obj);

#endif
