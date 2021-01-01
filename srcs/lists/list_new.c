/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 22:30:09 by caugier           #+#    #+#             */
/*   Updated: 2020/12/23 17:15:37 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"
#include "../gc_malloc/gc_malloc.h"

t_list	*list_new(void *content)
{
	t_list	*ret;

	ret = gc_malloc(sizeof(t_list));
	ret->next = NULL;
	ret->content = content;
	return (ret);
}
