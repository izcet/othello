/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_move.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 16:09:41 by irhett            #+#    #+#             */
/*   Updated: 2018/01/15 17:31:56 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "othello.h"

void		del_move(t_move *m)
{
	if (m)
		free(m);
}

t_move	*new_move(unsigned char row, unsigned char col, unsigned int id, 
					unsigned int flipped, t_player *active)
{
	t_move	*m;

	m = (t_move *)malloc(sizeof(t_move));
	if (!m)
		return (NULL);
	m->row = row;
	m->col = col;
	m->multiplier = 1;
	m->id = id;
	m->flipped = flipped;
	m->player = active;
	return (m);
}
