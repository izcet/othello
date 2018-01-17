/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_turn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 18:27:45 by irhett            #+#    #+#             */
/*   Updated: 2018/01/17 13:40:08 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "othello.h"

void	copy_board(t_turn *src, t_turn *dst, unsigned char boardsize)
{
	unsigned char	r;
	unsigned char	c;

	r = 0;
	while (r < boardsize)
	{
		c = 0;
		while (c < boardsize)
		{
			if (src->board[r][c] < 3)
				dst->board[r][c] = src->board[r][c];
			else
				dst->board[r][c] = 0;
			c++;
		}
		r++;
	}
	dst->num_black = src->num_black;
	dst->num_white = src->num_white;
	dst->num_empty = src->num_empty;
}

void	take_turn(t_turn *old, t_turn *new, unsigned char size)
{
	unsigned int	flipped;
	t_move			*m;

	copy_board(old, new, size);
	if (old->move)
	{
		m = old->move->data;
		place_tile(new, m, size);
		flipped = m->flipped;
		if (old->active->value == 1)
		{
			new->num_black += flipped + 1;
			new->num_white -= flipped;
		}
		else
		{
			new->num_white += flipped + 1;
			new->num_black -= flipped;
		}
		new->num_empty--;
	}
	new->move = get_all_moves(new, size);
	if (new->move)
		new->move = simplify_moves(new, new->move, size);
	new->done = 0;
}
