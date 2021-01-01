/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filters.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 11:29:38 by caugier           #+#    #+#             */
/*   Updated: 2020/12/29 11:29:38 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILTERS_H
# define FILTERS_H

# include "../../scene/scene.h"

void	apply_filters(t_rgba *color, t_filter filter);

#endif
