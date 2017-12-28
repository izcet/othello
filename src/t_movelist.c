/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_movelist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 23:43:30 by irhett            #+#    #+#             */
/*   Updated: 2017/12/27 23:43:30 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "othello.h"

void		del_movelist(t_movelist *m)
{
	if (m)
	{
		/* delete data */
		free(m);
	}
}

t_movelist	*new_movelist(void /* args */)
{
	t_movelist	*m;

	m = (t_movelist *)malloc(sizeof(t_movelist));
	if (!m)
		return (NULL);
	/* args */
	return (m);
}
