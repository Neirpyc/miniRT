/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 22:11:46 by caugier           #+#    #+#             */
/*   Updated: 2020/12/31 17:52:02 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors_int.h"
#include "../libft/libft.h"
#include "../gc_malloc/gc_malloc.h"
#include <unistd.h>
#include <errno.h>
#include <string.h>

const char	*ft_strerror(int error)
{
	size_t				i;
	const char			*ptr;
	extern const char	_binary_assets_errors_bin_start[];

	if (error < 0)
		error = ERRCODE_UNKNOWN_ERROR;
	ptr = (const char *) & _binary_assets_errors_bin_start;
	i = 0;
	while (*ptr != 8)
	{
		if (i == (size_t)error)
			return (ptr);
		if (*(ptr++) == '\0')
			i++;
	}
	return (ft_strerror(ERRCODE_UNKNOWN_ERROR));
}

void	ft_put_strerror(int error)
{
	const char	*err;

	err = ft_strerror(error);
	write(STDOUT_FILENO, "Error\n", 6);
	write(STDERR_FILENO, err, ft_strlen(err));
	write(STDERR_FILENO, "\n", 1);
}

void	gc_exit_strerror(int error, int exit_code)
{
	ft_put_strerror(error);
	gc_exit(exit_code);
}

void	ft_put_strerrno(void)
{
	const char	*err;

	err = strerror(errno);
	write(STDOUT_FILENO, "Error\n", 6);
	write(STDERR_FILENO, err, ft_strlen(err));
	write(STDERR_FILENO, "\n", 1);
}
