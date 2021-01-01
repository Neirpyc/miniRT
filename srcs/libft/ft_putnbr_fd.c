/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 16:58:44 by caugier           #+#    #+#             */
/*   Updated: 2020/12/31 19:40:29 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static int	ft_my_mod(int a, int b)
{
	int	r;

	r = a % b;
	if (r < 0)
		return (10 - r - b);
	return (r);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	buf[11];
	int		i;
	int		sign;

	i = 10;
	if (n == 0)
		buf[i--] = '0';
	if (n < 0)
		sign = -1;
	else
		sign = 1;
	while (n != 0)
	{
		buf[i--] = (char)(ft_my_mod(n, 10) + '0');
		n /= 10;
	}
	if (sign == -1)
		buf[i--] = '-';
	write(fd, &buf[i + 1], 10 - i);
}
