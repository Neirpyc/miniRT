/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 18:07:38 by caugier           #+#    #+#             */
/*   Updated: 2020/12/31 18:48:00 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "../scene/scene_parse.h"

# ifndef DFLT_REF_I
#  define DFLT_REF_I 1.4
# endif

# ifndef DFLT_SPEC
#  define DFLT_SPEC 0
# endif

typedef struct s_input {
	char			*rt_file;
	unsigned short	save;
}					t_input;

t_scene				*parse(int argc, char **argv);
t_scene				*scene_list_to_scene(t_list_scene *old);
void				parse_args(int argc, char **argv, t_input *inp);

#endif
