/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 12:27:38 by irhett            #+#    #+#             */
/*   Updated: 2018/01/13 16:58:55 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "othello.h"

t_movelist		*get_all_moves(t_turn *t, unsigned char boardsize)
{
	t_movelist		*list;
	unsigned char	row;
	unsigned char	col;
	unsigned int	id;
	unsigned int	flip;

	list = NULL;
	id = 0;
	row = 0;
	while (row < boardsize)
	{
		col = 0;
		while (col < boardsize)
		{
			if ((flip = is_valid_move(turn, boardsize, row, col)))
				list = movelist_add(list, make_move(g, row, col, id++, flip));
			col++;
		}
		row++;
	}
	return (list);
}

t_movelist		*simplify_moves(t_turn *t, t_movelist *old, unsigned char size)
{
	t_movelist		*list;
	t_movelist		*curr;
	t_movelist		*temp;
	unsigned int	id_offset;
	unsigned char	board_dupes;

	list = old;
	curr = old;
	id_offset = NULL;
	board_dupes = get_duplicates(t, size)
	// TODO
	(void)old;
	(void)g;
	return (list);
}
