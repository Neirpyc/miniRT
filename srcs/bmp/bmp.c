/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 14:33:01 by caugier           #+#    #+#             */
/*   Updated: 2020/12/31 19:27:01 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bmp_int.h"
#include "../gc_malloc/gc_malloc.h"
#include "../errors/errors.h"
#include <unistd.h>
#include "../libft/libft.h"

static void	put_header(void *buf, size_t size)
{
	ft_memcpy(buf, "BM....MnRT....", HEADER_SIZE);
	*((int *)((char *)buf + 2)) = size;
	*((int *)((char *)buf + 10)) = HEADER_SIZE + DIB_HEADER_SIZE;
}

static void	put_dib(void *buf, int width, int height)
{
	unsigned int	dib[15];

	dib[0] = DIB_HEADER_SIZE;
	dib[1] = width;
	dib[2] = height;
	dib[3] = (32u << 16u) | 1u;
	dib[4] = 0;
	dib[5] = width * height * 4;
	dib[6] = DFLT_PPM;
	dib[7] = DFLT_PPM;
	dib[8] = 0;
	dib[9] = 0;
	dib[10] = 0x00FF0000;
	dib[11] = 0x0000FF00;
	dib[12] = 0x000000FF;
	dib[13] = 0xFF000000;
	ft_memcpy(buf, dib, DIB_HEADER_SIZE);
}

static void	put_bm(void *buf, int width, int height)
{
	void	*stop;
	void	*src;

	width *= 4;
	stop = ((char *)buf) + width * height;
	src = ((char *)g_image_buffer.address) + width * height;
	while (buf < stop)
	{
		src = ((char *)src) - width;
		ft_memcpy(buf, src, width);
		buf = ((char *)buf) + width;
	}
}

static size_t	generate_bmp(void **buf, int width, int height)
{
	size_t	size;

	size = HEADER_SIZE + DIB_HEADER_SIZE + width * height * 4;
	*buf = gc_malloc(size);
	put_header(*buf, size);
	put_dib(((char *)*buf) + HEADER_SIZE, width, height);
	put_bm(((char *)*buf) + HEADER_SIZE + DIB_HEADER_SIZE, width, height);
	return (size);
}

void	export_buffer_bmp(int width, int height)
{
	void	*bmp;
	ssize_t	size;
	int		fd;
	ssize_t	ret;

	size = (ssize_t)generate_bmp(&bmp, width, height);
	fd = open_img_file();
	ret = write(fd, bmp, size);
	if (ret < 0)
	{
		ft_put_strerrno();
		gc_exit(-1);
	}
	if (ret != size)
		gc_exit_strerror(ERRCODE_UNK_WRT_F, -1);
	gc_close(fd);
	gc_free(bmp);
}
