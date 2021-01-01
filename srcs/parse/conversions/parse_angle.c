/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_angle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 21:22:25 by caugier           #+#    #+#             */
/*   Updated: 2020/12/31 18:15:30 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse_int.h"
#include "../../libft/libft.h"

int	parse_angle(char *str, size_t *pos, double *dbl)
{
	int	ret;

	while (ft_isspace(str[*pos]))
		(*pos)++;
	ret = ft_strtod(str, pos, dbl);
	if (ret != 0)
		return (ret);
	if (*dbl > 0 && *dbl < 180)
		return (0);
	while (*pos != 0 && !ft_isspace(str[*pos]))
		(*pos)--;
	(*pos)++;
	return (ERRCODE_EXP_DBL_0180EX);
}
