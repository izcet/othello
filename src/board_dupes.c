/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_dupes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 15:56:18 by irhett            #+#    #+#             */
/*   Updated: 2018/01/13 16:30:34 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "othello.h"

static unsigned char	is_dupe_board(t_turn *t, unsigned char y_out,
						unsigned char y, unsigned char x, unsigned char size)
{
	unsigned int	r;
	unsigned int	c;
	unsigned int	yr;
	unsigned int	xc;

	if (y_out)
		yr = y ? size - 1 : 0; 
	else
		xc = x ? size - 1 : 0;
	r = 0;
	while (r < size)
	{
		if (y_out)
			xc = x ? size - 1 : 0;
		else
			yr = y ? size - 1 : 0;
		c = 0;
		while (c < size)
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

unsigned char			get_duplicates(t_turn *t, unsigned char size)
{
	unsigned char	duplicates;
	unsigned char	curr;
	unsigned char	y_out;
	unsigned char	y;
	unsigned char	x;

	duplicates = 0;
	curr = 0;
	y_out = 0;
	while (y_out <= 2)
	{
		y = 0;
		while (y <= 2)
		{
			x = 0;
			while (x <= 2)
			{
				if (y_out + y + x != 6)
					duplicates += is_dupe_board(t, y_out, y, x, size) << curr;
				curr++;
				x += 2;
			}
			y += 2;
		}
		y_out += 2;
	}
	return (duplicates);
}
