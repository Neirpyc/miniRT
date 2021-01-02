/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 18:44:24 by caugier           #+#    #+#             */
/*   Updated: 2021/01/01 15:40:46 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse_int.h"
#include "../../libft/libft.h"
#include "../../gc_malloc/gc_malloc.h"
#include <unistd.h>

static size_t	write_args(int argc, char **argv,
	size_t *arg_begin, int arg_end)
{
	int		i;
	size_t	largest_err;
	size_t	largest_space;
	size_t	len;

	i = 0;
	largest_space = 0;
	largest_err = 0;
	while (i < argc)
	{
		len = ft_strlen(argv[i]);
		if (i >= (int) * arg_begin && i <= arg_end)
		{
			if (len > largest_err)
				largest_err = len;
		}
		else if (len > largest_space)
			largest_space = len;
		write(STDOUT_FILENO, argv[i], len);
		write(STDOUT_FILENO, " ", (i == argc - 1 ? 0 : 1));
		i++;
	}
	write(STDOUT_FILENO, "\n", 1);
	*arg_begin = largest_err;
	return (largest_space);
}

static void	fill_bufs(size_t largest_space, size_t largest_err,
	char **buf_space, char **buf_err)
{
	*buf_space = gc_malloc(largest_space);
	*buf_err = gc_malloc(largest_err);
	if (largest_err > 0)
		**buf_err = '^';
	ft_memset(*buf_err + 1, '~', (largest_err > 1 ? largest_err - 1 : 0));
	ft_memset(*buf_space, ' ', largest_space);
}

void	err_arg(int argc, char **argv, int arg_begin, int arg_end)
{
	size_t	largest_space;
	size_t	largest_err;
	char	*buf_space;
	char	*buf_err;
	int		i;

	largest_err = arg_begin;
	largest_space = write_args(argc, argv, &largest_err, arg_end);
	fill_bufs(largest_space, largest_err, &buf_space, &buf_err);
	i = 0;
	while (i < argc)
	{
		if (i >= arg_begin && i <= arg_end)
		{
			write(STDOUT_FILENO, buf_err, ft_strlen(argv[i]));
			if (largest_err > 0)
				buf_err[0] = '~';
		}
		else
			write(STDOUT_FILENO, buf_space, ft_strlen(argv[i]));
		write(STDOUT_FILENO, " ", (i == argc - 1 ? 0 : 1));
		i++;
	}
	write(STDOUT_FILENO, "\n", 1);
	gc_exit(-1);
}
