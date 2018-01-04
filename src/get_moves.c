/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 12:27:38 by irhett            #+#    #+#             */
/*   Updated: 2018/01/03 20:07:10 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "othello.h"

t_movelist		*get_all_moves(t_game *g)
{
	t_movelist		*list;
	unsigned char	row;
	unsigned char	col;
	unsigned int	id;
	unsigned int	flip;

	list = NULL;
	id = 0;
	row = 0;
	while (row < g->boardsize)
	{
		col = 0;
		while (col < g->boardsize)
		{
			if ((flip = is_valid_move(g, row, col)))
				list = movelist_add(list, make_move(g, row, col, id++, flip));
			col++;
		}
		row++;
	}
	return (list);
}

t_movelist		*simplify_moves(t_movelist *old, t_game *g)
{
	t_movelist	*list;

	list = NULL;
	(void)old;
	(void)g;
	return (list);
}
