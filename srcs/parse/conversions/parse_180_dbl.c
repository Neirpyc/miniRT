/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_180_dbl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 12:20:24 by caugier           #+#    #+#             */
/*   Updated: 2020/12/08 12:25:13 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse_int.h"
#include "../../libft/libft.h"

int	parse_180_dbl(char *str, size_t *pos, double *dbl)
{
	int	ret;

	while (ft_isspace(str[*pos]))
		(*pos)++;
	ret = ft_strtod(str, pos, dbl);
	if (ret != 0)
		return (ret);
	if (*dbl >= 0 && *dbl <= 180)
		return (0);
	while (*pos != 0 && !ft_isspace(str[*pos]))
		(*pos)--;
	(*pos)++;
	return (ERRCODE_EXP_DBL_180);
}
