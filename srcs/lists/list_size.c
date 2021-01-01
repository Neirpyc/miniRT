/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 17:01:51 by caugier           #+#    #+#             */
/*   Updated: 2020/12/07 17:01:51 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"

size_t	list_size(t_list *list)
{
	if (list == NULL)
		return (0);
	return (list_size(list->next) + 1);
}
