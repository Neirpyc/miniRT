/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_disruption.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 12:02:25 by caugier           #+#    #+#             */
/*   Updated: 2020/12/31 18:25:36 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse_int.h"
#include "../../libft/libft.h"

int	parse_disruption(char *str, size_t *pos, t_disruption *disruption)
{
	while (ft_isspace(str[*pos]))
		(*pos)++;
	if (ft_toupper(str[*pos]) == 'N')
		*disruption = disruption_none;
	else if (ft_toupper(str[*pos]) == 'S')
		*disruption = disruption_sine;
	else if (ft_toupper(str[*pos]) == 'C')
		*disruption = disruption_check;
	else if (ft_toupper(str[*pos]) == 'R')
		*disruption = disruption_rainbow;
	else
		return (ERRCODE_EXP_NSCR);
	(*pos)++;
	if (str[*pos] == '\0')
		return (0);
	if (!ft_isspace(str[*pos]))
		return (ERRCODE_EXP_NSCR);
	return (0);
}
