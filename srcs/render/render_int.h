/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_int.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 14:21:16 by caugier           #+#    #+#             */
/*   Updated: 2021/01/02 15:52:20 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_INT_H
# define RENDER_INT_H

# include <pthread.h>
# include <stdatomic.h>
# include "render.h"
# define MODE_CAM 0
# define MODE_OBJ 1

# ifndef MOVE_STEP
#  define MOVE_STEP 0.2f
# endif

# ifndef ROTATE_STEP
#  define ROTATE_STEP 0.05f
# endif

# ifndef CHUNK_PX
#  define CHUNK_PX 64
# endif

extern pthread_t		*g_threads;
pthread_barrier_t		g_render_start_barrier;
pthread_barrier_t		g_render_stop_barrier;
extern atomic_long		g_current_point;
extern t_camera			*g_camera;

void	move(t_render *rd, t_vec3 translation, t_vec3 rotation);

#endif
