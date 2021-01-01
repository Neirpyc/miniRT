/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_filter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 11:42:26 by caugier           #+#    #+#             */
/*   Updated: 2020/12/29 11:54:03 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse_int.h"
#include "../../libft/libft.h"

int	parse_f(char *str, size_t *pos, t_filter *filter)
{
	while (ft_isspace(str[*pos]))
		(*pos)++;
	if (ft_toupper(str[*pos]) == 'R')
		*filter = filter_red;
	else if (ft_toupper(str[*pos]) == 'G')
		*filter = filter_green;
	else if (ft_toupper(str[*pos]) == 'B')
		*filter = filter_blue;
	else
		return (ERRCODE_EXP_RGB);
	(*pos)++;
	if (str[*pos] == '\0')
		return (0);
	if (!ft_isspace(str[*pos]))
		return (ERRCODE_EXP_RGB);
	return (0);
}
