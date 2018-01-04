/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 18:27:45 by irhett            #+#    #+#             */
/*   Updated: 2018/01/03 19:07:05 by irhett           ###   ########.fr       */
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

void	make_move(t_game *g)
{
	t_turn			*old;
	t_turn			*new;
	unsigned int	flipped;

	if (g->turn_number + 1 >= g->num_turns)
		extend_game(g);
	old = g->turns[turn_number];
	g->turn_number++;
	new = g->turns[turn_number];
	copy_board(old, new, g->boardsize);
	if (old->move)
	{
		place_tile(new, old->move->data, g);
		flipped = old->move->data->flipped;
		if (old->active->value = 1)
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
}
