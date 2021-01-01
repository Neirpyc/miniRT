/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_float_1inf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 11:23:07 by caugier           #+#    #+#             */
/*   Updated: 2020/12/12 11:24:05 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse_int.h"
#include "../../libft/libft.h"
#include <math.h>

int	parse_float_1inf(char *str, size_t *pos, double *d_1inf)
{
	int	ret;

	while (ft_isspace(str[*pos]))
		(*pos)++;
	ret = ft_strtod(str, pos, d_1inf);
	if (ret != 0)
		return (ret);
	if (*d_1inf >= 1 && *d_1inf <= INFINITY)
		return (0);
	while (*pos != 0 && !ft_isspace(str[*pos]))
		(*pos)--;
	(*pos)++;
	return (ERRCODE_EXP_DBL_1INF);
}
