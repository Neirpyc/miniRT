/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 17:20:44 by caugier           #+#    #+#             */
/*   Updated: 2020/12/06 21:08:32 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

size_t	ft_strlen(const char *str);
void	*ft_memset(void *s, int c, size_t d);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_isspace(int c);
int		ft_isdigit(int c);
void	ft_putnbr_fd(int n, int fd);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int		ft_toupper(int c);

#endif
