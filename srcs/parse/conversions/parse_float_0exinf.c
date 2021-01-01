/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_float_0exinf.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 15:29:59 by caugier           #+#    #+#             */
/*   Updated: 2020/12/21 15:29:59 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse_int.h"
#include "../../libft/libft.h"
#include <math.h>

int	parse_float_0exinf(char *str, size_t *pos, double *d_01)
{
	int	ret;

	while (ft_isspace(str[*pos]))
		(*pos)++;
	ret = ft_strtod(str, pos, d_01);
	if (ret != 0)
		return (ret);
	if (*d_01 > 0 && *d_01 < INFINITY)
		return (0);
	while (*pos != 0 && !ft_isspace(str[*pos]))
		(*pos)--;
	(*pos)++;
	return (ERRCODE_EXP_FP0INF);
}
