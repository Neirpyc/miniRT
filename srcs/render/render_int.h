/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_int.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 14:21:16 by caugier           #+#    #+#             */
/*   Updated: 2020/12/31 14:49:01 by caugier          ###   ########.fr       */
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

extern pthread_t		*g_threads;
extern pthread_cond_t	g_start_render_cond;
extern pthread_cond_t	g_render_done_cond;
extern pthread_mutex_t	g_start_render_mutex;
extern pthread_mutex_t	g_render_done_mutex;
extern atomic_int		g_asleep_threads;
extern atomic_long		g_current_point;
extern t_camera			*g_camera;
extern int				g_thread_count;

void	move(t_render *rd, t_vec3 translation, t_vec3 rotation);

#endif
