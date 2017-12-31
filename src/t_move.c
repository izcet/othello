/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_move.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 16:09:41 by irhett            #+#    #+#             */
/*   Updated: 2017/12/30 17:35:58 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "othello.h"

void		del_move(t_move *m)
{
	if (m)
		free(m);
}

t_move	*new_move(unsigned char x, unsigned char y, unsigned int id, 
					unsigned int flipped, t_player *active)
{
	t_move	*m;

	m = (t_move *)malloc(sizeof(t_move));
	if (!m)
		return (NULL);
	m->x = x;
	m->y = y;
	m->multiplier = 1;
	m->id = id;
	m->flipped = flipped;
	m->player = active;
	return (m);
}
