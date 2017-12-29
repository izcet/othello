/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_movelist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 23:43:30 by irhett            #+#    #+#             */
/*   Updated: 2017/12/28 21:15:59 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "othello.h"

/*
 * WARNING: Only deletes a single node
 */

void		del_movelist(t_movelist *m)
{
	if (m)
	{
		del_move(m->data);
		free(m);
	}
}

t_movelist	*new_movelist(t_move *data)
{
	t_movelist	*m;

	m = (t_movelist *)malloc(sizeof(t_movelist));
	if (!m)
		return (NULL);
	m->data = data;
	m->next = NULL;
	return (m);
}

t_movelist	*movelist_add(t_movelist *list, t_move *data)
{
	t_movelist	*temp;

	if (!list)
		return (new_movelist(data));
	temp = list;
	while (temp->next)
		temp = temp->next;
	temp->next = new_movelist(data);
	return (list);
}

t_move		*movelist_pop(t_movelist **head)
{
	t_move		*ret;
	t_movelist	*temp;

	if (head && *head)
	{
		temp = *head;
		*head = (*head)->next;
		ret = temp->data;
		free(temp);
		return (ret);
	}
	return (game_error(NULL, "movelist_pop NULL parameter"));
}
