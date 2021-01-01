/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_int.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 18:14:54 by caugier           #+#    #+#             */
/*   Updated: 2020/12/31 19:20:29 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_INT_H
# define PARSE_INT_H

# define SIGN_PLUS 1
# define SIGN_MINUS -1

# include "parse.h"
# include "../errors/errors.h"

typedef void	(*t_parse_func)(t_list *, size_t, size_t *, t_scene_parse *);

void			err_arg(int argc, char **argv, int arg_begin, int arg_end);
void			parse_line(char *line, t_scene_parse *scene,
	size_t current_line, t_list *lines);
void			validate_scene(t_list *lines, t_scene_parse *scene);
unsigned int	is_bonus(t_list *lines, size_t *pos);
void			chk_duplicate_mat_id(t_list *lines, t_scene_parse *scene);
void			link_mat(t_list *lines, t_scene_parse *scene);
t_material		*seek_material(t_scene_parse *scene, signed long long id);
t_material		*new_material(void);

/*
** Coumpounds
*/
void			expand_compounds(t_list_scene *scene);
void			expand_cubes(t_list_scene *scene, t_cube_list cubes);
void			process_square(t_square *square);
void			expand_pyramids(t_list_scene *scene, t_pyramid_list pyramids);
void			expand_cylinders(t_list_scene *scene,
	t_cylinder_list cylinders);
void			expand_cones(t_list_scene *scene, t_cone_list cones);

/*
** Conf error handling
*/
typedef struct s_location{
	size_t	line;
	size_t	arg_begin;
	size_t	arg_end;
	size_t	char_beg;
}				t_location;

void			err_line(char *line, t_location *loc, int errcode);
void			err_dup_line(t_list *lines, size_t prev_line,
							 size_t curr_line, int errcode);
void			highlight_words(char *line, ssize_t c_beg,
								size_t w_beg, size_t w_end);
t_location		*gen_loc(t_location *loc, size_t char_beg,
						   size_t word_beg, size_t word_end);
void			unk_material_id(t_list *lines, signed long long id,
								t_location *loc);

/*
** Atoi-like stuff
*/
int				ft_strtoll_noendchk(const char *str, size_t *pos,
	signed long long int *nbr);
int				ft_strtoll(const char *str,
	size_t *pos, signed long long int *nbr);
int				ft_strtod(const char *str, size_t *pos, double *nbr);
int				ft_strtod_noendchk(const char *str, size_t *pos, double *nbr);
int				parse_endl(char *str, size_t *pos);
int				parse_p_long(char *str, size_t *pos, signed long long *p_int);
int				parse_p_int(char *str, size_t *pos, int *p_int);
int				parse_float_01(char *str, size_t *pos, double *d_01);
int				parse_rgb(char *str, size_t *pos, t_frgba *rgb);
int				parse_position(char *str, size_t *pos, t_position *position);
int				parse_rotation(char *str, size_t *pos, t_rotation *rotation);
int				parse_180_dbl(char *str, size_t *pos, double *dbl);
int				parse_float_0inf(char *str, size_t *pos, double *d_01);
int				parse_float_1inf(char *str, size_t *pos, double *d_1inf);
int				parse_float_0incinf(char *str, size_t *pos, double *d_01);
int				parse_angle(char *str, size_t *pos, double *dbl);
int				parse_f(char *str, size_t *pos, t_filter *filter);
int				parse_disruption(char *str, size_t *pos,
	t_disruption *disruption);

/*
** Linking
*/
void			link_spheres(t_list *lines, t_scene_parse *scene);
void			link_planes(t_list *lines, t_scene_parse *scene);
void			link_squares(t_list *lines, t_scene_parse *scene);
void			link_cylinders(t_list *lines, t_scene_parse *scene);
void			link_triangles(t_list *lines, t_scene_parse *scene);
void			link_cubes(t_list *lines, t_scene_parse *scene);
void			link_cones(t_list *lines, t_scene_parse *scene);
void			link_pyramids(t_list *lines, t_scene_parse *scene);

/*
** List to Array
*/
void			fill_all_funcs(t_list_scene *old, t_scene *new);
void			fill_funcs(t_objects *objs, void (*gf)(t_funcs *), size_t i);
size_t			copy_refs(t_array *arr, t_list *lst);
size_t			object_count(t_list_scene *scene);

#endif
