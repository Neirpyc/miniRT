/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 21:44:03 by caugier           #+#    #+#             */
/*   Updated: 2020/12/07 22:15:44 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse_int.h"
#include "../../libft/libft.h"

static int	parse_p_chanel(char *str, size_t *pos, double *c)
{
	signed long long	nbr;
	int					ret;

	ret = ft_strtoll_noendchk(str, pos, &nbr);
	if (ret != 0)
		return (ret);
	if (nbr >= 0 && nbr <= 255)
	{
		*c = (double)nbr / 255.;
		*c *= *c;
		return (0);
	}
	(*pos)--;
	while (*pos != 0 && !ft_isspace(str[*pos]) && str[*pos] != ',')
		(*pos)--;
	(*pos)++;
	return (ERRCODE_EXP_BYTE);
}

int	parse_rgb(char *str, size_t *pos, t_frgba *rgb)
{
	int	ret;

	while (ft_isspace(str[*pos]))
		(*pos)++;
	ret = parse_p_chanel(str, pos, &rgb->red);
	if (ret != 0)
		return (ret);
	if (str[*pos] != ',')
		return (ERRCODE_EXP_3BYTES);
	(*pos)++;
	ret = parse_p_chanel(str, pos, &rgb->green);
	if (ret != 0)
		return (ret);
	if (str[*pos] != ',')
		return (ERRCODE_EXP_3BYTES);
	(*pos)++;
	ret = parse_p_chanel(str, pos, &rgb->blue);
	if (ret != 0)
		return (ret);
	if (!ft_isspace(str[*pos]) && str[*pos] != '\0')
		return (ERRCODE_UNEX_CHR);
	return (0);
}
