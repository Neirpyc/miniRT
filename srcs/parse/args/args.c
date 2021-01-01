/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 18:07:19 by caugier           #+#    #+#             */
/*   Updated: 2020/12/31 18:45:41 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse_int.h"
#include "../../gc_malloc/gc_malloc.h"
#include "../../libft/libft.h"
#include <unistd.h>

static void	ft_write_usage(char **argv)
{
	write(STDOUT_FILENO, "Usage: ", 7);
	write(STDOUT_FILENO, argv[0], ft_strlen(argv[0]));
	write(STDOUT_FILENO, " filename.rt [--save]\n", 22);
}

static void	validate_path(int argc, char **argv)
{
	size_t	len;

	len = ft_strlen(argv[1]);
	if (len < 3)
	{
		ft_put_strerror(ERRCODE_NOT_RT);
		err_arg(argc, argv, 1, 1);
	}
	if (argv[1][len - 1] != 't' || argv[1][len - 2] != 'r'
		|| argv[1][len - 3] != '.')
	{
		ft_put_strerror(ERRCODE_NOT_RT);
		err_arg(argc, argv, 1, 1);
	}
}

static void	validate_save(int argc, char **argv)
{
	if (ft_strcmp("--save", argv[2]) != 0)
	{
		ft_put_strerror(ERRCODE_UNEX_ARG);
		err_arg(argc, argv, 2, argc);
	}
}

void	parse_args(int argc, char **argv, t_input *inp)
{
	if (argc == 1)
	{
		ft_put_strerror(ERRCODE_NOT_ENOUGH_ARGS);
		ft_write_usage(argv);
		gc_exit(-1);
	}
	if (argc >= 4)
	{
		if (argc == 4)
			ft_put_strerror(ERRCODE_UNEX_ARG);
		else
			ft_put_strerror(ERRCODE_UNEX_ARGS);
		ft_write_usage(argv);
		err_arg(argc, argv, 3, argc);
	}
	if (argc == 3)
		validate_save(argc, argv);
	validate_path(argc, argv);
	inp->rt_file = argv[1];
	inp->save = 1;
	if (argc == 2)
		inp->save = 0;
}
