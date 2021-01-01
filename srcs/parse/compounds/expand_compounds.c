/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_compounds.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 21:34:00 by caugier           #+#    #+#             */
/*   Updated: 2020/12/31 18:28:42 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse_int.h"

void	expand_compounds(t_list_scene *scene)
{
	expand_cubes(scene, scene->cubes);
	expand_pyramids(scene, scene->pyramids);
	expand_cylinders(scene, scene->cylinders);
	expand_cones(scene, scene->cones);
	list_clear(scene->pyramids.list);
	list_clear(scene->cubes.list);
}
