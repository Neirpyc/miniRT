/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filters_int.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 11:29:00 by caugier           #+#    #+#             */
/*   Updated: 2020/12/29 11:29:18 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILTERS_INT_H
# define FILTERS_INT_H

# include "filters.h"

void	f_filter_red(t_rgba *color);
void	f_filter_green(t_rgba *color);
void	f_filter_blue(t_rgba *color);

#endif
