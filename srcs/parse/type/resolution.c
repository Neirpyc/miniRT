/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 18:20:01 by caugier           #+#    #+#             */
/*   Updated: 2020/12/09 17:08:13 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"

void	parse_resolution(t_list *lines, size_t line_nb,
	size_t *pos, t_scene_parse *scene)
{
	int			ret;
	t_location	loc;
	char		*line;

	if (scene->resolution_line != -1)
		err_dup_line(lines, scene->resolution_line, line_nb, ERRCODE_RES_RE);
	line = ((char *)lines->content);
	loc.line = line_nb;
	ret = parse_p_int(line, pos, &scene->scene->resolution.width);
	err_line(line, gen_loc(&loc, *pos, 1, 1), ret);
	ret = parse_p_int(line, pos, &scene->scene->resolution.height);
	err_line(line, gen_loc(&loc, *pos, 2, 2), ret);
	ret = parse_endl(line, pos);
	err_line(line, gen_loc(&loc, *pos, 3, 3), ret);
	scene->resolution_line = line_nb;
}
