/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_p_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 21:41:10 by caugier           #+#    #+#             */
/*   Updated: 2020/12/18 20:01:54 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse_int.h"
#include "../../libft/libft.h"

int	parse_p_long(char *str, size_t *pos, signed long long *p_int)
{
	int	ret;

	while (ft_isspace(str[*pos]))
		(*pos)++;
	ret = ft_strtoll(str, pos, p_int);
	if (ret != 0)
		return (ret);
	if (*p_int > 0)
		return (0);
	while (*pos != 0 && !ft_isspace(str[*pos]))
		(*pos)--;
	(*pos)++;
	return (ERRCODE_EXP_PINT);
}

int	parse_p_int(char *str, size_t *pos, int *p_int)
{
	int					ret;
	signed long long	nbr;

	ret = parse_p_long(str, pos, &nbr);
	if (ret != 0)
		return (ret);
	*p_int = (int)nbr;
	if ((signed long long)*p_int != nbr)
		gc_exit_strerror(ERRCODE_SINT_OVFL, -1);
	return (0);
}
