/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rotation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 12:17:53 by caugier           #+#    #+#             */
/*   Updated: 2020/12/31 18:16:27 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse_int.h"
#include "../../libft/libft.h"
#include "../../raytrace/raytrace_int.h"

static int	parse_n_dbl(char *str, size_t *pos, double *dbl)
{
	int	ret;

	ret = ft_strtod_noendchk(str, pos, dbl);
	if (ret != 0)
		return (ret);
	if (*dbl >= -1 && *dbl <= 1)
		return (0);
	while (*pos != 0 && !ft_isspace(str[*pos]) && str[*pos] != ',')
		(*pos)--;
	(*pos)--;
	return (ERRCODE_EXP_DBL_11);
}

static int	parse_rot_norm(t_rotation *rotation, size_t *pos)
{
	if (norm_vec3(*rotation) == 0)
	{
		*pos = -1;
		return (ERRCODE_VEC_NNORM);
	}
	normalize_vec3(rotation);
	return (0);
}

int	parse_rotation(char *str, size_t *pos, t_rotation *rotation)
{
	int	ret;

	while (ft_isspace(str[*pos]))
		(*pos)++;
	ret = parse_n_dbl(str, pos, &rotation->x);
	if (ret != 0)
		return (ret);
	if (str[*pos] != ',')
		return (ERRCODE_EXP_3DBL_11);
	(*pos)++;
	ret = parse_n_dbl(str, pos, &rotation->y);
	if (ret != 0)
		return (ret);
	if (str[*pos] != ',')
		return (ERRCODE_EXP_3DBL_11);
	(*pos)++;
	ret = parse_n_dbl(str, pos, &rotation->z);
	if (ret != 0)
		return (ret);
	if (!ft_isspace(str[*pos]) && str[*pos] != '\0')
		return (ERRCODE_EXP_3DBL_11);
	return (parse_rot_norm(rotation, pos));
}
