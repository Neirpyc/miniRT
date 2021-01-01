/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 19:04:57 by caugier           #+#    #+#             */
/*   Updated: 2020/12/31 19:47:51 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

typedef struct s_vec3 {
	double				x;
	double				y;
	double				z;
}						t_vec3;

typedef struct s_intersection {
	t_vec3				intersection;
	t_vec3				normal;
}						t_intersection;

typedef struct s_frgba {
	double				red;
	double				green;
	double				blue;
	double				alpha;
}						t_frgba;

typedef struct s_rgba
{
	unsigned char		blue;
	unsigned char		green;
	unsigned char		red;
	unsigned char		alpha;
}						t_int_rgba;

typedef union u_rgba
{
	int					nbr;
	t_int_rgba			rgba;
}						t_rgba;

typedef struct s_min_max {
	double				min;
	double				max;
}						t_min_max;

typedef struct s_bounding_box {
	t_min_max			x;
	t_min_max			y;
	t_min_max			z;
}						t_bounding_box;

typedef struct s_vec3	t_position;
typedef struct s_vec3	t_rotation;

#endif
