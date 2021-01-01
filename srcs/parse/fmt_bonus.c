/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 11:57:52 by caugier           #+#    #+#             */
/*   Updated: 2020/12/31 18:48:27 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_int.h"
#include "../libft/libft.h"
#include "../gc_malloc/gc_malloc.h"

unsigned int	is_bonus(t_list *lines, size_t *pos)
{
	size_t	len;
	char	*line;

	line = ((char *)lines->content);
	len = ft_strlen(line);
	if (len >= 6)
	{
		if (ft_memcmp(line, "#BONUS", 6) == 0)
		{
			*pos = 6;
			if (parse_endl(line, pos) == 0)
				return (FORMAT_BONUS);
		}
	}
	return (FORMAT_DEFAULT);
}

static signed long long	find_dup(t_int_material_list *list,
	t_int_line_list *id_list, signed long long id)
{
	if (list == NULL)
		return (0);
	if (id == list->content->id)
		return ((long long)id_list->nbr);
	return (find_dup(list->next, id_list->next, id));
}

t_material	*new_material(void)
{
	t_material	*mat;

	mat = gc_malloc(sizeof(t_material));
	mat->refraction_indice = DFLT_REF_I;
	mat->spec_k = DFLT_SPEC;
	mat->disruption = disruption_none;
	return (mat);
}

void	chk_duplicate_mat_id(t_list *lines, t_scene_parse *scene)
{
	t_material_list		list;
	t_id_line_list		id_list;
	signed long long	ret;

	list.list = scene->scene->materials.list;
	id_list.list = scene->materials_lines.list;
	if (list.list != NULL)
	{
		while (list.list->next != NULL)
		{
			ret = find_dup(list.materials->next,
					id_list.id_line_list->next, list.materials->content->id);
			if (ret > 0)
				err_dup_line(lines, (size_t)ret,
					id_list.id_line_list->nbr, ERRCODE_DUP_MATID);
			list.list = list.list->next;
			id_list.list = id_list.list->next;
		}
	}
}
