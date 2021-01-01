/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_position.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 12:10:31 by caugier           #+#    #+#             */
/*   Updated: 2020/12/08 12:16:39 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse_int.h"
#include "../../libft/libft.h"
#include <math.h>

static int	parse_n_dbl(char *str, size_t *pos, double *dbl)
{
	int	ret;

	ret = ft_strtod_noendchk(str, pos, dbl);
	if (ret != 0)
		return (ret);
	if (*dbl > -INFINITY && *dbl < INFINITY)
		return (0);
	while (*pos != 0 && !ft_isspace(str[*pos]) && str[*pos] != ',')
		(*pos)--;
	(*pos)++;
	return (ERRCODE_EXP_DBL_NP);
}

int	parse_position(char *str, size_t *pos, t_position *position)
{
	int	ret;

	while (ft_isspace(str[*pos]))
		(*pos)++;
	ret = parse_n_dbl(str, pos, &position->x);
	if (ret != 0)
		return (ret);
	if (str[*pos] != ',')
		return (ERRCODE_EXP_3DBL_NP);
	(*pos)++;
	ret = parse_n_dbl(str, pos, &position->y);
	if (ret != 0)
		return (ret);
	if (str[*pos] != ',')
		return (ERRCODE_EXP_3DBL_NP);
	(*pos)++;
	ret = parse_n_dbl(str, pos, &position->z);
	if (ret != 0)
		return (ret);
	if (!ft_isspace(str[*pos]) && str[*pos] != '\0')
		return (ERRCODE_EXP_3DBL_NP);
	return (0);
}
