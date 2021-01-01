/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 11:40:21 by caugier           #+#    #+#             */
/*   Updated: 2020/12/29 11:43:46 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"

void	parse_filter(t_list *lines, size_t line_nb,
	size_t *pos, t_scene_parse *scene)
{
	int			ret;
	t_location	loc;
	char		*line;

	if (scene->filter_line != -1)
		err_dup_line(lines, scene->resolution_line, line_nb, ERRCODE_FI_RE);
	line = ((char *)lines->content);
	loc.line = line_nb;
	ret = parse_f(line, pos, &scene->scene->filter);
	err_line(line, gen_loc(&loc, *pos, 1, 1), ret);
	ret = parse_endl(line, pos);
	err_line(line, gen_loc(&loc, *pos, 2, 2), ret);
	scene->filter_line = line_nb;
}
