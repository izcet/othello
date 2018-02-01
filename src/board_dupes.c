/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_dupes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 15:56:18 by irhett            #+#    #+#             */
/*   Updated: 2018/01/31 18:34:42 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "othello.h"

static unsigned char	is_dupe_board(t_turn *t, char y_out, char y, char x)
{
	unsigned int	r;
	unsigned int	c;
	unsigned int	yr = 0;
	unsigned int	xc = 0;
	if (y_out)
		yr = y ? 0 : g_boardsize - 1; 
	else
		xc = x ? 0 : g_boardsize - 1;
	r = 0;
	while (r < g_boardsize)
	{
		if (y_out)
			xc = x ? 0 : g_boardsize - 1;
		else
			yr = y ? 0 : g_boardsize - 1;
		c = 0;
		while (c < g_boardsize)
		{
			if (t->board[r][c] != t->board[yr][xc])
				return (0);
			if (y_out)
				xc += x - 1;
			else
				yr += y - 1;
			c++;
		}
		if (y_out)
			yr += y - 1;
		else
			xc += x - 1;
		r++;
	}
	return (1);
}

unsigned char			get_duplicates(t_turn *t)
{
	unsigned char	duplicates;

	duplicates = 0;
	duplicates += (is_dupe_board(t, 0, 0, 0) << 0);
	duplicates += (is_dupe_board(t, 0, 0, 2) << 1);
	duplicates += (is_dupe_board(t, 0, 2, 0) << 2);
	duplicates += (is_dupe_board(t, 0, 2, 2) << 3);
	duplicates += (is_dupe_board(t, 2, 0, 0) << 4);
	duplicates += (is_dupe_board(t, 2, 0, 2) << 5);
	duplicates += (is_dupe_board(t, 2, 2, 0) << 6);
	return (duplicates);
}
