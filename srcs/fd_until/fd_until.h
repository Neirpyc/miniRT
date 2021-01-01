/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_until.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 15:51:28 by caugier           #+#    #+#             */
/*   Updated: 2020/12/05 15:54:22 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FD_UNTIL_H
# define FD_UNTIL_H

# include <sys/types.h>

ssize_t	fd_read_until(int fd, char **bin, int sep);
void	fd_close_until(int fd);

#endif
