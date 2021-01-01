/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_scene.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 23:01:07 by caugier           #+#    #+#             */
/*   Updated: 2020/12/08 19:03:45 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_int.h"
#include "../gc_malloc/gc_malloc.h"

void	validate_scene(t_list *lines, t_scene_parse *scene)
{
	int	errcode;

	errcode = 0;
	if (scene->resolution_line == -1)
		errcode = ERRCODE_NO_RES;
	if (scene->ambient_line == -1)
		errcode = ERRCODE_NO_AMB;
	if (scene->scene->cameras.list == NULL)
		errcode = ERRCODE_NO_CAM;
	if (scene->version == FORMAT_BONUS)
	{
		chk_duplicate_mat_id(lines, scene);
		link_mat(lines, scene);
	}
	if (errcode == 0)
		return ;
	ft_put_strerror(errcode);
	gc_exit(-1);
}
