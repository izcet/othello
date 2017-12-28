/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_move.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 16:09:41 by irhett            #+#    #+#             */
/*   Updated: 2017/12/27 16:09:41 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "othello.h"

void		del_move(t_move *m)
{
	if (m)
	{
		/* delete data */
		free(m);
	}
}

t_move	*new_move(void /* args */)
{
	t_move	*m;

	m = (t_move *)malloc(sizeof(t_move));
	if (!m)
		return (NULL);
	/* args */
	return (m);
}
