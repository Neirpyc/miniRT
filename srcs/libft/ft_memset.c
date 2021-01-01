/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 18:46:10 by caugier           #+#    #+#             */
/*   Updated: 2020/12/06 18:51:44 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t d)
{
	if (d == 0)
		return (s);
	while (--d > 0)
		((unsigned char *)s)[d] = (unsigned char)c;
	((unsigned char *)s)[d] = (unsigned char)c;
	return (s);
}
