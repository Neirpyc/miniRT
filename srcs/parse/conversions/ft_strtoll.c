/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 20:18:57 by caugier           #+#    #+#             */
/*   Updated: 2020/12/31 18:18:04 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse_int.h"
#include "../../libft/libft.h"

int	ft_strtoll_noendchk(const char *str, size_t *pos, signed long long int *nbr)
{
	int	sign;
	int	i;

	sign = SIGN_PLUS;
	if (str[*pos] == '-')
		sign = SIGN_MINUS;
	if (str[*pos] == '+' || sign == SIGN_MINUS)
		(*pos)++;
	*nbr = 0;
	i = 0;
	while (ft_isdigit(str[*pos]))
	{
		*nbr = *nbr * 10 + sign * (str[(*pos)++] - '0');
		i++;
	}
	if (str[*pos] == '\0' && i == 0)
		return (ERRCODE_EXP_ARG);
	if (i > 0)
		return (0);
	return (ERRCODE_EXP_DIG);
}

int	ft_strtoll(const char *str, size_t *pos, signed long long int *nbr)
{
	int	ret;

	ret = ft_strtoll_noendchk(str, pos, nbr);
	if (ret != 0)
		return (ret);
	if (!ft_isspace(str[*pos]) && str[*pos] != '\0')
		return (ERRCODE_UNEX_CHR);
	return (0);
}
