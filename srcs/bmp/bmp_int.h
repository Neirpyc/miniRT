/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_int.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 14:37:20 by caugier           #+#    #+#             */
/*   Updated: 2020/12/18 17:25:23 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BMP_INT_H
# define BMP_INT_H

# include "bmp.h"

# define HEADER_SIZE 14
# define DIB_HEADER_SIZE 56

# ifndef DFLT_PPM
#  define DFLT_PPM 3800
# endif

int	open_img_file(void);

#endif
