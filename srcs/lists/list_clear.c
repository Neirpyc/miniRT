/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 22:36:12 by caugier           #+#    #+#             */
/*   Updated: 2020/12/06 22:36:12 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gc_malloc/gc_malloc.h"
#include "lists.h"

void	list_free(t_list *list)
{
	if (list == NULL)
		return ;
	list_free(list->next);
	gc_free(list);
}

void	list_clear(t_list *list)
{
	if (list == NULL)
		return ;
	gc_free(list->content);
	list_clear(list->next);
	gc_free(list);
}
