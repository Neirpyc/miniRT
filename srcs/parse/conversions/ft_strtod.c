/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 20:17:43 by caugier           #+#    #+#             */
/*   Updated: 2020/12/31 18:23:47 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse_int.h"
#include "../../libft/libft.h"

static int	ft_parsedot(const char *str, size_t *pos, double *nbr, int sign)
{
	int	j;
	int	tmp;

	j = 0;
	if (str[*pos] == '.')
	{
		(*pos)++;
		while (ft_isdigit(str[*pos]))
		{
			*nbr = *nbr * 10 + sign * (str[(*pos)++] - '0');
			j++;
		}
		tmp = j;
		if (tmp != 0)
			while (tmp-- > 0)
				*nbr /= 10;
	}
	return (j);
}

int	ft_strtod_noendchk(const char *str, size_t *pos, double *nbr)
{
	int	sign;
	int	i;

	while (ft_isspace(str[*pos]))
		(*pos)++;
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
	i += ft_parsedot(str, pos, nbr, sign);
	if (str[*pos] == '\0' && i == 0)
		return (ERRCODE_EXP_ARG);
	if (i > 0)
		return (0);
	return (ERRCODE_EXP_DIG);
}

int	ft_strtod(const char *str, size_t *pos, double *nbr)
{
	int	ret;

	ret = ft_strtod_noendchk(str, pos, nbr);
	if (ret != 0)
		return (ret);
	if (!ft_isspace(str[*pos]) && str[*pos] != '\0')
		return (ERRCODE_UNEX_CHR);
	return (0);
}
