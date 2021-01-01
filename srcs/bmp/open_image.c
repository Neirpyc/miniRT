/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 15:18:15 by caugier           #+#    #+#             */
/*   Updated: 2020/12/31 19:27:21 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bmp_int.h"
#include <unistd.h>
#include "../gc_malloc/gc_malloc.h"
#include "../errors/errors.h"
#include <fcntl.h>
#include <errno.h>

#define DFLT_PATH "frame.bmp"

static int	confirm(void)
{
	char	buf[2];
	int		res;

	write(STDOUT_FILENO,
		"File 'frame.bmp' already exists, overwrite? [y/N]: ", 51);
	res = read(STDIN_FILENO, &buf, 2);
	if (res < 0)
	{
		ft_put_strerrno();
		gc_exit(-1);
	}
	else if (res != 2)
		gc_exit(0);
	if ((buf[0] == 'y' || buf[0] == 'Y') && buf[1] == '\n')
		return (gc_open(DFLT_PATH, O_WRONLY));
	gc_exit(0);
}

int	open_img_file(void)
{
	int	fd;

	errno = 0;
	fd = open(DFLT_PATH, O_CREAT | O_EXCL | O_WRONLY, 0740);
	if (errno == 0)
	{
		close(fd);
		return (gc_open(DFLT_PATH, O_WRONLY));
	}
	if (errno == EEXIST)
		return (confirm());
	ft_put_strerrno();
	gc_exit(-1);
}
