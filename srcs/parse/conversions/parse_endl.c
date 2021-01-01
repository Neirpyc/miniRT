/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_endl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 20:43:03 by caugier           #+#    #+#             */
/*   Updated: 2020/12/07 20:43:03 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse_int.h"
#include "../../libft/libft.h"

int	parse_endl(char *str, size_t *pos)
{
	while (ft_isspace(str[*pos]))
		(*pos)++;
	if (str[*pos] == '\0')
		return (0);
	return (ERRCODE_EXP_EOL);
}
